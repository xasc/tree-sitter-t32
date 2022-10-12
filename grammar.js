const PREC = {
  command: -1,
}


module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.label_identifier
  ],

  conflicts: $ => [],

  word: $ => $.identifier,

  rules: {
    script: $ => repeat($._top_level),

    _top_level: $ => choice(
      $.label,
      $._statement,
      $._block,
      $._newline
    ),

    _block: $ => prec.right(seq(
      seq(
        '(',
        $._newline
      ),
      repeat($._statement),
      seq(
        ')',
        optional($._newline)
      ),
    )),

    _statement: $ => seq(
      choice(
        $.macro_declaration,
        $.if_block,
        $.repeat_block,
        $.while_block,
        $._expression,
        $.command,
      )
    ),

    if_block: $ => prec.right(seq(
      caseInsensitiveAndShort('IF'),
      field('condition', $._expression),
      $._newline,
      choice(
        $._statement,
        $._block
      ),
      repeat($.else_block)
    )),

    else_block: $ => seq(
      caseInsensitiveAndShort('ELSE'),
      choice(
        $.if_block,
        seq(
          $._newline,
          choice(
            $._statement,
            $._block
          ),
        )
      )
    ),

    while_block: $ => seq(
      caseInsensitiveAndShort('WHILE'),
      field('condition', $._expression),
      $._newline,
      choice(
        $._statement,
        $._block
      ),
    ),

    repeat_block: $ => prec.right(seq(
      caseInsensitiveAndShort('RePeaT'),
      choice(
        seq(
          $.integer,
          $.command
        ),
        seq(
          optional($.integer),
          $._newline,
          $._block
        ),
        seq(
          $._newline,
          $._block,
          caseInsensitiveAndShort('WHILE'),
          field('condition', $._expression),
        ),
      )
    )),

    _expression: $ => choice(
      $._macro
    ),

    label: $ => seq(
      alias($.label_identifier, $.identifier),
      token.immediate(':')
    ),

    macro_declaration: $ => seq(
      $._declaration_command,
      prec.right(repeat1($._macro))
    ),

    _macro: $ => seq(
      '&',
      optional(token.immediate('(')),
      $.identifier,
      optional(token.immediate(')'))
    ),

    _declaration_command: $ => choice(
      caseInsensitiveAndShort('GLOBAL'),
      caseInsensitiveAndShort('LOCAL'),
      caseInsensitiveAndShort('PRIVATE')
    ),

    command: $ => seq(
      token(prec(PREC.command, /[a-zA-Z]+/)),
      $._newline
    ),

    integer: $ => choice(
      /0y[0-9]+/,    // binary
      /[0-9]+\.?/,   // decimal
      /0x[0-9a-fA-F]+/, // hexadecimal
    ),

    bitmask: $ => choice(
      /0y[0-9xX]+/,    // bitmask
      /0x[0-9a-fA-FxX]+/, // hexmask
    ),

    time: $ => /[0-9]+(\.[0-9]+)?[mnu]?s/,

    identifier: $ => /[a-zA-Z]\w*/,

    _newline: $ => /[\r\n]+/,
  }
})


function caseInsensitiveAndShort(keyword, aliasAsWord = true) {
  let result = new RegExp(
    [
      // Capture short form: RePeaT -> [rR][pP][tT]
      keyword
        .split('')
        .map(l => l === l.toUpperCase() ? `[${l.toLowerCase()}${l}]` : '')
        .join(''),
      // Capture long form: RePeaT -> [rR][eE][pP][eE][aA][tT]
      keyword
        .split('')
        .map(l => `[${l.toLowerCase()}${l.toUpperCase()}]`)
        .join('')
    ].join('|')
  )

  if (aliasAsWord) {
    result = alias(result, keyword)
  }
  return result
}
