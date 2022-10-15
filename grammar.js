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
  command: -1,
  _non_quoted_symbol: -1,
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
  address: 100,
  time: 100
}

const BLANK = /[ \t]/

const COMMAND_NAME = /[a-zA-Z]+/

const STRING_BODY = /[^"\n]+/

const INTEGERS = [
  /0y[0-9]+/,  // Binary
  /[0-9]+\.?/,  // Decimal
  /0x[0-9a-fA-F]+/,  // Hexadecimal
]


module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.label_identifier,
    $._no_blank,  // Zero-length token for expressions
    $._logical_and,
    $._bitwise_and
  ],

  conflicts: $ => [],

  extras: $ => [
    /\\\r?\n/
  ],

  word: $ => $.identifier,

  rules: {
    script: $ => repeat($._top_level),

    _top_level: $ => choice(
      $.label,
      $._statement,
      $._block,
      $._terminator
    ),

    _block: $ => prec.right(seq(
      seq(
        '(',
        $._terminator
      ),
      repeat($._statement),
      seq(
        ')',
        $._terminator
      ),
    )),

    _statement: $ => choice(
      $.macro_declaration,
      $.recursive_macro_expansion,
      $.assignment_expression,
      $.on_event_control,
      $.globalon_event_control,
      $.if_block,
      $.repeat_block,
      $.while_block,
      $.command,
    ),

    if_block: $ => prec.right(seq(
      longAndShortForm('IF'),
      repeat1($._blank),
      field('condition', $._macro),
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
              $.command
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

    on_event_control: $ => seq(
      longAndShortForm('ON'),
      repeat1($._blank),
      choice(
        $._common_practice_event,
        $._on_device_event,
        $._cpu_event,
        $._cmd_event,
      ),
      repeat1($._blank),
      $._on_event_action,
    ),

    globalon_event_control: $ => seq(
      longAndShortForm('GLOBALON'),
      repeat1($._blank),
      choice(
        seq(
          choice(
            $._common_practice_event,
            $._common_device_event,
            $._cpu_event,
            $._cmd_event,
          ),
          optional(seq(
            repeat1($._blank),
            $._common_event_action
          )),
          $._terminator
        ),
        seq(
          $._cmd_event,
          repeat1($._blank),
          longAndShortForm('EXECute'),
          repeat1($._blank),
          $.command
        )
      )
    ),

    _common_practice_event: $ => choice(
      longAndShortForm('ALWAYS'),
      longAndShortForm('ERROR'),
      longAndShortForm('STOP'),
      seq(
        longAndShortForm('TIME'),
        repeat1($._blank),
        $.literal
      )
    ),

    _on_device_event: $ => choice(
      $._common_device_event,
      longAndShortForm('OBREAK'),
      longAndShortForm('ATRIGGER'),
      longAndShortForm('OTRIGGER'),
      longAndShortForm('CATRIGGER')
    ),

    _common_device_event: $ => choice(
      longAndShortForm('ABREAK'),
      longAndShortForm('CORESWITCH'),
      longAndShortForm('GO'),
      longAndShortForm('PBREAK'),
      longAndShortForm('POWERDOWN'),
      longAndShortForm('POWERUP'),
      longAndShortForm('RESET'),
      longAndShortForm('SYSDOWN'),
      longAndShortForm('SYSUP'),
      longAndShortForm('TRIGGER'),
      seq(
        longAndShortForm('PBREAKAT'),
        repeat1($._blank),
        $.literal
      ),
    ),

    _cpu_event: $ => choice(
      longAndShortForm('PDRESETOFF'),  // Mico32
      longAndShortForm('BOOTSTALL'),  // Intel x86
      longAndShortForm('CPUBOOTSTALL'),
      longAndShortForm('TRACEHUBBREAK'),
      longAndShortForm('PBREAKRESET'),
      longAndShortForm('PBREAKVMENTRY'),
      longAndShortForm('PBREAKVMEXIT'),
      longAndShortForm('PBREAKSMMENTRY'),
      longAndShortForm('PBREAKSMMEXIT'),
      longAndShortForm('PBREAKGENERALDETECT'),
      longAndShortForm('PBREAKINIT'),
      longAndShortForm('PBREAKMACHINECHECK'),
      longAndShortForm('PBREAKSHUTDOWN'),
      longAndShortForm('PBREAKC6EXIT'),
      longAndShortForm('PBREAKENCLU'),
    ),

    _on_event_action: $ => choice(
      $._common_event_action,
      longAndShortForm('inherit'),
      longAndShortForm('CONTinue'),
      longAndShortForm('default'),
      seq(
        choice(
          longAndShortForm('GOSUB'),
          longAndShortForm('GOTO'),
          longAndShortForm('JUMPTO'),
        ),
        choice(
          seq(
            repeat1($._blank),
            $.identifier,
            $._terminator
          ),
          seq(
            $._terminator,
            $._block
          )
        )
      )
    ),

    _cmd_event: $ => seq(
      longAndShortForm('CMD'),
      repeat1($._blank),
      alias(COMMAND_NAME, $.command)
    ),

    _common_event_action: $ => seq(
      longAndShortForm('DO'),
      repeat1($._blank),
      $._path
    ),

    _expression: $ => choice(
      $._macro,
      $.literal,
      $.unary_expression,
      $.binary_expression,
      $._parenthesized_expression
    ),

    _parenthesized_expression: $ => seq(
      /[({]/,
      $._expression,
      $._no_blank,
      /[)}]/
    ),

    assignment_expression: $ => seq(
      $._macro,
      repeat($._blank),
      "=",
      repeat($._blank),
      $._expression
    ),

   unary_expression: $ => prec.left(PREC.unary, seq(
      field('operator', choice(
        '+', '-', '~', '!'
      )),
      $._no_blank,
      field('argument', $._expression)
    )),

    binary_expression: $ => {
      const operators = [
        [$._logical_and, PREC.logical_and],
        [$._bitwise_and, PREC.bitwise_and],
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
        [/\.\.|\-\-|\+\+/, PREC.range]
      ];

      return choice(...operators.map(([op, pre]) => {
        return prec.left(pre, seq(
          field('left', $._expression),
          field('operator', op),
          $._no_blank,
          field('right', $._expression)
        ))
      }));
    },

    label: $ => seq(
      alias($.label_identifier, $.identifier),
      token.immediate(':')
    ),

    macro_declaration: $ => seq(
      $._declaration_command,
      repeat1(seq(
        repeat1($._blank),
        $._macro
      )),
    ),

    _macro: $ => prec.left(seq(
      '&',
      optional('('),
      $.identifier,
      optional(')')
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
      longAndShortForm('PRIVATE')
    ),

    command: $ => seq(
      token(prec(PREC.command, COMMAND_NAME)),
      $._terminator
    ),

    literal: $ => choice(
      $._integer,
      $._bitmask,
      $._float,
      $._address,
      $._time,
      $._string,
      $._character,
      $._non_quoted_symbol
    ),

    _integer: $ => seq(
      optional(/[-\+]/),
      choice(
        ...INTEGERS
      )
    ),

    _float: $ => /[0-9]+\.[0-9]+(e[-+][0-9]+)?/,

    _bitmask: $ => choice(
      /0y[0-9xX]+/,  // Bitmask
      /0x[0-9a-fA-FxX]+/,  // Hexmask
    ),

    _address: $ => token(prec(PREC.address, seq(
      /([a-zA-Z0-9]+:)([a-zA-Z0-9]+:::)?([0-9]+:)?/,
      choice(
        ...INTEGERS
      )
    ))),

    _string: $ => seq(
      '"',
      repeat(choice(
        STRING_BODY,
        /""/,  // Escape sequence
      )),
      '"'
    ),

    _path: $ => alias(
      choice(
        $._string,
        STRING_BODY
      ),
      $.literal
    ),

    _non_quoted_symbol: $ => token(prec(PREC._non_quoted_symbol, seq(
      /[^"\s.-]+/,
    ))),

    _character: $ => seq(
      "'",
      /[^\n]/,
      "'"
    ),

    _time: $ => token(prec(PREC.time, /[0-9]+\.?[0-9]*[mnu]*s/)),

    identifier: $ => /[a-zA-Z]\w*/,

    _terminator: $ => prec.right(repeat1(
      /\s*[\r\n]+\s*/
    )),

    _blank: $ => BLANK
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
