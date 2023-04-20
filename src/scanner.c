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


#if defined(_MSC_VER)
# define _Static_assert(c__, msg__)  static_assert((c__))
#endif


enum TokenType {
	LABEL_IDENTIFIER,
	AND_OPERATOR_PRE_HOOK,
	DECIMAL_NUMBER,
	DECIMAL_NUMBER_PRE_HOOK,
	PATH,
	LOGICAL_AND,
	BITWISE_AND
};

typedef struct scannerState_s {
	unsigned and_operator_len;
	unsigned decimal_number_len;
}
scannerState_t;

typedef struct sequences_s {
	unsigned num_tildes;
	unsigned num_dots;
	unsigned num_slashes;
	unsigned num_backslashes;
}
sequences_t;

typedef struct pathScan_s {
	bool has_dir_shorthand;
	bool has_file_suffix;
	bool has_drive;
	bool has_wildcard;
	bool has_root;
	bool has_letters;
	sequences_t seq[1];
	unsigned num_total_slashes;
}
pathScan_t;


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


static bool IsNum(
	int32_t const glyph)
{
	return (glyph >= '0' && glyph <= '9');
}


static bool IsAlphaNum(
	int32_t const glyph)
{
	return (IsAlpha(glyph) || IsNum(glyph));
}


static bool IsSpace(
	int32_t const glyph)
{
	return (
		glyph == ' ' ||
		glyph == '\t' ||
		glyph == '\r' ||
		glyph == '\n'
	);
}


static void ScanLabelIdentifier(
	TSLexer * lexer)
{
	assert(lexer != NULL);

	Advance(lexer);
	while (
		IsAlphaNum(lexer->lookahead) ||
		lexer->lookahead == '_' ||
		lexer->lookahead == '.'
	) {
		Advance(lexer);
		if (IsEof(lexer)) {
			break;
		}
	}
}


static void ScanIdentifier(
	TSLexer * lexer)
{
	assert(lexer != NULL);

	Advance(lexer);
	while (
		IsAlphaNum(lexer->lookahead) ||
		lexer->lookahead == '_'
	) {
		Advance(lexer);
		if (IsEof(lexer)) {
			break;
		}
	}
}


static unsigned ScanLengthAndOperator(
	TSLexer *const lexer)
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
	 *
	 * LOCAL &f
	 * &e = FALSE()&&sYmbol.Exit(main)
	 */

	MarkEnd(lexer);

	unsigned len = 0;
	int32_t macro_delim = '\0';
	while (
		lexer->lookahead == '&' ||
		lexer->lookahead == '(' ||
		lexer->lookahead == '{'
	) {
		if (lexer->lookahead == '&') {
			len += 1u;
		}
		else if (lexer->lookahead == '(') {
			macro_delim = ')';
		}
		else if (lexer->lookahead == '{') {
			macro_delim = '}';
		}

		Advance(lexer);
		if (IsEof(lexer)) {
			break;
		}
	}

	// Check for number literal on right hand side
	if (len <= 0 || !IsAlpha(lexer->lookahead)) {
		return len;
	}

	// Check for PRACTICE function calls or parenthesized
	// expressions on right hand side
	ScanIdentifier(lexer);
	if (
		lexer->lookahead == '.' ||
		(macro_delim != '\0' && macro_delim != lexer->lookahead)
	) {
		return len;
	}
	return len - 1u;;
}


static unsigned ScanLengthDecimalNumber(
	TSLexer *const lexer)
{
	assert(lexer != NULL && IsNum(lexer->lookahead));

	/* LOCAL &a
	 * &a = 1...4
	 *
	 * LOCAL &b
	 * &b = 1..2
	 *
	 * LOCAL &c
	 * &c = 1.MHZ
	 *
	 * LOCAL &d
	 * &d = 1.ms
	 *
	 * LOCAL &e
	 * &e = 1.0%
	 */
	MarkEnd(lexer);

	unsigned len = 0;
	unsigned num_dots = 0;
	while (
		IsNum(lexer->lookahead) ||
		lexer->lookahead == '.'
	) {
		if (IsNum(lexer->lookahead)) {
			if (num_dots == 1u) {
				// Floating point number detected
				return 0;
			}
			else if (num_dots > 1u) {
				// Number after range operator
				break;
			}
			len += 1u;
		}
		else if (lexer->lookahead == '.') {
			num_dots += 1u;
		}

		Advance(lexer);
		if (IsEof(lexer)) {
			break;
		}
	}

	// Check for binary, hexadecimal numbers, time and frequency
	// literals, and addresses
	if (
		// addresses
		lexer->lookahead == ':' || lexer->lookahead ==  '\'' ||
		// bitmasks
		lexer->lookahead == 'x' || lexer->lookahead == 'X' ||
		lexer->lookahead == 'y' || lexer->lookahead == 'Y' ||
		// time
		lexer->lookahead == 'm' || lexer->lookahead == 'u' || lexer->lookahead == 'n' || lexer->lookahead == 's' ||
		lexer->lookahead == 'M' || lexer->lookahead == 'U' || lexer->lookahead == 'N' || lexer->lookahead == 'S' ||
		// frequency
		lexer->lookahead == 'k' || lexer->lookahead == 'm' || lexer->lookahead == 'g' || lexer->lookahead == 'h' ||
		lexer->lookahead == 'K' || lexer->lookahead == 'M' || lexer->lookahead == 'G' || lexer->lookahead == 'H'
	) {
		return 0;
	}

	// Check for percentage literals
	if (lexer->lookahead == '%') {
		Advance(lexer);
		if (IsSpace(lexer->lookahead)) {
			return 0;
		}
	}

	if (num_dots == 1u || num_dots == 3u) {
		len += 1u;
	}
	return len;
}


static unsigned TrackConsecutiveSymbols(
	char const sym,
	int32_t const glyph,
	unsigned counter)
{
	if (glyph == sym) {
		return counter + 1u;
	}
	return 0;
}


static bool ScanPathLiteral(
	TSLexer *const lexer)
{
	assert(lexer != NULL);

	bool is_expression = false;
	bool is_comment = false;
	bool is_line_continuation = false;
	bool is_option = false;
	bool is_symbol = false;

	pathScan_t scan[1] = {{0}};

	unsigned ii = 0;
	while (!(IsSpace(lexer->lookahead) || IsEof(lexer))) {
		if (
			lexer->lookahead == '(' ||
			lexer->lookahead == ')' ||
			lexer->lookahead == '&' ||
			lexer->lookahead == '%' ||
			lexer->lookahead == '+' ||
			lexer->lookahead == '"' ||
			lexer->lookahead == '`' ||
			lexer->lookahead == '\'' ||
			((ii == 0 || scan->seq->num_tildes > 0) && IsNum(lexer->lookahead))
		) {
			/*
			 * Detect expressions containing tilde operators, macros or
			 * time literals.
			 */
			is_expression = true;
			break;
		}
		else if (lexer->lookahead == '/') {
			if (scan->seq->num_slashes > 0) {
				is_comment = true;
				break;
			}

			if (ii == 0) {
				is_option = true;
				scan->has_root = true;
			}
		}
		else if (lexer->lookahead == '\\' && scan->seq->num_backslashes) {
			is_symbol = true;
			break;
		}
		else if (IsAlpha(lexer->lookahead)) {
			scan->has_letters = true;
		}

		if (ii == 1 && lexer->lookahead == ':') {
			scan->has_drive = true;
		}
		else if (ii == 2 && scan->has_drive) {
			scan->has_drive = (lexer->lookahead == '\\');
		}
		else if (lexer->lookahead == '*' || lexer->lookahead == '?') {
			if (scan->seq->num_slashes > 0 || scan->seq->num_backslashes > 0) {
				scan->has_wildcard = true;
			}
		}
		else if (lexer->lookahead == '/' || lexer->lookahead == '\\') {
			if (scan->seq->num_tildes > 0 || scan->seq->num_dots > 0) {
				scan->has_dir_shorthand = true;
			}
		}
		else if (scan->seq->num_dots > 0 && IsAlpha(lexer->lookahead)) {
			scan->has_file_suffix = true;
		}

		scan->seq->num_tildes = TrackConsecutiveSymbols('~', lexer->lookahead, scan->seq->num_tildes);

		scan->seq->num_dots = TrackConsecutiveSymbols('.', lexer->lookahead, scan->seq->num_dots);

		scan->seq->num_slashes = TrackConsecutiveSymbols('/', lexer->lookahead, scan->seq->num_slashes);

		scan->seq->num_backslashes = TrackConsecutiveSymbols('\\', lexer->lookahead, scan->seq->num_backslashes);

		if (lexer->lookahead == '/') {
			scan->num_total_slashes += 1u;
		}

		Advance(lexer);
		ii += 1u;
	}

	if (scan->seq->num_backslashes > 0 && (lexer->lookahead == '\r' || lexer->lookahead == '\n')) {
		is_line_continuation = true;
	}
	else if (is_option && scan->num_total_slashes != 1u) {
		is_option = false;
	}

	if (is_expression || is_comment || is_line_continuation || is_option || is_symbol) {
		return false;
	}

	return (
		scan->has_dir_shorthand ||
		scan->has_file_suffix ||
		scan->has_drive ||
		scan->has_wildcard ||
		(scan->has_root && scan->has_letters && scan->num_total_slashes > 1u)
	);
}


bool tree_sitter_t32_external_scanner_scan(
	void * payload,
	TSLexer * lexer,
	const bool * valid_symbols)
{
	assert(payload != NULL && lexer != NULL && valid_symbols != NULL);

	scannerState_t *const state = (scannerState_t *) payload;

	if (IsSpace(lexer->lookahead)) {
		return false;
	}

	// Labels must start in the first column
	if (valid_symbols[LABEL_IDENTIFIER] && lexer->get_column(lexer) == 0) {
		if (
			IsAlpha(lexer->lookahead) ||
			lexer->lookahead == '_' ||
			lexer->lookahead == '.'
		) {
			ScanLabelIdentifier(lexer);

			if (lexer->lookahead == ':') {
				lexer->result_symbol = LABEL_IDENTIFIER;
				return true;
			}
		}
	}
	else if (valid_symbols[AND_OPERATOR_PRE_HOOK] && lexer->lookahead == '&') {
		state->and_operator_len = ScanLengthAndOperator(lexer);
		if (state->and_operator_len > 0) {
			lexer->result_symbol = AND_OPERATOR_PRE_HOOK;
			return true;
		}
	}
	else if (
		(valid_symbols[LOGICAL_AND] || valid_symbols[BITWISE_AND]) &&
		state->and_operator_len > 0
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
	else if (valid_symbols[DECIMAL_NUMBER_PRE_HOOK] && IsNum(lexer->lookahead)) {
		state->decimal_number_len = ScanLengthDecimalNumber(lexer);
		if (state->decimal_number_len > 0) {
			lexer->result_symbol = DECIMAL_NUMBER_PRE_HOOK;
			return true;
		}
	}
	else if (valid_symbols[DECIMAL_NUMBER] && state->decimal_number_len) {
		unsigned const len = state->decimal_number_len;
		for (unsigned ii = 0; ii < len; ii++) {
			Advance(lexer);
		}

		if (len > 0) {
			state->decimal_number_len = 0;
			lexer->result_symbol = DECIMAL_NUMBER;
			return true;
		}
	}
	else if (valid_symbols[PATH] && ScanPathLiteral(lexer)) {
		lexer->result_symbol = PATH;
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
