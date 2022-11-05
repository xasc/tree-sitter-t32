[
  "="
  "^^"
  "||"
  "&&"
  "+"
  "-"
  "*"
  "/"
  "%"
  "|"
  "^"
  "=="
  "!="
  ">"
  ">="
  "<="
  "<"
  "<<"
  ">>"
  ".."
  "--"
  "++"
  "+"
  "-"
  "~"
  "!"
  "&"
  "->"
  "*"
] @operator

[
 "("
 ")"
 "{"
 "}"
 "["
 "]"
] @punctuation.bracket

[
  ","
  "."
] @punctuation.delimiter

[
  (access_class)
  (address)
  (bitmask)
  (file_handle)
  (integer)
  (time)
] @number

(float) @float

(string) @string

(path) @string.special

(symbol) @string.special

"" @string.escape

(character) @character

(labeled_expression label: (identifier) @label)

(
  (macro_definition
    command: (identifier) @keyword
    macro: (macro) @parameter)
  (#match? @keyword "^[pP][aA][rR][aA][mM][eE][tT][eE][rR][sS]$")
)
(
  (command_expression
    command: (identifier) @keyword
    arguments: (argument_list (macro) @parameter))
  (#match? @keyword "^[eE][nN][tT][rR][yY]$")
)
(
  (command_expression
    command: (identifier) @keyword
    arguments: (argument_list (macro) @parameter))
  (#match? @keyword "^[rR][eE][tT][uU][rR][nN][vV][aA][lL][uU][eE][sS]$")
)

(
  (command_expression
    command: (identifier) @keyword.return)
  (#match? @keyword.return "^[eE][nN][dD]([dD][oO])?$")
)
(
  (command_expression
    command: (identifier) @keyword.return)
  (#match? @keyword.return "^[rR][eE][tT][uU][rR][nN]$")
)

(macro) @variable

(
 (argument_list (identifier) @constant.builtin)
 (#match? @constant.builtin "^[%/][a-zA-Z][a-zA-Z0-9.]*$")
)
(argument_list
  (identifier) @constant
  !variable)
(argument_list (identifier) @variable)

(command_expression command: (identifier) @keyword)
(macro_definition command: (identifier) @keyword)

(if_block command: (identifier) @conditional)
(else_block command: (identifier) @conditional)

(while_block command: (identifier) @repeat)
(repeat_block command: (identifier) @repeat)

(call_expression function: (identifier) @function.call)

(comment) @comment
