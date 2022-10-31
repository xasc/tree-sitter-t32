/*
   Copyright (c) 2022 Christoph Sax

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

const PREC = {
  logical_or: 10,
  logical_xor: 11,
  logical_and: 12,
  bitwise_or: 13,
  bitwise_xor: 14,
  bitwise_and: 15,
  relational: 16,
  add_sub: 17,
  mul_div_mod: 18,
  shift: 19,
  pointer: 20,
  cast: 21,
  unary: 22,
  range: 23
}

const RE_BIN_HEX_NUMBER = [
  /0y[0-9]+/,  // Binary
  // /[0-9]+\.?/,  // Decimal
  /0[xX][0-9a-fA-F]+/,  // Hexadecimal
]


module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.label_identifier,
    $._and_operator_pre_hook,  // Check for presence of macros after operator
    $._decimal_number,
    $._decimal_number_pre_hook,  // Check for presence of range operator after number
    $._path,  // Unquoted path literals
    '&&',
    '&',
  ],

  conflicts: $ => [
    [$._binary_expression, $._and_expression],
    [$._expression, $._function_identifier],
    [$._expression, $.c_type_declaration]
  ],

  extras: $ => [
    $._line_continuation
  ],

  word: $ => $.identifier,

  rules: {
    script: $ => repeat($._top_level),

    _top_level: $ => choice(
      $._statement,
      $._block,
      $._terminator
    ),

    _block: $ => prec.right(seq(
      seq(
        /\((&[+-]?)?/,
        $._terminator
      ),
      repeat($._statement),
      seq(
        ')',
        $._terminator
      ),
    )),

    _statement: $ => choice(
      $.recursive_macro_expansion,
      alias($.macro_assignment_expression, $.assignment_expression),
      $.if_block,
      $.repeat_block,
      $.while_block,
      $.command_expression,
      $.labeled_expression
    ),

    labeled_expression: $ => seq(
      $._label,
      repeat($._blank),
      choice(
        $._statement,
        $._terminator
      )
    ),

    if_block: $ => prec.right(seq(
      longAndShortForm('IF'),
      repeat1($._blank),
      field('condition', $._practice_expression),
      $._terminator,
      choice(
        $._statement,
        $._block
      ),
      repeat($.else_block)
    )),

    else_block: $ => seq(
      longAndShortForm('ELSE'),
      choice(
        seq(
          $._terminator,
          choice(
            $._statement,
            $._block
          )
        ),
        seq(
          repeat1($._blank),
          $.if_block
        )
      ),
    ),

    while_block: $ => seq(
      longAndShortForm('WHILE'),
      repeat1($._blank),
      field('condition', $._practice_expression),
      $._terminator,
      choice(
        $._statement,
        $._block
      ),
    ),

    repeat_block: $ => prec.right(seq(
      longAndShortForm('RePeaT'),
      choice(
        seq(
          repeat1($._blank),
          field('condition', $._practice_expression),
          choice(
            seq(
              repeat1($._blank),
              $.identifier
            ),
            seq(
              $._terminator,
              choice(
                $._statement,
                $._block
              )
            )
          )
        ),
        seq(
          $._terminator,
          choice(
            $._statement,
            $._block
          ),
          optional(seq(
            longAndShortForm('WHILE'),
            repeat1($._blank),
            field('condition', $._practice_expression),
            $._terminator
          ))
        )
      )
    )),

    _practice_expression: $ => choice(
      $._expression,
      $.practice_function,
    ),

    _hll_expression: $ => choice(
      $._expression,
      $.c_subscript_expression
    ),

    _expression: $ => choice(
      $.unary_expression,
      $.binary_expression,
      $._macro,
      $._internal_c_variable,
      $.c_pointer_expression,
      $.c_cast_expression,
      $.literal,
      $.identifier,
      $._parenthesized_expression
    ),

    _parenthesized_expression: $ => choice(
      seq(
        '(',
        $._practice_expression,
        ')'
      ),
      seq(
        '{',
        $._practice_expression,
        '}'
      )
    ),

    macro_assignment_expression: $ => seq(
      field('left', $._macro),
      repeat($._blank),
      field('operator', '='),
      repeat($._blank),
      field('right', $._practice_expression)
    ),

   unary_expression: $ => prec.left(PREC.unary, seq(
      field('operator', choice(
        '+', '-', '~', '!'
      )),
      field('argument', $._practice_expression)
    )),

    binary_expression: $ => choice(
      $._binary_expression,
      $._and_expression
    ),

    // Address-of operator is treated as PRACTICE macro
    c_pointer_expression: $ => prec.left(PREC.pointer, seq(
      field('operator', '*'),
      field('argument', $._practice_expression)
    )),

    c_cast_expression: $ => prec(PREC.cast, seq(
      '(',
      field('type', alias($.c_type_declaration, $.identifier)),
      ')',
      field('value', $._practice_expression)
    )),

    c_call_expression: $ => seq(
      field('function', $._expression),
      field('arguments', $.argument_list)
      ),

    _binary_expression: $ => {
      const operators = [
        ['^^', PREC.logical_xor],
        ['||', PREC.logical_or],
        ['+', PREC.add_sub],
        ['-', PREC.add_sub],
        ['*', PREC.mul_div_mod],
        ['/', PREC.mul_div_mod],
        ['%', PREC.mul_div_mod],
        ['|', PREC.bitwise_or],
        ['^', PREC.bitwise_xor],
        ['==', PREC.relational],
        ['!=', PREC.relational],
        ['>', PREC.relational],
        ['>=', PREC.relational],
        ['<=', PREC.relational],
        ['<', PREC.relational],
        ['<<', PREC.shift],
        ['>>', PREC.shift],
        ['..', PREC.range],
        ['--', PREC.range],
        ['++', PREC.range]
      ];

      return choice(...operators.map(([op, pre]) => {
        return prec.left(pre, seq(
          field('left', $._practice_expression),
          field('operator', op),
          field('right', $._practice_expression)
        ))
      }));
    },

    _and_expression: $ => {
      const operators = [
        ['&&', PREC.logical_and],
        ['&', PREC.bitwise_and]
      ];

      return choice(...operators.map(([op, pre]) => {
        return prec.left(pre, seq(
          field('left', $._practice_expression),
          $._and_operator_pre_hook,
          field('operator', op),
          field('right', $._practice_expression)
        ))
      }));
    },

    assignment_expression: $ => prec.left(seq(
        field('left', $._practice_expression),
        repeat($._blank),
        field('operator', '='),
        repeat($._blank),
        field('right', $._practice_expression)
    )),

    _label: $ => seq(
      field('label', alias($.label_identifier, $.identifier)),
      ':'
    ),

    _macro_definition: $ => seq(
      field('command', alias($.macro_definition_command, $.identifier)),
      repeat1(seq(
        repeat1($._blank),
        field('macro', $._macro)
      )),
    ),

    _macro: $ => prec.left(choice(
      seq(
        '&',
        $.identifier
      ),
      seq(
        '&',
        '(',
        $.identifier,
        ')'
      ),
      seq(
        '&',
        '{',
        $.identifier,
        '}'
      )
    )),

    recursive_macro_expansion: $ => prec.left(seq(
      '&&',
      optional('('),
      $.identifier,
      optional(')')
    )),

    _var_command: $ => choice(
      seq(
        field('command', alias(seq(
          longAndShortForm('Var'),
          '.',
          choice(
            longAndShortForm('NEWLOCAL'),
            longAndShortForm('NEWGLOBAL')
          )
        ), $.identifier)),
        repeat1($._blank),
        alias($._type, $.literal),
        repeat1($._blank),
        field('variable', $._internal_c_variable)
      ),
      seq(
        field('command', alias(seq(
          longAndShortForm('Var'),
          optional(seq(
            '.',
            choice(
              longAndShortForm('set'),
              longAndShortForm('ASSIGN'),
              longAndShortForm('Call')
            )
          ))
        ), $.identifier)),
        field('arguments', alias($._var_call_command_arguments, $.argument_list))
      ),
      seq(
        field('command', alias(seq(
          longAndShortForm('Var'),
          repeat1(seq(
            '.',
            alias($.identifier, 'subcommand')
          ))
        ), $.identifier)),
        field('arguments', optional(alias($._var_command_arguments, $.argument_list)))
      )
    ),

    _var_call_command_arguments: $ => seq(
      repeat1($._blank),
      optional(seq(
        alias($._command_format, $.identifier),
        repeat1($._blank),
      )),
      $._var_call_command_argument
    ),

    // Commas as argument separators do not seem viable for
    // HLL expressions
    _var_command_arguments: $ => seq(
      repeat1($._blank),
      choice(
        ',',
        seq(
          ',',
          $._command_argument,
          repeat(seq(
            repeat1($._blank),
            $._command_argument
          )),
          repeat($._blank)
        ),
        seq(
          $._command_argument,
          repeat(seq(
            repeat1($._blank),
            $._command_argument
          )),
          repeat($._blank)
        )
      )
    ),

    _var_call_command_argument: $ => choice(
      $._hll_expression,
      $.assignment_expression,
      $.c_call_expression,
      $._command_option,
      alias($._command_format, $.identifier),
    ),

    c_subscript_expression: $ => seq(
      field('argument', $._hll_expression),
      seq(
        '[',
        field('index', $._hll_expression),
        ']'
      )
    ),

    _internal_c_variable: $ => seq(
      '\\',
      $.identifier,
      optional(token(seq(
        '[',
        /[0-9]+/,
        ']'
      )))
    ),

    macro_definition_command: $ => token(choice(
      longAndShortForm('GLOBAL'),
      longAndShortForm('LOCAL'),
      longAndShortForm('PRIVATE'),
      longAndShortForm('PARAMETERS')
    )),

    command_expression: $ => seq(
      optional(/(::)*B::/),
      choice(
        seq(
          choice(
            $._macro_definition,
            $._var_command
          ),
          $._terminator
        ),
        seq(
          field('command', alias($._command_identifier, $.identifier)),
          field('arguments', optional(alias($._command_arguments, $.argument_list))),
          $._terminator
        )
      )
    ),

    _command_identifier: $ => seq(
      alias($.identifier, 'command'),
      repeat(seq(
        '.',
        alias($.identifier, 'subcommand')
      ))
    ),

    _command_arguments: $ => seq(
      repeat1($._blank),
      choice(
        ',',
        seq(
          ',',
          $._command_argument,
          repeat(seq(
            repeat1($._command_argument_separator),
            $._command_argument
          )),
          repeat($._command_argument_separator)
        ),
        seq(
          $._command_argument,
          repeat(seq(
            repeat1($._command_argument_separator),
            $._command_argument
          )),
          repeat($._command_argument_separator)
        )
      )
    ),

    _command_argument: $ => choice(
      $._practice_expression,
      $._command_option,
      alias($._command_format, $.identifier),
      alias($._path, $.literal)
    ),

    _command_argument_separator: $ => choice(
      $._blank,
      ',',
    ),

    _command_option: $ => seq(
      '/',
      $.identifier
    ),

    _command_format: $ => seq(
      '%',
      alias($.identifier, 'format'),
      repeat(seq(
        '.',
        alias($.identifier, 'subformat')
      ))
    ),

    practice_function: $ => seq(
      field('function', alias($._function_identifier, $.identifier)),
      field('arguments', $.argument_list)
    ),

    _function_identifier: $ => seq(
      alias($.identifier, 'function'),
      repeat(seq(
        '.',
        alias($.identifier, 'subfunction')
      ))
    ),

    argument_list: $ => seq(
      '(',
      optional(seq(
        $._practice_expression,
        repeat(seq(
          repeat($._blank),
          ',',
          repeat($._blank),
          $._practice_expression
        ))
      )),
      ')'
    ),

    c_type_declaration: $ => seq(
      choice(
        $._c_base_type_declaration,
        $._c_compound_type_declaration,
        $.identifier
      ),
      repeat(seq(
        repeat($._blank),
        choice(
          '*',
          seq(
            '[',
            $._practice_expression,
            ']'
          )
        )
      ))
    ),

    _c_compound_type_declaration: $ => seq(
      choice(
        'struct',
        'union',
        'enum',
      ),
      repeat1($._blank),
      $.identifier
    ),

    _c_base_type_declaration: $ => choice(
      seq(
        optional(seq(
          choice(
            'signed',
            'unsigned'
          ),
          repeat1($._blank)
        )),
        choice(
          'char',
          'short',
          'int',
          'long',
          'long long',
          ...[8, 16, 32, 64].map(w => `int${w}_t`),
          ...[8, 16, 32, 64].map(w => `uint${w}_t`)
        ),
      ),
      'float',
      'double',
      'long double',
      'bool'
    ),

    literal: $ => choice(
      $._integer,
      $._bitmask,
      $._float,
      $._address,
      $._time,
      $._string,
      $._character,
      $._symbol,
      $._file_dialog,
      $._file_handle
    ),

    _integer: $ => choice(
      ...RE_BIN_HEX_NUMBER,
      seq(
        $._decimal_number_pre_hook,
        $._decimal_number
      )
    ),

    _float: $ => /[0-9]+\.[0-9]+(e[-+][0-9]+)?/,

    _bitmask: $ => choice(
      /0y[0-9xX]+/,  // Bitmask
      /0x[0-9a-fA-FxX]+/,  // Hexmask
    ),

    _address: $ => {
      const alphanum = '[a-zA-Z0-9]+'

      return seq(
        new RegExp(alphanum + ':'),  // Access class
        repeat(new RegExp(alphanum + '[.]?:+')),  // Machine identifier:::Memory space identifier::Memory segment identifier:
        choice(
          ...RE_BIN_HEX_NUMBER,
          seq(
            $._decimal_number_pre_hook,
            $._decimal_number
          )
        )
      )
    },

    _string: $ => seq(
      '"',
      repeat(choice(
        /[^"]+/,
        /""/,  // Escape sequence
      )),
      '"'
    ),

    _character: $ => seq(
      "'",
      /[^\n]/,
      "'"
    ),

    // Module names with single backslash are treated as internal c-style variables
    _symbol: $ => token(choice(
      /\\\\\\([\w_]+|`[^`\n]+`)\\\\([\w_]*|`[^`\n]+`)\\([\w_]*|`[^`\n]+`)\\([\w_]+|`[^`\n]+`)(\\([\w_]+|`[^`\n]+`))*/,  // Includes machine name
      /((\\\\([\w_]+|`[^`\n]+`))?\\([\w_]*|`[^`\n]+`)\\)?`[^`\n]+`(\\([\w_]+|`[^`\n]+`))*/,  // Quoted function name only
      /(\\\\([\w_]+|`[^`\n]+`))?\\([\w_]*|`[^`\n]+`)\\[\w_]+(\\([\w_]+|`[^`\n]+`))*/,  // Module name with unquoted function name
      /[\\]{2,3}([\w_]+|`[^`\n]+`)/,  // Machine or program name
      /\\`[^`\n]+`/,  // Quoted module name only
    )),

    _time: $ => /[0-9]+\.?[0-9]*[mnu]*s/,

    _file_dialog: $ => '*',

    _file_handle: $ => /#[0-9]+/,

    _type: $ => seq(
      alias($.identifier, ''),
      repeat(/\[[0-9]+\]/)
    ),

    identifier: $ => /[a-zA-Z_][\w_]*/,

    comment: $ => seq(
      choice(
        ';',
        '//'
      ),
      repeat(/\\\r?\n|[^\n]/)
    ),

    _terminator: $ => prec.right(seq(
      optional($.comment),
      /(\s*[\r\n]+\s*)+/
    )),

    _line_continuation: $ => /\\\r?\n/,

    _blank: $ => /[ \t]/
  }
})

function longAndShortForm(keyword, aliasAsWord = true) {
  // Capture short form: RePeaT -> [rR][pP][tT]
  const short = keyword
    .split('')
    .map(l => l === l.toUpperCase() ? `[${l.toLowerCase()}${l}]` : '')
    .join('')

  // Capture long form: RePeaT -> [rR][eE][pP][eE][aA][tT]
  const long = keyword
    .split('')
    .map(l => `[${l.toLowerCase()}${l.toUpperCase()}]`)
    .join('')

  let result = new RegExp([short, long].join('|'))
  if (!short) {
    result = new RegExp(long)
  }

  if (aliasAsWord) {
    result = alias(result, keyword)
  }
  return result
}
