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
        $._expression,
        $.command,
      )
    ),

    if_block: $ => prec.right(seq(
      choice('IF', 'if'),
      $._expression,
      $._newline,
      choice(
        $._statement,
        $._block
      ),
      repeat($.else_block)
    )),

    else_block: $ => seq(
      choice('ELSE', 'else'),
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
      caseInsensitive('GLOBAL'),
      caseInsensitive('LOCAL'),
      caseInsensitive('PRIVATE')
    ),

    command: $ => seq(
      token(prec(PREC.command, /[a-zA-Z]+/)),
      $._newline
    ),

    identifier: $ => /[a-zA-Z]\w*/,

    _newline: $ => /[\r\n]+/,
  }
})


function caseInsensitive (keyword, aliasAsWord = true) {
  let result = new RegExp(keyword
    .split('')
    .map(l => l !== l.toLowerCase() ? `[${l}${l.toLowerCase()}]` : l)
    .join('')
  )
  if (aliasAsWord) result = alias(result, keyword)
  return result
}
