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

    _block: $ => seq(
      seq(
        '(',
        $._newline
      ),
      repeat($._statement),
      seq(
        ')',
        $._newline
      ),
    ),

    _statement: $ => seq(
      choice(
        $.macro_declaration,
        $.if_block,
        $.while_block,
        $._expression,
        $.command,
      )
    ),

    if_block: $ => prec.right(seq(
      caseInsensitiveAndShort('IF'),
      $._expression,
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
      $._expression,
      $._newline,
      choice(
        $._statement,
        $._block
      ),
    ),

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

    identifier: $ => /[a-zA-Z]\w*/,

    _newline: $ => /[\r\n]+/,
  }
})


function concatRegexp(reg, exp) {
  let flags = reg.flags + exp.flags;
  flags = Array.from(new Set(flags.split(''))).join();
  return new RegExp(reg.source + exp.source, flags);
}


function caseInsensitiveAndShort(keyword, aliasAsWord = true) {
  // Capture short form: RePeaT -> [rR][pP][tT]
  const short = new RegExp(keyword
    .split('')
    .map(l => l === l.toUpperCase() ? `[${l.toLowerCase()}${l}]` : '')
    .join('')
  )

  const combinator = new RegExp('|')

  // Capture long form: RePeaT -> [rR][eE][pP][eE][aA][tT]
  const long = new RegExp(keyword
    .split('')
    .map(l => `[${l.toLowerCase()}${l.toUpperCase()}]`)
    .join('')
  )

  let result = concatRegexp(concatRegexp(short, combinator), long)
  if (aliasAsWord) {
    result = alias(result, keyword)
  }
  return result
}
