module.exports = grammar({
  name: 't32',

  externals: $ => [
    $.identifier,
    $.label_identifier
  ],

  word: $ => $.identifier,

  rules: {
    script: $ => repeat($._unit),

    _unit: $ => choice(
      $._expression,
      $._newline
    ),

    _expression: $ => choice(
      $.macro_declaration,
      $.label,
    ),

    label: $ => seq(
      alias($.label_identifier, $.identifier),
      token.immediate(':')
    ),

    macro_declaration: $ => seq(
      choice('GLOBAL', 'LOCAL', 'PRIVATE'),
      repeat1($._macro)
    ),

    _macro: $ => seq(
      '&',
      optional(token.immediate('(')),
      $.identifier,
      optional(token.immediate(')'))
    ),

    _newline: $ => /[\r\n]+/,
  }
});
