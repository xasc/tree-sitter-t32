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
  address: 1,
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
  prefix_postfix: 23,
  field: 24,
  subscript: 25,
  range: 26
}

const RE_BIN_HEX_NUMBER = [
  /0y[0-9]+/,  // Binary
  /0[xX][0-9a-fA-F]+/,  // Hexadecimal
]

const ALPHANUM = '[a-zA-Z0-9]+'

module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.label_identifier,
    $._and_operator_pre_hook,  // Check for presence of macros after operator
    $._decimal_number,
    $._decimal_number_pre_hook,  // Check for presence of range operator after number
    $.path,  // Unquoted path literals
    '&&',
    '&',
  ],

  conflicts: $ => [
    [$._binary_expression, $._and_expression],
    [$._expression, $._function_identifier],
    [$._expression, $.c_type_declaration],
    [$._command_argument, $.assignment_expression],
    [$.argument_list, $.assignment_expression]
  ],

  extras: $ => [
    $._line_continuation,
    $.comment
  ],

  word: $ => $.identifier,

  rules: {
    script: $ => repeat($._top_level),

    _top_level: $ => choice(
      $.block,
      $._statement,
      $._terminator
    ),

    block: $ => prec.right(seq(
      repeat($._blank),
      seq(
        /\((&[+-]?)?/,
        $._terminator
      ),
      repeat(choice(
        $._statement,
        $.block
      )),
      seq(
        repeat($._blank),
        ')',
        $._terminator
      ),
    )),

    _statement: $ => seq(
      repeat($._blank),
      choice(
        alias($.macro_assignment_expression, $.assignment_expression),
        $.command_expression,
        $.labeled_expression,
        $.macro_definition,
        $.if_block,
        $.recursive_macro_expansion,
        $.repeat_block,
        $.while_block
      )
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

    labeled_expression: $ => seq(
      $._label,
      choice(
        $._statement,
        $._terminator
      )
    ),

    if_block: $ => prec.right(seq(
      field('command', choice(
        alias(seq(
          longAndShortForm('Var'),
          '.',
          longAndShortForm('IF')
        ), $.identifier),
        alias(longAndShortForm('IF'), $.identifier)
      )),
      repeat1($._blank),
      field('condition', $._expression),
      $._terminator,
      choice(
        $._statement,
        $.block
      ),
      repeat($._blank),
      optional($.else_block)
    )),

    else_block: $ => seq(
      field('command', alias(longAndShortForm('ELSE'), $.identifier)),
      choice(
        seq(
          $._terminator,
          choice(
            $._statement,
            $.block
          )
        ),
        seq(
          repeat1($._blank),
          $.if_block
        )
      ),
    ),

    while_block: $ => seq(
      field('command', choice(
        alias(seq(
          longAndShortForm('Var'),
          '.',
          longAndShortForm('WHILE')
        ), $.identifier),
        alias(longAndShortForm('WHILE'), $.identifier)
      )),
      repeat1($._blank),
      field('condition', $._expression),
      $._terminator,
      choice(
        $._statement,
        $.block
      ),
    ),

    repeat_block: $ => prec.right(seq(
      field('command', alias(longAndShortForm('RePeaT'), $.identifier)),
      choice(
        seq(
          repeat1($._blank),
          field('condition', $._expression),
          choice(
            $._statement,
            seq(
              $._terminator,
              choice(
                $._statement,
                $.block
              )
            )
          )
        ),
        seq(
          $._terminator,
          choice(
            $._statement,
            $.block
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

    macro_assignment_expression: $ => prec.right(seq(
      field('left', $.macro),
      repeat($._blank),
      field('operator', '='),
      repeat($._blank),
      field('right', $._expression),
      $._terminator
    )),

   unary_expression: $ => choice(
      $._prefix_postfix_expression,
      $._unary_expression
    ),

   _unary_expression: $ => prec.left(PREC.unary, seq(
      field('operator', choice(
        '+', '-', '~', '!'
      )),
      field('argument', $._expression)
    )),

    _prefix_postfix_expression: $ => prec.right(PREC.prefix_postfix, choice(
      seq(
        field('argument', $._expression),
        field('operator', choice('++', '--'))
      ),
      seq(
        field('operator', choice('++', '--')),
        field('argument', $._expression)
      )
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
        ['..', PREC.range],
        ['--', PREC.range],
        ['++', PREC.range]
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

    assignment_expression: $ => prec.right(seq(
        field('left', $._expression),
        repeat($._blank),
        field('operator', '='),
        repeat($._blank),
        field('right', $._expression)
    )),

    _label: $ => seq(
      field('label', alias($.label_identifier, $.identifier)),
      ':'
    ),

    macro_definition: $ => seq(
      optional(/(::)*B::/),
      field('command', alias($.macro_definition_command, $.identifier)),
      repeat1(seq(
        repeat1($._blank),
        field('macro', $.macro)
      )),
      $._terminator
    ),

    macro: $ => prec.left(choice(
      seq(
        '&',
        alias($.identifier, 'name')
      ),
      seq(
        '&',
        '(',
        alias($.identifier, 'name'),
        ')'
      ),
      seq(
        '&',
        '{',
        alias($.identifier, 'name'),
        '}'
      )
    )),

    recursive_macro_expansion: $ => prec.left(seq(
      '&&',
      optional('('),
      $.identifier,
      optional(')')
    )),

    // Address-of operator is treated as PRACTICE macro
    c_pointer_expression: $ => prec.left(PREC.pointer, seq(
      field('operator', '*'),
      field('argument', $._expression)
    )),

    c_cast_expression: $ => prec(PREC.cast, seq(
      '(',
      field('type', alias($.c_type_declaration, $.identifier)),
      ')',
      field('value', $._expression)
    )),

    _var_command: $ => choice(
      seq(
        field('command', alias($._var_definition_command_identifier, $.identifier)),
        field('arguments', optional(alias($._var_definition_command_arguments, $.argument_list)))
      ),
      seq(
        field('command', alias($._var_command_identifier, $.identifier)),
        field('arguments', optional(alias($._var_command_arguments, $.argument_list)))
      )
    ),

    _var_command_identifier: $ => seq(
      alias(longAndShortForm('Var'), 'command'),
      repeat(seq(
        '.',
        alias($.identifier, 'subcommand')
      )),
    ),

    // Commas as argument separators do not seem viable for
    // HLL expressions
    _var_definition_command_arguments: $ => seq(
      repeat1($._blank),
      optional(seq(
        alias($._type, $.literal),
        repeat1($._blank)
      )),
      field('variable', $._internal_c_variable)
    ),

    _var_definition_command_identifier: $ => seq(
      alias(longAndShortForm('Var'), 'command'),
      '.',
      choice(
        longAndShortForm('NEWLOCAL'),
        longAndShortForm('NEWGLOBAL')
      )
    ),

    // Commas as argument separators do not seem viable for
    // HLL expressions
    _var_command_arguments: $ => seq(
      repeat1($._blank),
      choice(
        ',',
        seq(
          repeat1(','),
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

    c_subscript_expression: $ => prec(PREC.subscript, seq(
      field('argument', $._expression),
      seq(
        '[',
        field('index', $._expression),
        ']'
      )
    )),

    c_field_expression: $ => prec(PREC.field, seq(
      field('argument', $._expression),
      field('operator', choice(
        '->',
      )),
      field('field', $.identifier)
    )),

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
          $._var_command,
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
          repeat1(','),
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
      $._expression,
      $._command_option,
      alias($._command_format, $.identifier),
      $.path
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

    call_expression: $ => seq(
      field('function', choice(
        $._expression,
        alias($._function_identifier, $.identifier)
      )),
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
        $._expression,
        repeat(seq(
          repeat($._blank),
          ',',
          repeat($._blank),
          $._expression
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
            $._expression,
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

    _literal: $ => choice(
      $.address,
      $.bitmask,
      $.character,
      $._compound_address,
      alias($._file_dialog, $.literal),
      $.file_handle,
      $.float,
      $.integer,
      $.string,
      $.symbol,
      $.time
    ),

    integer: $ => choice(
      ...RE_BIN_HEX_NUMBER,
      seq(
        $._decimal_number_pre_hook,
        $._decimal_number
      )
    ),

    float: $ => /[0-9]+\.[0-9]+(e[-+][0-9]+)?/,

    bitmask: $ => choice(
      /0y[0-9xX]+/,  // Bitmask
      /0x[0-9a-fA-FxX]+/,  // Hexmask
    ),

    _compound_address: $ => prec.left(seq(
      $.access_class,
      $._expression
    )),

    access_class: $ => {
      return new RegExp(ALPHANUM + ':')
    },

    address: $ => {
      return prec(PREC.address, seq(
        alias($.access_class, 'access_class'),
        repeat(new RegExp(ALPHANUM + '[.]?:+')),  // Machine identifier:::Memory space identifier::Memory segment identifier:
        choice(
          ...RE_BIN_HEX_NUMBER,
          seq(
            $._decimal_number_pre_hook,
            $._decimal_number
          )
        )
      ))
    },

    string: $ => seq(
      '"',
      repeat(choice(
        /[^"]+/,
        /""/,  // Escape sequence
      )),
      '"'
    ),

    character: $ => seq(
      "'",
      choice(
        /\\[^'\n]/,
        /[^\n]/,
      ),
      "'"
    ),

    // Module names with single backslash are treated as internal c-style variables
    symbol: $ => token(choice(
      /\\\\\\([\w_]+|`[^`\n]+`)\\\\([\w_]*|`[^`\n]+`)\\([\w_]*|`[^`\n]+`)\\([\w_]+|`[^`\n]+`)(\\([\w_]+|`[^`\n]+`))*/,  // Includes machine name
      /((\\\\([\w_]+|`[^`\n]+`))?\\([\w_]*|`[^`\n]+`)\\)?`[^`\n]+`(\\([\w_]+|`[^`\n]+`))*/,  // Quoted function name only
      /(\\\\([\w_]+|`[^`\n]+`))?\\([\w_]*|`[^`\n]+`)\\[\w_]+(\\([\w_]+|`[^`\n]+`))*/,  // Module name with unquoted function name
      /[\\]{2,3}([\w_]+|`[^`\n]+`)/,  // Machine or program name
      /\\`[^`\n]+`/,  // Quoted module name only
    )),

    time: $ => /[0-9]+\.?[0-9]*[mnu]*s/,

    _file_dialog: $ => '*',

    file_handle: $ => /#[0-9]+/,

    _type: $ => seq(
      alias($.identifier, ''),
      repeat(/\[[0-9]+\]/)
    ),

    _expression: $ => choice(
      $.assignment_expression,
      $.binary_expression,
      $.call_expression,
      $.c_cast_expression,
      $.c_pointer_expression,
      $.c_subscript_expression,
      $.c_field_expression,
      $.identifier,
      $._literal,
      $.unary_expression,
      $._internal_c_variable,
      $.macro,
      $._parenthesized_expression
    ),

    identifier: $ => /[a-zA-Z_][\w_]*/,

    comment: $ => /[ \t]*(;|\/\/)(\\\r?\n|[^\n])*\n/,

    _terminator: $ => choice(
      $.comment,
      /\s*\r?\n/
    ),

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
