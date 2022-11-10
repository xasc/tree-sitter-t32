(block) @local.scope

; Variable definitions
(
  (macro_definition
    command: (identifier) @command
    macro: (macro) @local.definition.var)
  (#match? @command "^[pP][rR][iI][vV][aA][tT][eE]$")
)
(
  (macro_definition
    command: (identifier) @command
    macro: (macro) @global.definition.var)
  (#match? @command "^[lL][oO][cC][aA][lL]$")
)
(
  (macro_definition
    command: (identifier) @command
    macro: (macro) @global.definition.var)
  (#match? @command "^[gG][lL][oO][bB][aA][lL]$")
)

(
  (command_expression
    command: (identifier) @command
    arguments: (argument_list
        variable: (identifier) @local.definition.var))
  (#match? @command "^([vV][aA][rR]|[vV])[.][nN][eE][wW][lL][oO][cC][aA][lL]$")
)
(
  (command_expression
    command: (identifier) @command
    arguments: (argument_list
        variable: (identifier) @global.definition.var))
  (#match? @command "^([vV][aA][rR]|[vV])[.][nN][eE][wW][gG][lL][oO][bB][aA][lL]$")
)

; Parameter definitions
(
  (macro_definition
    command: (identifier) @command
    macro: (macro) @local.definition.parameter)
  (#match? @command "^[pP][aA][rR][aA][mM][eE][tT][eE][rR][sS]$")
)
(
  (command_expression
    command: (identifier) @command
    arguments: (argument_list (macro) @local.definition.parameter))
  (#match? @command "^[eE][nN][tT][rR][yY]$")
)
(
  (command_expression
    command: (identifier) @command
    arguments: (argument_list (macro) @local.definition.parameter))
  (#match? @command "^[rR][eE][tT][uU][rR][nN][vV][aA][lL][uU][eE][sS]$")
)

; Function definitions
(subroutine_block
  command: (identifier) @command
  subroutine: (identifier) @global.definition.function)

(labeled_expression
  label: (identifier) @global.definition.function
  (block))

; References
(
  (command_expression
    command: (identifier) @command
    arguments: (argument_list . (identifier) @reference))
  (#match? @command "^[gG][oO][sS][uU][bB]$")
)
(macro) @reference
(identifier) @reference
