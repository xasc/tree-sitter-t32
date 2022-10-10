#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "tree_sitter/parser.h"


enum TokenType {
	LABEL_IDENTIFIER,
};


typedef struct scannerState_s {
	bool whitespace_after_linebreak;
}
scannerState_t;


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


static bool IsAlpha(int32_t const glyph)
{
	return (
		(glyph >= 'A' && glyph <= 'Z') ||
		(glyph >= 'a' && glyph <= 'z')
	);
}


static bool IsAlphaNum(int32_t const glyph)
{
	return (
		IsAlpha(glyph) ||
		(glyph >= '0' && glyph <= '9')
	);
}


static void ConsumeIdentifier(
	TSLexer * lexer)
{
	assert(lexer != NULL);

	lexer->advance(lexer, false);

	while (IsAlphaNum(lexer->lookahead) || lexer->lookahead == '_') {
		lexer->advance(lexer, false);
	}
}


bool tree_sitter_t32_external_scanner_scan(
	void * payload,
	TSLexer * lexer,
	const bool * valid_symbols)
{
	assert(payload != NULL && lexer != NULL && valid_symbols != NULL);

	scannerState_t *const state = (scannerState_t *) payload;

	if (lexer->lookahead == '\n') {
		return false;
	}

	// Labels must start in the first column
	if (valid_symbols[LABEL_IDENTIFIER] && lexer->get_column(lexer) == 0) {
		if (IsAlpha(lexer->lookahead) || lexer->lookahead == '_') {
			ConsumeIdentifier(lexer);

			if (lexer->lookahead == ':') {
				lexer->result_symbol = LABEL_IDENTIFIER;
				return true;
			}
		}
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
