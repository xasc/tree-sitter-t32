(
  (command_expression
    command: (identifier) @keyword
    arguments: (argument_list . (identifier) @name))
  (#match? @keyword "^[sS][uU][bB][rR][oO][uU][tT][iI][nN][eE]$")
) @definition.function

(
  (command_expression
    command: (identifier) @keyword
    arguments: (argument_list . (identifier) @name))
  (#match? @keyword "^[gG][oO][sS][uU][bB]$")
) @reference.call

(call_expression
  function: (identifier) @name
) @reference.call
