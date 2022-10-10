#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 52
#define LARGE_STATE_COUNT 26
#define SYMBOL_COUNT 39
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  sym_identifier = 1,
  anon_sym_IF = 2,
  anon_sym_if = 3,
  aux_sym_else_block_token1 = 4,
  anon_sym_COLON = 5,
  anon_sym_AMP = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_GLOBAL = 9,
  anon_sym_global = 10,
  anon_sym_LOCAL = 11,
  anon_sym_local = 12,
  anon_sym_PRIVATE = 13,
  anon_sym_private = 14,
  anon_sym_STOP = 15,
  anon_sym_stop = 16,
  anon_sym_CONTinue = 17,
  anon_sym_continue = 18,
  anon_sym_CONT = 19,
  anon_sym_cont = 20,
  aux_sym_command_token1 = 21,
  sym__newline = 22,
  sym_label_identifier = 23,
  sym_script = 24,
  sym__top_level = 25,
  sym__block = 26,
  sym_if_block = 27,
  sym_else_block = 28,
  sym__expression = 29,
  sym_label = 30,
  sym_macro_declaration = 31,
  sym__macro = 32,
  sym__declaration_command = 33,
  sym__flow_command = 34,
  sym_command = 35,
  aux_sym_script_repeat1 = 36,
  aux_sym_if_block_repeat1 = 37,
  aux_sym_macro_declaration_repeat1 = 38,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_IF] = "IF",
  [anon_sym_if] = "if",
  [aux_sym_else_block_token1] = "else_block_token1",
  [anon_sym_COLON] = ":",
  [anon_sym_AMP] = "&",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_GLOBAL] = "GLOBAL",
  [anon_sym_global] = "global",
  [anon_sym_LOCAL] = "LOCAL",
  [anon_sym_local] = "local",
  [anon_sym_PRIVATE] = "PRIVATE",
  [anon_sym_private] = "private",
  [anon_sym_STOP] = "STOP",
  [anon_sym_stop] = "stop",
  [anon_sym_CONTinue] = "CONTinue",
  [anon_sym_continue] = "continue",
  [anon_sym_CONT] = "CONT",
  [anon_sym_cont] = "cont",
  [aux_sym_command_token1] = "command_token1",
  [sym__newline] = "_newline",
  [sym_label_identifier] = "identifier",
  [sym_script] = "script",
  [sym__top_level] = "_top_level",
  [sym__block] = "_block",
  [sym_if_block] = "if_block",
  [sym_else_block] = "else_block",
  [sym__expression] = "_expression",
  [sym_label] = "label",
  [sym_macro_declaration] = "macro_declaration",
  [sym__macro] = "_macro",
  [sym__declaration_command] = "_declaration_command",
  [sym__flow_command] = "command",
  [sym_command] = "command",
  [aux_sym_script_repeat1] = "script_repeat1",
  [aux_sym_if_block_repeat1] = "if_block_repeat1",
  [aux_sym_macro_declaration_repeat1] = "macro_declaration_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_IF] = anon_sym_IF,
  [anon_sym_if] = anon_sym_if,
  [aux_sym_else_block_token1] = aux_sym_else_block_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_GLOBAL] = anon_sym_GLOBAL,
  [anon_sym_global] = anon_sym_global,
  [anon_sym_LOCAL] = anon_sym_LOCAL,
  [anon_sym_local] = anon_sym_local,
  [anon_sym_PRIVATE] = anon_sym_PRIVATE,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_STOP] = anon_sym_STOP,
  [anon_sym_stop] = anon_sym_stop,
  [anon_sym_CONTinue] = anon_sym_CONTinue,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_CONT] = anon_sym_CONT,
  [anon_sym_cont] = anon_sym_cont,
  [aux_sym_command_token1] = aux_sym_command_token1,
  [sym__newline] = sym__newline,
  [sym_label_identifier] = sym_identifier,
  [sym_script] = sym_script,
  [sym__top_level] = sym__top_level,
  [sym__block] = sym__block,
  [sym_if_block] = sym_if_block,
  [sym_else_block] = sym_else_block,
  [sym__expression] = sym__expression,
  [sym_label] = sym_label,
  [sym_macro_declaration] = sym_macro_declaration,
  [sym__macro] = sym__macro,
  [sym__declaration_command] = sym__declaration_command,
  [sym__flow_command] = sym_command,
  [sym_command] = sym_command,
  [aux_sym_script_repeat1] = aux_sym_script_repeat1,
  [aux_sym_if_block_repeat1] = aux_sym_if_block_repeat1,
  [aux_sym_macro_declaration_repeat1] = aux_sym_macro_declaration_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_IF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_else_block_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
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
  [anon_sym_GLOBAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_global] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LOCAL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_local] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PRIVATE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_private] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STOP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_stop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CONTinue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CONT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cont] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_command_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
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
  [sym__top_level] = {
    .visible = false,
    .named = true,
  },
  [sym__block] = {
    .visible = false,
    .named = true,
  },
  [sym_if_block] = {
    .visible = true,
    .named = true,
  },
  [sym_else_block] = {
    .visible = true,
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
  [sym__declaration_command] = {
    .visible = false,
    .named = true,
  },
  [sym__flow_command] = {
    .visible = true,
    .named = true,
  },
  [sym_command] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_script_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_block_repeat1] = {
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
  [6] = 4,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 9,
  [14] = 14,
  [15] = 11,
  [16] = 10,
  [17] = 17,
  [18] = 18,
  [19] = 14,
  [20] = 17,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 24,
  [27] = 25,
  [28] = 21,
  [29] = 18,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 32,
  [34] = 34,
  [35] = 34,
  [36] = 17,
  [37] = 14,
  [38] = 38,
  [39] = 38,
  [40] = 38,
  [41] = 21,
  [42] = 42,
  [43] = 43,
  [44] = 18,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 43,
  [49] = 45,
  [50] = 45,
  [51] = 47,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == ':') ADVANCE(15);
      if (lookahead == 'C') ADVANCE(114);
      if (lookahead == 'E') ADVANCE(109);
      if (lookahead == 'G') ADVANCE(112);
      if (lookahead == 'I') ADVANCE(107);
      if (lookahead == 'L') ADVANCE(115);
      if (lookahead == 'P') ADVANCE(119);
      if (lookahead == 'S') ADVANCE(123);
      if (lookahead == 'c') ADVANCE(143);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == 'g') ADVANCE(139);
      if (lookahead == 'i') ADVANCE(134);
      if (lookahead == 'l') ADVANCE(144);
      if (lookahead == 'p') ADVANCE(148);
      if (lookahead == 's') ADVANCE(152);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(6)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 1:
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(57);
      if (lookahead == 'G') ADVANCE(55);
      if (lookahead == 'I') ADVANCE(50);
      if (lookahead == 'L') ADVANCE(58);
      if (lookahead == 'P') ADVANCE(62);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'g') ADVANCE(82);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'p') ADVANCE(91);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 3:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 4:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == 'C') ADVANCE(57);
      if (lookahead == 'E') ADVANCE(54);
      if (lookahead == 'G') ADVANCE(55);
      if (lookahead == 'I') ADVANCE(50);
      if (lookahead == 'L') ADVANCE(58);
      if (lookahead == 'P') ADVANCE(62);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == 'g') ADVANCE(82);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'p') ADVANCE(91);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(7)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(159);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 5:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == ')') ADVANCE(18);
      if (lookahead == 'C') ADVANCE(57);
      if (lookahead == 'G') ADVANCE(55);
      if (lookahead == 'I') ADVANCE(50);
      if (lookahead == 'L') ADVANCE(58);
      if (lookahead == 'P') ADVANCE(62);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'g') ADVANCE(82);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'p') ADVANCE(91);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(8)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(160);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 6:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(114);
      if (lookahead == 'E') ADVANCE(109);
      if (lookahead == 'G') ADVANCE(112);
      if (lookahead == 'I') ADVANCE(107);
      if (lookahead == 'L') ADVANCE(115);
      if (lookahead == 'P') ADVANCE(119);
      if (lookahead == 'S') ADVANCE(123);
      if (lookahead == 'c') ADVANCE(143);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == 'g') ADVANCE(139);
      if (lookahead == 'i') ADVANCE(134);
      if (lookahead == 'l') ADVANCE(144);
      if (lookahead == 'p') ADVANCE(148);
      if (lookahead == 's') ADVANCE(152);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(6)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 7:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(57);
      if (lookahead == 'E') ADVANCE(54);
      if (lookahead == 'G') ADVANCE(55);
      if (lookahead == 'I') ADVANCE(50);
      if (lookahead == 'L') ADVANCE(58);
      if (lookahead == 'P') ADVANCE(62);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == 'g') ADVANCE(82);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'p') ADVANCE(91);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(7)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(159);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 8:
      if (eof) ADVANCE(9);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == 'C') ADVANCE(57);
      if (lookahead == 'G') ADVANCE(55);
      if (lookahead == 'I') ADVANCE(50);
      if (lookahead == 'L') ADVANCE(58);
      if (lookahead == 'P') ADVANCE(62);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'g') ADVANCE(82);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'p') ADVANCE(91);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(8)
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(160);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_IF);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_IF);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_else_block_token1);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_GLOBAL);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_GLOBAL);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_global);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_global);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LOCAL);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LOCAL);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_local);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_local);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_PRIVATE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_PRIVATE);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_private);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_STOP);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_STOP);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_stop);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_stop);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_CONTinue);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_CONTinue);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_CONT);
      if (lookahead == 'i') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_CONT);
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_cont);
      if (lookahead == 'i') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_cont);
      if (lookahead == 'i') ADVANCE(85);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'A') ADVANCE(52);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'A') ADVANCE(53);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'A') ADVANCE(65);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'B') ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'C') ADVANCE(43);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'E') ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'E') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'F') ADVANCE(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'I') ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'L') ADVANCE(23);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'L') ADVANCE(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'L') ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'L') ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'N') ADVANCE(64);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'O') ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'O') ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'O') ADVANCE(46);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'O') ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'P') ADVANCE(31);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'R') ADVANCE(51);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'S') ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'T') ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'T') ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'T') ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'V') ADVANCE(45);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'a') ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'a') ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'a') ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'b') ADVANCE(69);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'c') ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'e') ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'e') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'e') ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'e') ADVANCE(37);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'f') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'i') ADVANCE(98);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'l') ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'l') ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'l') ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'l') ADVANCE(88);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'n') ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'n') ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'n') ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'o') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'o') ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'o') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'o') ADVANCE(90);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'p') ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'r') ADVANCE(78);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 's') ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 't') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 't') ADVANCE(74);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 't') ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'u') ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'u') ADVANCE(76);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (lookahead == 'v') ADVANCE(70);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_command_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'I') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'V') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(157);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == 'E') ADVANCE(109);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == 'E') ADVANCE(54);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(160);
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
  [1] = {.lex_state = 5, .external_lex_state = 1},
  [2] = {.lex_state = 5, .external_lex_state = 1},
  [3] = {.lex_state = 5, .external_lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 4, .external_lex_state = 1},
  [8] = {.lex_state = 4, .external_lex_state = 1},
  [9] = {.lex_state = 4, .external_lex_state = 1},
  [10] = {.lex_state = 4, .external_lex_state = 1},
  [11] = {.lex_state = 4, .external_lex_state = 1},
  [12] = {.lex_state = 4, .external_lex_state = 1},
  [13] = {.lex_state = 4, .external_lex_state = 1},
  [14] = {.lex_state = 4, .external_lex_state = 1},
  [15] = {.lex_state = 5, .external_lex_state = 1},
  [16] = {.lex_state = 5, .external_lex_state = 1},
  [17] = {.lex_state = 4, .external_lex_state = 1},
  [18] = {.lex_state = 4, .external_lex_state = 1},
  [19] = {.lex_state = 5, .external_lex_state = 1},
  [20] = {.lex_state = 5, .external_lex_state = 1},
  [21] = {.lex_state = 4, .external_lex_state = 1},
  [22] = {.lex_state = 4, .external_lex_state = 1},
  [23] = {.lex_state = 4, .external_lex_state = 1},
  [24] = {.lex_state = 4, .external_lex_state = 1},
  [25] = {.lex_state = 4, .external_lex_state = 1},
  [26] = {.lex_state = 5, .external_lex_state = 1},
  [27] = {.lex_state = 5, .external_lex_state = 1},
  [28] = {.lex_state = 5, .external_lex_state = 1},
  [29] = {.lex_state = 5, .external_lex_state = 1},
  [30] = {.lex_state = 5, .external_lex_state = 1},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 5},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 5},
  [44] = {.lex_state = 5},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 5},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 5},
};

enum {
  ts_external_token_label_identifier = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_label_identifier] = sym_label_identifier,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_label_identifier] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_IF] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [aux_sym_else_block_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_GLOBAL] = ACTIONS(1),
    [anon_sym_global] = ACTIONS(1),
    [anon_sym_LOCAL] = ACTIONS(1),
    [anon_sym_local] = ACTIONS(1),
    [anon_sym_PRIVATE] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_STOP] = ACTIONS(1),
    [anon_sym_stop] = ACTIONS(1),
    [anon_sym_CONTinue] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_CONT] = ACTIONS(1),
    [anon_sym_cont] = ACTIONS(1),
    [aux_sym_command_token1] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym_label_identifier] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(42),
    [sym__top_level] = STATE(2),
    [sym__block] = STATE(2),
    [sym_if_block] = STATE(2),
    [sym__expression] = STATE(2),
    [sym_label] = STATE(2),
    [sym_macro_declaration] = STATE(2),
    [sym__macro] = STATE(2),
    [sym__declaration_command] = STATE(32),
    [sym__flow_command] = STATE(2),
    [sym_command] = STATE(2),
    [aux_sym_script_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_IF] = ACTIONS(5),
    [anon_sym_if] = ACTIONS(5),
    [anon_sym_AMP] = ACTIONS(7),
    [anon_sym_GLOBAL] = ACTIONS(9),
    [anon_sym_global] = ACTIONS(9),
    [anon_sym_LOCAL] = ACTIONS(9),
    [anon_sym_local] = ACTIONS(9),
    [anon_sym_PRIVATE] = ACTIONS(9),
    [anon_sym_private] = ACTIONS(9),
    [anon_sym_STOP] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(11),
    [anon_sym_CONTinue] = ACTIONS(11),
    [anon_sym_continue] = ACTIONS(11),
    [anon_sym_CONT] = ACTIONS(11),
    [anon_sym_cont] = ACTIONS(11),
    [aux_sym_command_token1] = ACTIONS(13),
    [sym__newline] = ACTIONS(15),
    [sym_label_identifier] = ACTIONS(17),
  },
  [2] = {
    [sym__top_level] = STATE(3),
    [sym__block] = STATE(3),
    [sym_if_block] = STATE(3),
    [sym__expression] = STATE(3),
    [sym_label] = STATE(3),
    [sym_macro_declaration] = STATE(3),
    [sym__macro] = STATE(3),
    [sym__declaration_command] = STATE(32),
    [sym__flow_command] = STATE(3),
    [sym_command] = STATE(3),
    [aux_sym_script_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [anon_sym_IF] = ACTIONS(5),
    [anon_sym_if] = ACTIONS(5),
    [anon_sym_AMP] = ACTIONS(7),
    [anon_sym_GLOBAL] = ACTIONS(9),
    [anon_sym_global] = ACTIONS(9),
    [anon_sym_LOCAL] = ACTIONS(9),
    [anon_sym_local] = ACTIONS(9),
    [anon_sym_PRIVATE] = ACTIONS(9),
    [anon_sym_private] = ACTIONS(9),
    [anon_sym_STOP] = ACTIONS(11),
    [anon_sym_stop] = ACTIONS(11),
    [anon_sym_CONTinue] = ACTIONS(11),
    [anon_sym_continue] = ACTIONS(11),
    [anon_sym_CONT] = ACTIONS(11),
    [anon_sym_cont] = ACTIONS(11),
    [aux_sym_command_token1] = ACTIONS(13),
    [sym__newline] = ACTIONS(21),
    [sym_label_identifier] = ACTIONS(17),
  },
  [3] = {
    [sym__top_level] = STATE(3),
    [sym__block] = STATE(3),
    [sym_if_block] = STATE(3),
    [sym__expression] = STATE(3),
    [sym_label] = STATE(3),
    [sym_macro_declaration] = STATE(3),
    [sym__macro] = STATE(3),
    [sym__declaration_command] = STATE(32),
    [sym__flow_command] = STATE(3),
    [sym_command] = STATE(3),
    [aux_sym_script_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_IF] = ACTIONS(25),
    [anon_sym_if] = ACTIONS(25),
    [anon_sym_AMP] = ACTIONS(28),
    [anon_sym_GLOBAL] = ACTIONS(31),
    [anon_sym_global] = ACTIONS(31),
    [anon_sym_LOCAL] = ACTIONS(31),
    [anon_sym_local] = ACTIONS(31),
    [anon_sym_PRIVATE] = ACTIONS(31),
    [anon_sym_private] = ACTIONS(31),
    [anon_sym_STOP] = ACTIONS(34),
    [anon_sym_stop] = ACTIONS(34),
    [anon_sym_CONTinue] = ACTIONS(34),
    [anon_sym_continue] = ACTIONS(34),
    [anon_sym_CONT] = ACTIONS(34),
    [anon_sym_cont] = ACTIONS(34),
    [aux_sym_command_token1] = ACTIONS(37),
    [sym__newline] = ACTIONS(40),
    [sym_label_identifier] = ACTIONS(43),
  },
  [4] = {
    [sym__block] = STATE(9),
    [sym_if_block] = STATE(9),
    [sym__expression] = STATE(9),
    [sym_macro_declaration] = STATE(9),
    [sym__macro] = STATE(9),
    [sym__declaration_command] = STATE(33),
    [sym__flow_command] = STATE(9),
    [sym_command] = STATE(9),
    [anon_sym_IF] = ACTIONS(46),
    [anon_sym_if] = ACTIONS(46),
    [anon_sym_AMP] = ACTIONS(48),
    [anon_sym_GLOBAL] = ACTIONS(50),
    [anon_sym_global] = ACTIONS(50),
    [anon_sym_LOCAL] = ACTIONS(50),
    [anon_sym_local] = ACTIONS(50),
    [anon_sym_PRIVATE] = ACTIONS(50),
    [anon_sym_private] = ACTIONS(50),
    [anon_sym_STOP] = ACTIONS(52),
    [anon_sym_stop] = ACTIONS(52),
    [anon_sym_CONTinue] = ACTIONS(52),
    [anon_sym_continue] = ACTIONS(52),
    [anon_sym_CONT] = ACTIONS(54),
    [anon_sym_cont] = ACTIONS(54),
    [aux_sym_command_token1] = ACTIONS(56),
  },
  [5] = {
    [sym__block] = STATE(23),
    [sym_if_block] = STATE(23),
    [sym__expression] = STATE(23),
    [sym_macro_declaration] = STATE(23),
    [sym__macro] = STATE(23),
    [sym__declaration_command] = STATE(33),
    [sym__flow_command] = STATE(23),
    [sym_command] = STATE(23),
    [anon_sym_IF] = ACTIONS(46),
    [anon_sym_if] = ACTIONS(46),
    [anon_sym_AMP] = ACTIONS(48),
    [anon_sym_GLOBAL] = ACTIONS(50),
    [anon_sym_global] = ACTIONS(50),
    [anon_sym_LOCAL] = ACTIONS(50),
    [anon_sym_local] = ACTIONS(50),
    [anon_sym_PRIVATE] = ACTIONS(50),
    [anon_sym_private] = ACTIONS(50),
    [anon_sym_STOP] = ACTIONS(52),
    [anon_sym_stop] = ACTIONS(52),
    [anon_sym_CONTinue] = ACTIONS(52),
    [anon_sym_continue] = ACTIONS(52),
    [anon_sym_CONT] = ACTIONS(54),
    [anon_sym_cont] = ACTIONS(54),
    [aux_sym_command_token1] = ACTIONS(56),
  },
  [6] = {
    [sym__block] = STATE(13),
    [sym_if_block] = STATE(13),
    [sym__expression] = STATE(13),
    [sym_macro_declaration] = STATE(13),
    [sym__macro] = STATE(13),
    [sym__declaration_command] = STATE(33),
    [sym__flow_command] = STATE(13),
    [sym_command] = STATE(13),
    [anon_sym_IF] = ACTIONS(46),
    [anon_sym_if] = ACTIONS(46),
    [anon_sym_AMP] = ACTIONS(48),
    [anon_sym_GLOBAL] = ACTIONS(50),
    [anon_sym_global] = ACTIONS(50),
    [anon_sym_LOCAL] = ACTIONS(50),
    [anon_sym_local] = ACTIONS(50),
    [anon_sym_PRIVATE] = ACTIONS(50),
    [anon_sym_private] = ACTIONS(50),
    [anon_sym_STOP] = ACTIONS(52),
    [anon_sym_stop] = ACTIONS(52),
    [anon_sym_CONTinue] = ACTIONS(52),
    [anon_sym_continue] = ACTIONS(52),
    [anon_sym_CONT] = ACTIONS(54),
    [anon_sym_cont] = ACTIONS(54),
    [aux_sym_command_token1] = ACTIONS(56),
  },
  [7] = {
    [sym_else_block] = STATE(12),
    [aux_sym_if_block_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(58),
    [anon_sym_IF] = ACTIONS(60),
    [anon_sym_if] = ACTIONS(60),
    [aux_sym_else_block_token1] = ACTIONS(62),
    [anon_sym_AMP] = ACTIONS(60),
    [anon_sym_GLOBAL] = ACTIONS(60),
    [anon_sym_global] = ACTIONS(60),
    [anon_sym_LOCAL] = ACTIONS(60),
    [anon_sym_local] = ACTIONS(60),
    [anon_sym_PRIVATE] = ACTIONS(60),
    [anon_sym_private] = ACTIONS(60),
    [anon_sym_STOP] = ACTIONS(60),
    [anon_sym_stop] = ACTIONS(60),
    [anon_sym_CONTinue] = ACTIONS(60),
    [anon_sym_continue] = ACTIONS(60),
    [anon_sym_CONT] = ACTIONS(60),
    [anon_sym_cont] = ACTIONS(60),
    [aux_sym_command_token1] = ACTIONS(60),
    [sym__newline] = ACTIONS(60),
    [sym_label_identifier] = ACTIONS(58),
  },
  [8] = {
    [sym_else_block] = STATE(12),
    [aux_sym_if_block_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(58),
    [anon_sym_IF] = ACTIONS(60),
    [anon_sym_if] = ACTIONS(60),
    [aux_sym_else_block_token1] = ACTIONS(60),
    [anon_sym_AMP] = ACTIONS(60),
    [anon_sym_GLOBAL] = ACTIONS(60),
    [anon_sym_global] = ACTIONS(60),
    [anon_sym_LOCAL] = ACTIONS(60),
    [anon_sym_local] = ACTIONS(60),
    [anon_sym_PRIVATE] = ACTIONS(60),
    [anon_sym_private] = ACTIONS(60),
    [anon_sym_STOP] = ACTIONS(60),
    [anon_sym_stop] = ACTIONS(60),
    [anon_sym_CONTinue] = ACTIONS(60),
    [anon_sym_continue] = ACTIONS(60),
    [anon_sym_CONT] = ACTIONS(60),
    [anon_sym_cont] = ACTIONS(60),
    [aux_sym_command_token1] = ACTIONS(60),
    [sym__newline] = ACTIONS(60),
    [sym_label_identifier] = ACTIONS(58),
  },
  [9] = {
    [sym_else_block] = STATE(8),
    [aux_sym_if_block_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(64),
    [anon_sym_IF] = ACTIONS(66),
    [anon_sym_if] = ACTIONS(66),
    [aux_sym_else_block_token1] = ACTIONS(66),
    [anon_sym_AMP] = ACTIONS(66),
    [anon_sym_GLOBAL] = ACTIONS(66),
    [anon_sym_global] = ACTIONS(66),
    [anon_sym_LOCAL] = ACTIONS(66),
    [anon_sym_local] = ACTIONS(66),
    [anon_sym_PRIVATE] = ACTIONS(66),
    [anon_sym_private] = ACTIONS(66),
    [anon_sym_STOP] = ACTIONS(66),
    [anon_sym_stop] = ACTIONS(66),
    [anon_sym_CONTinue] = ACTIONS(66),
    [anon_sym_continue] = ACTIONS(66),
    [anon_sym_CONT] = ACTIONS(66),
    [anon_sym_cont] = ACTIONS(66),
    [aux_sym_command_token1] = ACTIONS(66),
    [sym__newline] = ACTIONS(66),
    [sym_label_identifier] = ACTIONS(64),
  },
  [10] = {
    [sym__macro] = STATE(10),
    [aux_sym_macro_declaration_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(68),
    [anon_sym_IF] = ACTIONS(70),
    [anon_sym_if] = ACTIONS(70),
    [aux_sym_else_block_token1] = ACTIONS(70),
    [anon_sym_AMP] = ACTIONS(72),
    [anon_sym_GLOBAL] = ACTIONS(70),
    [anon_sym_global] = ACTIONS(70),
    [anon_sym_LOCAL] = ACTIONS(70),
    [anon_sym_local] = ACTIONS(70),
    [anon_sym_PRIVATE] = ACTIONS(70),
    [anon_sym_private] = ACTIONS(70),
    [anon_sym_STOP] = ACTIONS(70),
    [anon_sym_stop] = ACTIONS(70),
    [anon_sym_CONTinue] = ACTIONS(70),
    [anon_sym_continue] = ACTIONS(70),
    [anon_sym_CONT] = ACTIONS(70),
    [anon_sym_cont] = ACTIONS(70),
    [aux_sym_command_token1] = ACTIONS(70),
    [sym__newline] = ACTIONS(70),
    [sym_label_identifier] = ACTIONS(68),
  },
  [11] = {
    [sym__macro] = STATE(10),
    [aux_sym_macro_declaration_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(75),
    [anon_sym_IF] = ACTIONS(77),
    [anon_sym_if] = ACTIONS(77),
    [aux_sym_else_block_token1] = ACTIONS(77),
    [anon_sym_AMP] = ACTIONS(79),
    [anon_sym_GLOBAL] = ACTIONS(77),
    [anon_sym_global] = ACTIONS(77),
    [anon_sym_LOCAL] = ACTIONS(77),
    [anon_sym_local] = ACTIONS(77),
    [anon_sym_PRIVATE] = ACTIONS(77),
    [anon_sym_private] = ACTIONS(77),
    [anon_sym_STOP] = ACTIONS(77),
    [anon_sym_stop] = ACTIONS(77),
    [anon_sym_CONTinue] = ACTIONS(77),
    [anon_sym_continue] = ACTIONS(77),
    [anon_sym_CONT] = ACTIONS(77),
    [anon_sym_cont] = ACTIONS(77),
    [aux_sym_command_token1] = ACTIONS(77),
    [sym__newline] = ACTIONS(77),
    [sym_label_identifier] = ACTIONS(75),
  },
  [12] = {
    [sym_else_block] = STATE(12),
    [aux_sym_if_block_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(81),
    [anon_sym_IF] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(83),
    [aux_sym_else_block_token1] = ACTIONS(85),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_GLOBAL] = ACTIONS(83),
    [anon_sym_global] = ACTIONS(83),
    [anon_sym_LOCAL] = ACTIONS(83),
    [anon_sym_local] = ACTIONS(83),
    [anon_sym_PRIVATE] = ACTIONS(83),
    [anon_sym_private] = ACTIONS(83),
    [anon_sym_STOP] = ACTIONS(83),
    [anon_sym_stop] = ACTIONS(83),
    [anon_sym_CONTinue] = ACTIONS(83),
    [anon_sym_continue] = ACTIONS(83),
    [anon_sym_CONT] = ACTIONS(83),
    [anon_sym_cont] = ACTIONS(83),
    [aux_sym_command_token1] = ACTIONS(83),
    [sym__newline] = ACTIONS(83),
    [sym_label_identifier] = ACTIONS(81),
  },
  [13] = {
    [sym_else_block] = STATE(7),
    [aux_sym_if_block_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(64),
    [anon_sym_IF] = ACTIONS(66),
    [anon_sym_if] = ACTIONS(66),
    [aux_sym_else_block_token1] = ACTIONS(62),
    [anon_sym_AMP] = ACTIONS(66),
    [anon_sym_GLOBAL] = ACTIONS(66),
    [anon_sym_global] = ACTIONS(66),
    [anon_sym_LOCAL] = ACTIONS(66),
    [anon_sym_local] = ACTIONS(66),
    [anon_sym_PRIVATE] = ACTIONS(66),
    [anon_sym_private] = ACTIONS(66),
    [anon_sym_STOP] = ACTIONS(66),
    [anon_sym_stop] = ACTIONS(66),
    [anon_sym_CONTinue] = ACTIONS(66),
    [anon_sym_continue] = ACTIONS(66),
    [anon_sym_CONT] = ACTIONS(66),
    [anon_sym_cont] = ACTIONS(66),
    [aux_sym_command_token1] = ACTIONS(66),
    [sym__newline] = ACTIONS(66),
    [sym_label_identifier] = ACTIONS(64),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(88),
    [anon_sym_IF] = ACTIONS(90),
    [anon_sym_if] = ACTIONS(90),
    [aux_sym_else_block_token1] = ACTIONS(90),
    [anon_sym_AMP] = ACTIONS(90),
    [anon_sym_RPAREN] = ACTIONS(92),
    [anon_sym_GLOBAL] = ACTIONS(90),
    [anon_sym_global] = ACTIONS(90),
    [anon_sym_LOCAL] = ACTIONS(90),
    [anon_sym_local] = ACTIONS(90),
    [anon_sym_PRIVATE] = ACTIONS(90),
    [anon_sym_private] = ACTIONS(90),
    [anon_sym_STOP] = ACTIONS(90),
    [anon_sym_stop] = ACTIONS(90),
    [anon_sym_CONTinue] = ACTIONS(90),
    [anon_sym_continue] = ACTIONS(90),
    [anon_sym_CONT] = ACTIONS(90),
    [anon_sym_cont] = ACTIONS(90),
    [aux_sym_command_token1] = ACTIONS(90),
    [sym__newline] = ACTIONS(90),
    [sym_label_identifier] = ACTIONS(88),
  },
  [15] = {
    [sym__macro] = STATE(16),
    [aux_sym_macro_declaration_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(75),
    [anon_sym_IF] = ACTIONS(77),
    [anon_sym_if] = ACTIONS(77),
    [anon_sym_AMP] = ACTIONS(7),
    [anon_sym_GLOBAL] = ACTIONS(77),
    [anon_sym_global] = ACTIONS(77),
    [anon_sym_LOCAL] = ACTIONS(77),
    [anon_sym_local] = ACTIONS(77),
    [anon_sym_PRIVATE] = ACTIONS(77),
    [anon_sym_private] = ACTIONS(77),
    [anon_sym_STOP] = ACTIONS(77),
    [anon_sym_stop] = ACTIONS(77),
    [anon_sym_CONTinue] = ACTIONS(77),
    [anon_sym_continue] = ACTIONS(77),
    [anon_sym_CONT] = ACTIONS(77),
    [anon_sym_cont] = ACTIONS(77),
    [aux_sym_command_token1] = ACTIONS(77),
    [sym__newline] = ACTIONS(75),
    [sym_label_identifier] = ACTIONS(75),
  },
  [16] = {
    [sym__macro] = STATE(16),
    [aux_sym_macro_declaration_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(68),
    [anon_sym_IF] = ACTIONS(70),
    [anon_sym_if] = ACTIONS(70),
    [anon_sym_AMP] = ACTIONS(94),
    [anon_sym_GLOBAL] = ACTIONS(70),
    [anon_sym_global] = ACTIONS(70),
    [anon_sym_LOCAL] = ACTIONS(70),
    [anon_sym_local] = ACTIONS(70),
    [anon_sym_PRIVATE] = ACTIONS(70),
    [anon_sym_private] = ACTIONS(70),
    [anon_sym_STOP] = ACTIONS(70),
    [anon_sym_stop] = ACTIONS(70),
    [anon_sym_CONTinue] = ACTIONS(70),
    [anon_sym_continue] = ACTIONS(70),
    [anon_sym_CONT] = ACTIONS(70),
    [anon_sym_cont] = ACTIONS(70),
    [aux_sym_command_token1] = ACTIONS(70),
    [sym__newline] = ACTIONS(68),
    [sym_label_identifier] = ACTIONS(68),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(97),
    [anon_sym_IF] = ACTIONS(99),
    [anon_sym_if] = ACTIONS(99),
    [aux_sym_else_block_token1] = ACTIONS(99),
    [anon_sym_AMP] = ACTIONS(99),
    [anon_sym_RPAREN] = ACTIONS(101),
    [anon_sym_GLOBAL] = ACTIONS(99),
    [anon_sym_global] = ACTIONS(99),
    [anon_sym_LOCAL] = ACTIONS(99),
    [anon_sym_local] = ACTIONS(99),
    [anon_sym_PRIVATE] = ACTIONS(99),
    [anon_sym_private] = ACTIONS(99),
    [anon_sym_STOP] = ACTIONS(99),
    [anon_sym_stop] = ACTIONS(99),
    [anon_sym_CONTinue] = ACTIONS(99),
    [anon_sym_continue] = ACTIONS(99),
    [anon_sym_CONT] = ACTIONS(99),
    [anon_sym_cont] = ACTIONS(99),
    [aux_sym_command_token1] = ACTIONS(99),
    [sym__newline] = ACTIONS(99),
    [sym_label_identifier] = ACTIONS(97),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(103),
    [anon_sym_IF] = ACTIONS(105),
    [anon_sym_if] = ACTIONS(105),
    [aux_sym_else_block_token1] = ACTIONS(105),
    [anon_sym_AMP] = ACTIONS(105),
    [anon_sym_GLOBAL] = ACTIONS(105),
    [anon_sym_global] = ACTIONS(105),
    [anon_sym_LOCAL] = ACTIONS(105),
    [anon_sym_local] = ACTIONS(105),
    [anon_sym_PRIVATE] = ACTIONS(105),
    [anon_sym_private] = ACTIONS(105),
    [anon_sym_STOP] = ACTIONS(105),
    [anon_sym_stop] = ACTIONS(105),
    [anon_sym_CONTinue] = ACTIONS(105),
    [anon_sym_continue] = ACTIONS(105),
    [anon_sym_CONT] = ACTIONS(105),
    [anon_sym_cont] = ACTIONS(105),
    [aux_sym_command_token1] = ACTIONS(105),
    [sym__newline] = ACTIONS(105),
    [sym_label_identifier] = ACTIONS(103),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(88),
    [anon_sym_IF] = ACTIONS(90),
    [anon_sym_if] = ACTIONS(90),
    [anon_sym_AMP] = ACTIONS(90),
    [anon_sym_RPAREN] = ACTIONS(107),
    [anon_sym_GLOBAL] = ACTIONS(90),
    [anon_sym_global] = ACTIONS(90),
    [anon_sym_LOCAL] = ACTIONS(90),
    [anon_sym_local] = ACTIONS(90),
    [anon_sym_PRIVATE] = ACTIONS(90),
    [anon_sym_private] = ACTIONS(90),
    [anon_sym_STOP] = ACTIONS(90),
    [anon_sym_stop] = ACTIONS(90),
    [anon_sym_CONTinue] = ACTIONS(90),
    [anon_sym_continue] = ACTIONS(90),
    [anon_sym_CONT] = ACTIONS(90),
    [anon_sym_cont] = ACTIONS(90),
    [aux_sym_command_token1] = ACTIONS(90),
    [sym__newline] = ACTIONS(88),
    [sym_label_identifier] = ACTIONS(88),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(97),
    [anon_sym_IF] = ACTIONS(99),
    [anon_sym_if] = ACTIONS(99),
    [anon_sym_AMP] = ACTIONS(99),
    [anon_sym_RPAREN] = ACTIONS(109),
    [anon_sym_GLOBAL] = ACTIONS(99),
    [anon_sym_global] = ACTIONS(99),
    [anon_sym_LOCAL] = ACTIONS(99),
    [anon_sym_local] = ACTIONS(99),
    [anon_sym_PRIVATE] = ACTIONS(99),
    [anon_sym_private] = ACTIONS(99),
    [anon_sym_STOP] = ACTIONS(99),
    [anon_sym_stop] = ACTIONS(99),
    [anon_sym_CONTinue] = ACTIONS(99),
    [anon_sym_continue] = ACTIONS(99),
    [anon_sym_CONT] = ACTIONS(99),
    [anon_sym_cont] = ACTIONS(99),
    [aux_sym_command_token1] = ACTIONS(99),
    [sym__newline] = ACTIONS(97),
    [sym_label_identifier] = ACTIONS(97),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(97),
    [anon_sym_IF] = ACTIONS(99),
    [anon_sym_if] = ACTIONS(99),
    [aux_sym_else_block_token1] = ACTIONS(99),
    [anon_sym_AMP] = ACTIONS(99),
    [anon_sym_GLOBAL] = ACTIONS(99),
    [anon_sym_global] = ACTIONS(99),
    [anon_sym_LOCAL] = ACTIONS(99),
    [anon_sym_local] = ACTIONS(99),
    [anon_sym_PRIVATE] = ACTIONS(99),
    [anon_sym_private] = ACTIONS(99),
    [anon_sym_STOP] = ACTIONS(99),
    [anon_sym_stop] = ACTIONS(99),
    [anon_sym_CONTinue] = ACTIONS(99),
    [anon_sym_continue] = ACTIONS(99),
    [anon_sym_CONT] = ACTIONS(99),
    [anon_sym_cont] = ACTIONS(99),
    [aux_sym_command_token1] = ACTIONS(99),
    [sym__newline] = ACTIONS(99),
    [sym_label_identifier] = ACTIONS(97),
  },
  [22] = {
    [ts_builtin_sym_end] = ACTIONS(111),
    [anon_sym_IF] = ACTIONS(113),
    [anon_sym_if] = ACTIONS(113),
    [aux_sym_else_block_token1] = ACTIONS(113),
    [anon_sym_AMP] = ACTIONS(113),
    [anon_sym_GLOBAL] = ACTIONS(113),
    [anon_sym_global] = ACTIONS(113),
    [anon_sym_LOCAL] = ACTIONS(113),
    [anon_sym_local] = ACTIONS(113),
    [anon_sym_PRIVATE] = ACTIONS(113),
    [anon_sym_private] = ACTIONS(113),
    [anon_sym_STOP] = ACTIONS(113),
    [anon_sym_stop] = ACTIONS(113),
    [anon_sym_CONTinue] = ACTIONS(113),
    [anon_sym_continue] = ACTIONS(113),
    [anon_sym_CONT] = ACTIONS(113),
    [anon_sym_cont] = ACTIONS(113),
    [aux_sym_command_token1] = ACTIONS(113),
    [sym__newline] = ACTIONS(113),
    [sym_label_identifier] = ACTIONS(111),
  },
  [23] = {
    [ts_builtin_sym_end] = ACTIONS(115),
    [anon_sym_IF] = ACTIONS(117),
    [anon_sym_if] = ACTIONS(117),
    [aux_sym_else_block_token1] = ACTIONS(117),
    [anon_sym_AMP] = ACTIONS(117),
    [anon_sym_GLOBAL] = ACTIONS(117),
    [anon_sym_global] = ACTIONS(117),
    [anon_sym_LOCAL] = ACTIONS(117),
    [anon_sym_local] = ACTIONS(117),
    [anon_sym_PRIVATE] = ACTIONS(117),
    [anon_sym_private] = ACTIONS(117),
    [anon_sym_STOP] = ACTIONS(117),
    [anon_sym_stop] = ACTIONS(117),
    [anon_sym_CONTinue] = ACTIONS(117),
    [anon_sym_continue] = ACTIONS(117),
    [anon_sym_CONT] = ACTIONS(117),
    [anon_sym_cont] = ACTIONS(117),
    [aux_sym_command_token1] = ACTIONS(117),
    [sym__newline] = ACTIONS(117),
    [sym_label_identifier] = ACTIONS(115),
  },
  [24] = {
    [ts_builtin_sym_end] = ACTIONS(119),
    [anon_sym_IF] = ACTIONS(121),
    [anon_sym_if] = ACTIONS(121),
    [aux_sym_else_block_token1] = ACTIONS(121),
    [anon_sym_AMP] = ACTIONS(121),
    [anon_sym_GLOBAL] = ACTIONS(121),
    [anon_sym_global] = ACTIONS(121),
    [anon_sym_LOCAL] = ACTIONS(121),
    [anon_sym_local] = ACTIONS(121),
    [anon_sym_PRIVATE] = ACTIONS(121),
    [anon_sym_private] = ACTIONS(121),
    [anon_sym_STOP] = ACTIONS(121),
    [anon_sym_stop] = ACTIONS(121),
    [anon_sym_CONTinue] = ACTIONS(121),
    [anon_sym_continue] = ACTIONS(121),
    [anon_sym_CONT] = ACTIONS(121),
    [anon_sym_cont] = ACTIONS(121),
    [aux_sym_command_token1] = ACTIONS(121),
    [sym__newline] = ACTIONS(121),
    [sym_label_identifier] = ACTIONS(119),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(123),
    [anon_sym_IF] = ACTIONS(125),
    [anon_sym_if] = ACTIONS(125),
    [aux_sym_else_block_token1] = ACTIONS(125),
    [anon_sym_AMP] = ACTIONS(125),
    [anon_sym_GLOBAL] = ACTIONS(125),
    [anon_sym_global] = ACTIONS(125),
    [anon_sym_LOCAL] = ACTIONS(125),
    [anon_sym_local] = ACTIONS(125),
    [anon_sym_PRIVATE] = ACTIONS(125),
    [anon_sym_private] = ACTIONS(125),
    [anon_sym_STOP] = ACTIONS(125),
    [anon_sym_stop] = ACTIONS(125),
    [anon_sym_CONTinue] = ACTIONS(125),
    [anon_sym_continue] = ACTIONS(125),
    [anon_sym_CONT] = ACTIONS(125),
    [anon_sym_cont] = ACTIONS(125),
    [aux_sym_command_token1] = ACTIONS(125),
    [sym__newline] = ACTIONS(125),
    [sym_label_identifier] = ACTIONS(123),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(119), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(121), 16,
      anon_sym_IF,
      anon_sym_if,
      anon_sym_AMP,
      anon_sym_GLOBAL,
      anon_sym_global,
      anon_sym_LOCAL,
      anon_sym_local,
      anon_sym_PRIVATE,
      anon_sym_private,
      anon_sym_STOP,
      anon_sym_stop,
      anon_sym_CONTinue,
      anon_sym_continue,
      anon_sym_CONT,
      anon_sym_cont,
      aux_sym_command_token1,
  [24] = 2,
    ACTIONS(123), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(125), 16,
      anon_sym_IF,
      anon_sym_if,
      anon_sym_AMP,
      anon_sym_GLOBAL,
      anon_sym_global,
      anon_sym_LOCAL,
      anon_sym_local,
      anon_sym_PRIVATE,
      anon_sym_private,
      anon_sym_STOP,
      anon_sym_stop,
      anon_sym_CONTinue,
      anon_sym_continue,
      anon_sym_CONT,
      anon_sym_cont,
      aux_sym_command_token1,
  [48] = 2,
    ACTIONS(97), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(99), 16,
      anon_sym_IF,
      anon_sym_if,
      anon_sym_AMP,
      anon_sym_GLOBAL,
      anon_sym_global,
      anon_sym_LOCAL,
      anon_sym_local,
      anon_sym_PRIVATE,
      anon_sym_private,
      anon_sym_STOP,
      anon_sym_stop,
      anon_sym_CONTinue,
      anon_sym_continue,
      anon_sym_CONT,
      anon_sym_cont,
      aux_sym_command_token1,
  [72] = 2,
    ACTIONS(103), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(105), 16,
      anon_sym_IF,
      anon_sym_if,
      anon_sym_AMP,
      anon_sym_GLOBAL,
      anon_sym_global,
      anon_sym_LOCAL,
      anon_sym_local,
      anon_sym_PRIVATE,
      anon_sym_private,
      anon_sym_STOP,
      anon_sym_stop,
      anon_sym_CONTinue,
      anon_sym_continue,
      anon_sym_CONT,
      anon_sym_cont,
      aux_sym_command_token1,
  [96] = 2,
    ACTIONS(127), 3,
      sym_label_identifier,
      ts_builtin_sym_end,
      sym__newline,
    ACTIONS(129), 16,
      anon_sym_IF,
      anon_sym_if,
      anon_sym_AMP,
      anon_sym_GLOBAL,
      anon_sym_global,
      anon_sym_LOCAL,
      anon_sym_local,
      anon_sym_PRIVATE,
      anon_sym_private,
      anon_sym_STOP,
      anon_sym_stop,
      anon_sym_CONTinue,
      anon_sym_continue,
      anon_sym_CONT,
      anon_sym_cont,
      aux_sym_command_token1,
  [120] = 3,
    ACTIONS(133), 1,
      sym__newline,
    STATE(22), 1,
      sym_if_block,
    ACTIONS(131), 2,
      anon_sym_IF,
      anon_sym_if,
  [131] = 2,
    ACTIONS(135), 1,
      anon_sym_AMP,
    STATE(15), 2,
      sym__macro,
      aux_sym_macro_declaration_repeat1,
  [139] = 2,
    ACTIONS(48), 1,
      anon_sym_AMP,
    STATE(11), 2,
      sym__macro,
      aux_sym_macro_declaration_repeat1,
  [147] = 2,
    ACTIONS(137), 1,
      anon_sym_AMP,
    STATE(47), 2,
      sym__expression,
      sym__macro,
  [155] = 2,
    ACTIONS(137), 1,
      anon_sym_AMP,
    STATE(51), 2,
      sym__expression,
      sym__macro,
  [163] = 2,
    ACTIONS(97), 1,
      sym__newline,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
  [170] = 2,
    ACTIONS(88), 1,
      sym__newline,
    ACTIONS(141), 1,
      anon_sym_RPAREN,
  [177] = 2,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(145), 1,
      anon_sym_LPAREN,
  [184] = 2,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      anon_sym_LPAREN,
  [191] = 2,
    ACTIONS(151), 1,
      sym_identifier,
    ACTIONS(153), 1,
      anon_sym_LPAREN,
  [198] = 1,
    ACTIONS(97), 1,
      sym__newline,
  [202] = 1,
    ACTIONS(155), 1,
      ts_builtin_sym_end,
  [206] = 1,
    ACTIONS(157), 1,
      sym__newline,
  [210] = 1,
    ACTIONS(103), 1,
      sym__newline,
  [214] = 1,
    ACTIONS(159), 1,
      sym_identifier,
  [218] = 1,
    ACTIONS(161), 1,
      anon_sym_COLON,
  [222] = 1,
    ACTIONS(163), 1,
      sym__newline,
  [226] = 1,
    ACTIONS(165), 1,
      sym__newline,
  [230] = 1,
    ACTIONS(167), 1,
      sym_identifier,
  [234] = 1,
    ACTIONS(169), 1,
      sym_identifier,
  [238] = 1,
    ACTIONS(171), 1,
      sym__newline,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(26)] = 0,
  [SMALL_STATE(27)] = 24,
  [SMALL_STATE(28)] = 48,
  [SMALL_STATE(29)] = 72,
  [SMALL_STATE(30)] = 96,
  [SMALL_STATE(31)] = 120,
  [SMALL_STATE(32)] = 131,
  [SMALL_STATE(33)] = 139,
  [SMALL_STATE(34)] = 147,
  [SMALL_STATE(35)] = 155,
  [SMALL_STATE(36)] = 163,
  [SMALL_STATE(37)] = 170,
  [SMALL_STATE(38)] = 177,
  [SMALL_STATE(39)] = 184,
  [SMALL_STATE(40)] = 191,
  [SMALL_STATE(41)] = 198,
  [SMALL_STATE(42)] = 202,
  [SMALL_STATE(43)] = 206,
  [SMALL_STATE(44)] = 210,
  [SMALL_STATE(45)] = 214,
  [SMALL_STATE(46)] = 218,
  [SMALL_STATE(47)] = 222,
  [SMALL_STATE(48)] = 226,
  [SMALL_STATE(49)] = 230,
  [SMALL_STATE(50)] = 234,
  [SMALL_STATE(51)] = 238,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(34),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(38),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(32),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(26),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(43),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(3),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(46),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 5),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_block, 5),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 4),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_block, 4),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macro_declaration_repeat1, 2),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_macro_declaration_repeat1, 2),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_macro_declaration_repeat1, 2), SHIFT_REPEAT(40),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro_declaration, 2),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro_declaration, 2),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_block_repeat1, 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_block_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_if_block_repeat1, 2), SHIFT_REPEAT(31),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 2),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 2),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_macro_declaration_repeat1, 2), SHIFT_REPEAT(38),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 3),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 3),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 4),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 4),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_block, 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_block, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_block, 3),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_block, 3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__flow_command, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__flow_command, 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [155] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
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
