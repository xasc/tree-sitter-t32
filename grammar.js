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
  unary: 20,
  range: 21,
  practice_function: 22
}

const RE_STRING_BODY = /[^"\n\\]+/

const RE_INTEGERS = [
  /0y[0-9]+/,  // Binary
  /[0-9]+\.?/,  // Decimal
  /0x[0-9a-fA-F]+/,  // Hexadecimal
]


module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.label_identifier,
    $._and_operator_pre_hook,  // Check for presence of macros after operator
    '&&',
    '&',
  ],

  conflicts: $ => [
    [$._binary_expression, $._and_expression],
    [$._command_arguments, $._command_arguments]
  ],

  extras: $ => [
    /\\\r?\n/
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
      $.assignment_expression,
      $.if_block,
      $.repeat_block,
      $.while_block,
      $.command_expression,
      $.labeled_command
    ),

    labeled_command: $ => seq(
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
      field('condition', $._expression),
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
      field('condition', $._expression),
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
          field('condition', $._expression),
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
            field('condition', $._expression),
            $._terminator
          ))
        )
      )
    )),

    _expression: $ => choice(
      $.unary_expression,
      $.binary_expression,
      $.practice_function,
      $._macro,
      $.literal,
      $.identifier,
      $.identifier,
      $._go_command_expression,
      $._parenthesized_expression
    ),

    _parenthesized_expression: $ => choice(
      seq(
        '(',
        $._expression,
        ')'
      ),
      seq(
        '{',
        $._expression,
        '}'
      )
    ),

    assignment_expression: $ => seq(
      field('left', $._macro),
      repeat($._blank),
      field('operator', '='),
      repeat($._blank),
      field('right', $._expression)
    ),

   unary_expression: $ => prec.left(PREC.unary, seq(
      field('operator', choice(
        '+', '-', '~', '!'
      )),
      field('argument', $._expression)
    )),

    binary_expression: $ => choice(
      $._binary_expression,
      $._and_expression
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
        [/\.\.|\-\-|\+\+/, PREC.range]
      ];

      return choice(...operators.map(([op, pre]) => {
        return prec.left(pre, seq(
          field('left', $._expression),
          field('operator', op),
          field('right', $._expression)
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
          field('left', $._expression),
          $._and_operator_pre_hook,
          field('operator', op),
          field('right', $._expression)
        ))
      }));
    },

    _label: $ => seq(
      field('label', alias($.label_identifier, $.identifier)),
      ':'
    ),

    _macro_declaration: $ => seq(
      $._declaration_command,
      repeat1(seq(
        repeat1($._blank),
        $._macro
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

    _declaration_command: $ => choice(
      longAndShortForm('GLOBAL'),
      longAndShortForm('LOCAL'),
      longAndShortForm('PRIVATE'),
      longAndShortForm('PARAMETERS')
    ),

    _go_command_expression: $ => prec.right(seq(
      alias(longAndShortForm('DO'), $.identifier),
      repeat1($._blank),
      repeat1(
        choice(
          $._path,
          $._macro
        )
      )
    )),

    command_expression: $ => seq(
      optional(/(::)*B::/),
      choice(
        seq(
          $._macro_declaration,
          $._terminator
        ),
        seq(
          field('command', $.identifier),
          field('arguments', optional(alias($._command_arguments, $.argument_list))),
          choice(
            $._block,
            $._terminator
          )
        )
      )
    ),

    _command_arguments: $ => seq(
      repeat1(seq(
        repeat($._command_argument_separator),
        $._command_argument
      )),
      prec.left(repeat($._command_argument_separator))
    ),

    _command_argument: $ => choice(
      $._expression,
      $._command_option,
      $._command_format
    ),

    _command_argument_separator: $ => choice(
      $._blank,
      ','
    ),

    _command_option: $ => seq(
      '/',
      $.identifier
    ),

    _command_format: $ => seq(
      '%',
      $.identifier
    ),

    practice_function: $ => prec(PREC.practice_function, seq(
      field('function', $._expression),
      field('arguments', $.argument_list)
    )),

    argument_list: $ => seq(
      '(',
      optional(seq(
        $._expression,
        repeat(seq(
          ',',
          $._expression
        ))
      )),
      ')'
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
      $._file_dialog
    ),

    _integer: $ => choice(
      ...RE_INTEGERS
    ),

    _float: $ => /[0-9]+\.[0-9]+(e[-+][0-9]+)?/,

    _bitmask: $ => choice(
      /0y[0-9xX]+/,  // Bitmask
      /0x[0-9a-fA-FxX]+/,  // Hexmask
    ),

    _address: $ => {
      const alphanum = '[a-zA-Z0-9]+'

      return token(seq(
        new RegExp(alphanum + ':'),  // Access class
        repeat(new RegExp(alphanum + '[.]?:+')),  // Machine identifier:::Memory space identifier::Memory segment identifier:
        choice(
          ...RE_INTEGERS
        )
      ))
    },

    _string: $ => seq(
      '"',
      repeat(choice(
        RE_STRING_BODY,
        /""/,  // Escape sequence
      )),
      '"'
    ),

    _character: $ => seq(
      "'",
      repeat(
        /[^\n\\]/,
      ),
      "'"
    ),

    _path: $ => alias(
      choice(
        $._string,
        /[^"\s\\&:]+/
      ),
      $.literal
    ),

    _symbol: $ => seq(
      "`",
      /[^`\n]+/,
      "`",
    ),

    _time: $ => /[0-9]+\.?[0-9]*[mnu]*s/,

    _file_dialog: $ => '*',

    identifier: $ => token(choice(
      /[a-zA-Z][.\w]*/,
      /[a-zA-Z_][\w]*/,
    )),

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
