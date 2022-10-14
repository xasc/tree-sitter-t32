const PREC = {
  command: -1,
  address: 10,
  time: 10
}

const COMMAND_NAME = /[a-zA-Z]+/

const INTEGERS = [
  /0y[0-9]+/,  // Binary
  /[0-9]+\.?/,  // Decimal
  /0x[0-9a-fA-F]+/,  // Hexadecimal
]


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
        $.on_event_control,
        $.globalon_event_control,
        $.if_block,
        $.repeat_block,
        $.while_block,
        $._expression,
        $.command,
      )
    ),

    if_block: $ => prec.right(seq(
      longAndShortForm('IF'),
      field('condition', $._expression),
      $._newline,
      choice(
        $._statement,
        $._block
      ),
      repeat($.else_block)
    )),

    else_block: $ => seq(
      longAndShortForm('ELSE'),
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
      longAndShortForm('WHILE'),
      field('condition', $._expression),
      $._newline,
      choice(
        $._statement,
        $._block
      ),
    ),

    repeat_block: $ => prec.right(seq(
      longAndShortForm('RePeaT'),
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
          longAndShortForm('WHILE'),
          field('condition', $._expression),
        ),
      )
    )),

    on_event_control: $ => seq(
      longAndShortForm('ON'),
      choice(
        $._practice_event,
        $._on_device_event,
        $._cpu_event
      ),
      $._on_event_action,
    ),

    globalon_event_control: $ => seq(
      longAndShortForm('GLOBALON'),
      choice(
        seq(
          choice(
            $._practice_event,
            $._globalon_device_event,
            $._cpu_event
          ),
          optional(
            $._common_event_action
          )
        ),
        seq(
          $._common_cmd_event,
          longAndShortForm('EXECute'),
          $.command
        )
      )
    ),

    _practice_event: $ => choice(
      $._common_cmd_event,
      longAndShortForm('ALWAYS'),
      longAndShortForm('ERROR'),
      longAndShortForm('STOP'),
      seq(
        longAndShortForm('TIME'),
        $.literal
      )
    ),

    _on_device_event: $ => choice(
      $._globalon_device_event,
      longAndShortForm('OBREAK'),
      longAndShortForm('ATRIGGER'),
      longAndShortForm('OTRIGGER'),
      longAndShortForm('CATRIGGER')
    ),

    _globalon_device_event: $ => choice(
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
        $.literal
      ),
    ),

    _cpu_event: $ => choice(
      longAndShortForm('PDRESETOFF'),  // Mico32
      longAndShortForm('BOOTSTALL'),
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
          $.identifier,
          $._block
        )
      )
    ),

    _common_cmd_event: $ => seq(
      longAndShortForm('CMD'),
      alias(COMMAND_NAME, $.command)
    ),

    _common_event_action: $ => seq(
      longAndShortForm('DO'),
      $.literal
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
      longAndShortForm('GLOBAL'),
      longAndShortForm('LOCAL'),
      longAndShortForm('PRIVATE')
    ),

    command: $ => seq(
      token(prec(PREC.command, COMMAND_NAME)),
      $._newline
    ),

    integer: $ => choice(
      ...INTEGERS
    ),

    float: $ => /[0-9]+\.[0-9]+(e[-+][0-9]+)?/,

    bitmask: $ => choice(
      /0y[0-9xX]+/,  // Bitmask
      /0x[0-9a-fA-FxX]+/,  // Hexmask
    ),

    literal: $ => choice(
      $.integer,
      $.bitmask,
      $.float,
      $._address,
      $._time,
      $._string,
      $._character,
      $._path
    ),

    _address: $ => token(prec(PREC.address, seq(
      /([a-zA-Z0-9]+:)?([a-zA-Z0-9]+:::)?([0-9]+:)?/,
      token.immediate(choice(
        ...INTEGERS
      ))
    ))),

    _string: $ => seq(
      '"',
      repeat(choice(
        token.immediate(/[^"\n]+/),
        /""/,  // Escape sequence
      )),
      '"'
    ),

    _character: $ => seq(
      "'",
      token.immediate(/[^\n]/),
      "'"
    ),

    _time: $ => token(prec(PREC.time, /[0-9]+\.?[0-9]*[mnu]*s/)),

    _path: $ => seq(
      optional('"'),
      token.immediate(/[^\n]+/),
      optional('"')
    ),

    identifier: $ => /[a-zA-Z]\w*/,

    _newline: $ => /[\r\n]+/,
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
