#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_COLON = 1,
  anon_sym_GLOBAL = 2,
  anon_sym_LOCAL = 3,
  anon_sym_PRIVATE = 4,
  anon_sym_AMP = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  sym__newline = 8,
  sym_identifier = 9,
  sym_label_identifier = 10,
  sym_script = 11,
  sym__unit = 12,
  sym__expression = 13,
  sym_label = 14,
  sym_macro_declaration = 15,
  sym__macro = 16,
  aux_sym_script_repeat1 = 17,
  aux_sym_macro_declaration_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_GLOBAL] = "GLOBAL",
  [anon_sym_LOCAL] = "LOCAL",
  [anon_sym_PRIVATE] = "PRIVATE",
  [anon_sym_AMP] = "&",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym__newline] = "_newline",
  [sym_identifier] = "identifier",
  [sym_label_identifier] = "identifier",
  [sym_script] = "script",
  [sym__unit] = "_unit",
  [sym__expression] = "_expression",
  [sym_label] = "label",
  [sym_macro_declaration] = "macro_declaration",
  [sym__macro] = "_macro",
  [aux_sym_script_repeat1] = "script_repeat1",
  [aux_sym_macro_declaration_repeat1] = "macro_declaration_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_GLOBAL] = anon_sym_GLOBAL,
  [anon_sym_LOCAL] = anon_sym_LOCAL,
  [anon_sym_PRIVATE] = anon_sym_PRIVATE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym__newline] = sym__newline,
  [sym_identifier] = sym_identifier,
  [sym_label_identifier] = sym_identifier,
  [sym_script] = sym_script,
  [sym__unit] = sym__unit,
  [sym__expression] = sym__expression,
  [sym_label] = sym_label,
  [sym_macro_declaration] = sym_macro_declaration,
  [sym__macro] = sym__macro,
  [aux_sym_script_repeat1] = aux_sym_script_repeat1,
  [aux_sym_macro_declaration_repeat1] = aux_sym_macro_declaration_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GLOBAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LOCAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PRIVATE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_label_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_script] = {
    .visible = true,
    .named = true,
  },
  [sym__unit] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_macro_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__macro] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_script_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_macro_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      if (lookahead == '&') ADVANCE(23);
      if (lookahead == '(') ADVANCE(24);
      if (lookahead == ')') ADVANCE(25);
      if (lookahead == ':') ADVANCE(19);
      if (lookahead == 'G') ADVANCE(11);
      if (lookahead == 'L') ADVANCE(12);
      if (lookahead == 'P') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(26);
      END_STATE();
    case 1:
      if (lookahead == '&') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == 'A') ADVANCE(15);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == 'A') ADVANCE(10);
      END_STATE();
    case 5:
      if (lookahead == 'B') ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == 'C') ADVANCE(3);
      END_STATE();
    case 7:
      if (lookahead == 'E') ADVANCE(22);
      END_STATE();
    case 8:
      if (lookahead == 'I') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'L') ADVANCE(21);
      END_STATE();
    case 10:
      if (lookahead == 'L') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'L') ADVANCE(13);
      END_STATE();
    case 12:
      if (lookahead == 'O') ADVANCE(6);
      END_STATE();
    case 13:
      if (lookahead == 'O') ADVANCE(5);
      END_STATE();
    case 14:
      if (lookahead == 'R') ADVANCE(8);
      END_STATE();
    case 15:
      if (lookahead == 'T') ADVANCE(7);
      END_STATE();
    case 16:
      if (lookahead == 'V') ADVANCE(2);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      if (lookahead == '&') ADVANCE(23);
      if (lookahead == 'G') ADVANCE(11);
      if (lookahead == 'L') ADVANCE(12);
      if (lookahead == 'P') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(26);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_GLOBAL);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LOCAL);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_PRIVATE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(26);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0, .external_lex_state = 3},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0, .external_lex_state = 3},
};

enum {
  ts_external_token_identifier = 0,
  ts_external_token_label_identifier = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_identifier] = sym_identifier,
  [ts_external_token_label_identifier] = sym_label_identifier,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_identifier] = true,
    [ts_external_token_label_identifier] = true,
  },
  [2] = {
    [ts_external_token_label_identifier] = true,
  },
  [3] = {
    [ts_external_token_identifier] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_GLOBAL] = ACTIONS(1),
    [anon_sym_LOCAL] = ACTIONS(1),
    [anon_sym_PRIVATE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_label_identifier] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(14),
    [sym__unit] = STATE(2),
    [sym__expression] = STATE(2),
    [sym_label] = STATE(2),
    [sym_macro_declaration] = STATE(2),
    [aux_sym_script_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_GLOBAL] = ACTIONS(5),
    [anon_sym_LOCAL] = ACTIONS(5),
    [anon_sym_PRIVATE] = ACTIONS(5),
    [sym__newline] = ACTIONS(7),
    [sym_label_identifier] = ACTIONS(9),
  },
  [2] = {
    [sym__unit] = STATE(3),
    [sym__expression] = STATE(3),
    [sym_label] = STATE(3),
    [sym_macro_declaration] = STATE(3),
    [aux_sym_script_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_GLOBAL] = ACTIONS(5),
    [anon_sym_LOCAL] = ACTIONS(5),
    [anon_sym_PRIVATE] = ACTIONS(5),
    [sym__newline] = ACTIONS(13),
    [sym_label_identifier] = ACTIONS(9),
  },
  [3] = {
    [sym__unit] = STATE(3),
    [sym__expression] = STATE(3),
    [sym_label] = STATE(3),
    [sym_macro_declaration] = STATE(3),
    [aux_sym_script_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_GLOBAL] = ACTIONS(17),
    [anon_sym_LOCAL] = ACTIONS(17),
    [anon_sym_PRIVATE] = ACTIONS(17),
    [sym__newline] = ACTIONS(20),
    [sym_label_identifier] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(30), 1,
      anon_sym_AMP,
    STATE(5), 2,
      sym__macro,
      aux_sym_macro_declaration_repeat1,
    ACTIONS(26), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(28), 3,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
  [18] = 4,
    ACTIONS(36), 1,
      anon_sym_AMP,
    STATE(5), 2,
      sym__macro,
      aux_sym_macro_declaration_repeat1,
    ACTIONS(32), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(34), 3,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
  [36] = 3,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    ACTIONS(39), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(41), 4,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
      anon_sym_AMP,
  [51] = 3,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    ACTIONS(45), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(47), 4,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
      anon_sym_AMP,
  [66] = 2,
    ACTIONS(45), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(47), 4,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
      anon_sym_AMP,
  [78] = 2,
    ACTIONS(51), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(53), 4,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
      anon_sym_AMP,
  [90] = 2,
    ACTIONS(55), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(57), 3,
      anon_sym_GLOBAL,
      anon_sym_LOCAL,
      anon_sym_PRIVATE,
  [101] = 2,
    ACTIONS(59), 1,
      anon_sym_AMP,
    STATE(4), 2,
      sym__macro,
      aux_sym_macro_declaration_repeat1,
  [109] = 2,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      sym_identifier,
  [116] = 1,
    ACTIONS(65), 1,
      anon_sym_COLON,
  [120] = 1,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
  [124] = 1,
    ACTIONS(69), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 18,
  [SMALL_STATE(6)] = 36,
  [SMALL_STATE(7)] = 51,
  [SMALL_STATE(8)] = 66,
  [SMALL_STATE(9)] = 78,
  [SMALL_STATE(10)] = 90,
  [SMALL_STATE(11)] = 101,
  [SMALL_STATE(12)] = 109,
  [SMALL_STATE(13)] = 116,
  [SMALL_STATE(14)] = 120,
  [SMALL_STATE(15)] = 124,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(11),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(3),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(13),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro_declaration, 2),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro_declaration, 2),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macro_declaration_repeat1, 2),
  [34] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_macro_declaration_repeat1, 2),
  [36] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_macro_declaration_repeat1, 2), SHIFT_REPEAT(12),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 2),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 3),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 4),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 4),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_t32_external_scanner_create(void);
void tree_sitter_t32_external_scanner_destroy(void *);
bool tree_sitter_t32_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_t32_external_scanner_serialize(void *, char *);
void tree_sitter_t32_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_t32(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_t32_external_scanner_create,
      tree_sitter_t32_external_scanner_destroy,
      tree_sitter_t32_external_scanner_scan,
      tree_sitter_t32_external_scanner_serialize,
      tree_sitter_t32_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
