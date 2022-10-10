const PREC = {
  command: -1,
  else_block: 10,
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
      $._block,
      $._newline
    ),

    _block: $ => choice(
      $.macro_declaration,
      $.if_block,
      alias($._flow_command, $.command),
      $._expression,
      $.command,
    ),

    if_block: $ => prec.left(seq(
      choice('IF', 'if'),
      $._expression,
      $._newline,
      $._block,
      repeat($.else_block)
    )),

    else_block: $ => seq(
      token(prec(PREC.else_block, choice('ELSE', 'else'))),
      choice(
        $.if_block,
        seq($._newline, $._block)
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
      'GLOBAL', 'global',
      'LOCAL', 'local',
      'PRIVATE', 'private'
    ),

    _flow_command: $ => choice(
      'STOP', 'stop',
      'CONTinue', 'continue', 'CONT', 'cont',
    ),

    command: $ => seq(
      token(prec(PREC.command, /[a-zA-Z]+/)),
      $._newline
    ),

    identifier: $ => /[a-zA-Z]\w*/,

    _newline: $ => /[\r\n]+/,
  }
});
