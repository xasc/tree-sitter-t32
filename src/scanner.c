#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "tree_sitter/parser.h"


enum TokenType {
	LABEL_IDENTIFIER,
	NO_BLANK,
	LOGICAL_AND,
	BITWISE_AND
};


typedef struct scannerState_s {
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


static unsigned ScanAmpersandOperators(
	TSLexer * lexer)
{
	assert(lexer != NULL);

	/* LOCAL &a &b
	 * &a = TRUE()
	 * &b = FALSE()&&&a
	 *
	 * LOCAL &c &d
	 * &c = 0x1
	 * &d = 0xf&&c
	 */
	unsigned num = 0;
	for (unsigned ii = 0; ii < 2; ii++) {
		if (lexer->lookahead == '&') {
			Advance(lexer);
		}

		if (IsAlpha(lexer->lookahead)) {
			return num;
		}
		MarkEnd(lexer);
		num += 1u;
	}
	return num;
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
	else if (
		(valid_symbols[LOGICAL_AND] || valid_symbols[BITWISE_AND]) &&
		lexer->lookahead == '&'
	) {
		unsigned const num = ScanAmpersandOperators(lexer);
		if (num == 1) {
			lexer->result_symbol = BITWISE_AND;
			return true;
		}
		if (num == 2) {
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
