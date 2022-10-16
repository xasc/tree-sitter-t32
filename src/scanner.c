/*
 * Copyright (c) 2022 Christoph Sax
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "tree_sitter/parser.h"


enum TokenType {
	LABEL_IDENTIFIER,
	NO_BLANK,
	AND_OPERATOR_PRE_HOOK,
	LOGICAL_AND,
	BITWISE_AND
};

typedef struct scannerState_s {
	unsigned and_operator_len;
}
scannerState_t;


static void Skip(
	TSLexer *const lexer)
{
	assert(lexer != NULL);
	lexer->advance(lexer, true);
}


static void Advance(
	TSLexer *const lexer)
{
	assert(lexer != NULL);
	lexer->advance(lexer, false);
}


static void MarkEnd(
	TSLexer *const lexer)
{
	assert(lexer != NULL);
	lexer->mark_end(lexer);
}


static bool IsEof(
	TSLexer *const lexer)
{
	assert(lexer != NULL);
	return lexer->eof(lexer);
}


unsigned tree_sitter_t32_external_scanner_serialize(
	void * payload,
	char * buffer)
{
	assert(payload != NULL && buffer != NULL);

	scannerState_t *const s = (scannerState_t *) payload;

	size_t const num = sizeof(s[0]);
	_Static_assert(sizeof(s[0]) <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE, "Buffer too small");

	memcpy(buffer, s, num);
	return num;
}


void tree_sitter_t32_external_scanner_deserialize(
	void * payload,
	const char * buffer,
	unsigned length)
{
	assert(payload != NULL && (buffer != NULL || length <= 0));
	if (length <= 0) {
		return;
	};

	scannerState_t *const s = (scannerState_t *) payload;
	memcpy(s, buffer, length);
}


static bool IsAlpha(
	int32_t const glyph)
{
	return (
		(glyph >= 'A' && glyph <= 'Z') ||
		(glyph >= 'a' && glyph <= 'z')
	);
}


static bool IsAlphaNum(
	int32_t const glyph)
{
	return (
		IsAlpha(glyph) ||
		(glyph >= '0' && glyph <= '9')
	);
}


static void ScanIdentifier(
	TSLexer * lexer)
{
	assert(lexer != NULL);

	Advance(lexer);
	while (IsAlphaNum(lexer->lookahead) || lexer->lookahead == '_') {
		Advance(lexer);
	}
}


static unsigned ScanLengthAndOperator(
	TSLexer * lexer)
{
	assert(lexer != NULL && lexer->lookahead == '&');

	/* LOCAL &a &b
	 * &a = TRUE()
	 * &b = FALSE()&&&a
	 *
	 * LOCAL &c &d
	 * &c = 0x1
	 * &d = 0xf&&c
	 *
	 * LOCAL &e
	 * &e = 0xf&14.
	 */

	MarkEnd(lexer);

	unsigned len = 0;
	while (
		lexer->lookahead == '&' ||
		lexer->lookahead == '(' ||
		lexer->lookahead == '{'
	) {
		if (lexer->lookahead == '&') {
			len += 1u;
		}
		Advance(lexer);
	}

	if (IsAlpha(lexer->lookahead) && len > 0) {
		len -= 1u;
	}
	return len;
}


bool tree_sitter_t32_external_scanner_scan(
	void * payload,
	TSLexer * lexer,
	const bool * valid_symbols)
{
	assert(payload != NULL && lexer != NULL && valid_symbols != NULL);

	scannerState_t *const state = (scannerState_t *) payload;

	if (
		lexer->lookahead == ' ' ||
		lexer->lookahead == '\t' ||
		lexer->lookahead == '\r' ||
		lexer->lookahead == '\n'
	) {
		return false;
	}

	// Labels must start in the first column
	if (valid_symbols[LABEL_IDENTIFIER] && lexer->get_column(lexer) == 0) {
		if (IsAlpha(lexer->lookahead) || lexer->lookahead == '_') {
			ScanIdentifier(lexer);

			if (lexer->lookahead == ':') {
				lexer->result_symbol = LABEL_IDENTIFIER;
				return true;
			}
		}
	}
	else if (valid_symbols[AND_OPERATOR_PRE_HOOK] && lexer->lookahead == '&') {

		state->and_operator_len = ScanLengthAndOperator(lexer);
		lexer->result_symbol = AND_OPERATOR_PRE_HOOK;
		return true;
	}
	else if (
		(valid_symbols[LOGICAL_AND] || valid_symbols[BITWISE_AND]) &&
		lexer->lookahead == '&'
	) {
		unsigned const len = state->and_operator_len;
		for (unsigned ii = 0; ii < len; ii++) {
			Advance(lexer);
		}

		if (len == 1) {
			state->and_operator_len = 0;
			lexer->result_symbol = BITWISE_AND;
			return true;
		}
		if (len == 2) {
			state->and_operator_len = 0;
			lexer->result_symbol = LOGICAL_AND;
			return true;
		}
	}

	if (valid_symbols[NO_BLANK] && lexer->lookahead != ' ') {
		/* Capture zero-length symbol to detect whitespaces
		 * after operators after brackets.
		 */
		lexer->result_symbol = NO_BLANK;
		return true;
	}
	return false;
}


void * tree_sitter_t32_external_scanner_create()
{
	scannerState_t *const s = calloc(1u, sizeof(s[0]));
	assert(s != NULL);

	return s;
}


void tree_sitter_t32_external_scanner_destroy(void * payload)
{
	assert(payload != NULL);

	free(payload);
}
