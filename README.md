# tree-sitter-t32
[![Please don't upload to GitHub](https://nogithub.codeberg.page/badge.svg)](https://nogithub.codeberg.page)
[![CI Status](https://ci.codeberg.org/api/badges/xasc/tree-sitter-t32/status.svg)](https://ci.codeberg.org/xasc/tree-sitter-t32)

Lauterbach TRACE32 script language grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter).

## Quick Start

### Dependencies

- [Tree-sitter CLI](https://github.com/tree-sitter/tree-sitter/blob/master/cli/README.md) for generating the parser from the grammar.
- A C compiler

### Commands

#### Generate parser

Create and build the tree-sitter parser for the TRACE32 grammar.
```bash
tree-sitter generate
```

#### Parse TRACE32 Script

<details>

<summary>Use tree-sitter to parse a TRACE32 script</summary>

Example:
```
; --------------------------------------------------------------------------------
; @Title: Beautify an existing PRACTICE script
; @Description:
;   Beautifies the script, fixing the CamelCasing and indentation.
; @Keywords: PRACTICE, EDIT.FORMAT, CamelCasing, indent, beautify
; @Author: MOB
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: beautify.cmm 19661 2022-07-29 15:43:03Z rweiss $

PARAMETERS &script

IF "&script"==""
(
  DIALOG.File.open *.cmm
  ENTRY %LINE &script
)

IF FILE.EXIST("&script")
(
  ECHO %COLOR.GRAY "beautifying: &script"
  SETUP.EDITOR.TYPE PowerView ; required for EDIT.FORMAT
  PEDIT "&script"
  EDIT.FORMAT /Beautify
  EDIT.SAVE "&script"
  EDIT.CLOSE "&script"
  ECHO %COLOR.GREEN "beautified: &script"
)
ELSE
(
  ECHO %ERROR "Error: no such file: &script"
)

ENDDO
```
</details>

```bash
tree-sitter parse <path>
```

<details>

<summary>Prints the syntax tree</summary>

```
(script [0, 0] - [34, 0]
  (comment [0, 0] - [1, 0])
  (comment [1, 0] - [2, 0])
  (comment [2, 0] - [3, 0])
  (comment [3, 0] - [4, 0])
  (comment [4, 0] - [5, 0])
  (comment [5, 0] - [6, 0])
  (comment [6, 0] - [7, 0])
  (comment [7, 0] - [8, 0])
  (comment [8, 0] - [9, 0])
  (parameter_declaration [10, 0] - [12, 0]
    command: (identifier [10, 0] - [10, 10])
    macro: (macro [10, 11] - [10, 18]))
  (if_block [12, 0] - [18, 0]
    command: (identifier [12, 0] - [12, 2])
    condition: (binary_expression [12, 3] - [12, 16]
      left: (string [12, 3] - [12, 12]
        (macro [12, 4] - [12, 11]))
      right: (string [12, 14] - [12, 16]))
    (block [13, 0] - [18, 0]
      (command_expression [14, 2] - [15, 0]
        command: (identifier [14, 2] - [14, 18])
        arguments: (argument_list [14, 18] - [14, 24]
          (path [14, 19] - [14, 24])))
      (parameter_declaration [15, 2] - [16, 0]
        command: (identifier [15, 2] - [15, 7])
        (identifier [15, 8] - [15, 13])
        macro: (macro [15, 14] - [15, 21]))))
  (if_block [18, 0] - [33, 0]
    command: (identifier [18, 0] - [18, 2])
    condition: (call_expression [18, 3] - [18, 24]
      function: (identifier [18, 3] - [18, 13])
      arguments: (argument_list [18, 13] - [18, 24]
        (string [18, 14] - [18, 23]
          (macro [18, 15] - [18, 22]))))
    (block [19, 0] - [28, 0]
      (command_expression [20, 2] - [21, 0]
        command: (identifier [20, 2] - [20, 6])
        arguments: (argument_list [20, 6] - [20, 41]
          (identifier [20, 7] - [20, 18])
          (string [20, 19] - [20, 41]
            (macro [20, 33] - [20, 40]))))
      (command_expression [21, 2] - [22, 0]
        command: (identifier [21, 2] - [21, 19])
        arguments: (argument_list [21, 19] - [21, 29]
          (identifier [21, 20] - [21, 29]))
        (comment [21, 29] - [22, 0]))
      (command_expression [22, 2] - [23, 0]
        command: (identifier [22, 2] - [22, 7])
        arguments: (argument_list [22, 7] - [22, 17]
          (string [22, 8] - [22, 17]
            (macro [22, 9] - [22, 16]))))
      (command_expression [23, 2] - [24, 0]
        command: (identifier [23, 2] - [23, 13])
        arguments: (argument_list [23, 13] - [23, 23]
          (identifier [23, 15] - [23, 23])))
      (command_expression [24, 2] - [25, 0]
        command: (identifier [24, 2] - [24, 11])
        arguments: (argument_list [24, 11] - [24, 21]
          (string [24, 12] - [24, 21]
            (macro [24, 13] - [24, 20]))))
      (command_expression [25, 2] - [26, 0]
        command: (identifier [25, 2] - [25, 12])
        arguments: (argument_list [25, 12] - [25, 22]
          (string [25, 13] - [25, 22]
            (macro [25, 14] - [25, 21]))))
      (command_expression [26, 2] - [27, 0]
        command: (identifier [26, 2] - [26, 6])
        arguments: (argument_list [26, 6] - [26, 41]
          (identifier [26, 7] - [26, 19])
          (string [26, 20] - [26, 41]
            (macro [26, 33] - [26, 40])))))
    (else_block [28, 0] - [33, 0]
      command: (identifier [28, 0] - [28, 4])
      (block [29, 0] - [33, 0]
        (command_expression [30, 2] - [31, 0]
          command: (identifier [30, 2] - [30, 6])
          arguments: (argument_list [30, 6] - [30, 44]
            (identifier [30, 7] - [30, 13])
            (string [30, 14] - [30, 44]
              (macro [30, 36] - [30, 43])))))))
  (command_expression [33, 0] - [34, 0]
    command: (identifier [33, 0] - [33, 5])))
```

</details>

#### Highlight TRACE32 Script

Use tree-sitter to highlight a TRACE32 script.
```bash
tree-sitter highlight <path>
```

## Syntax Highlighting

- [Neovim](https://github.com/neovim/neovim):
  [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter)

## References

- [PRACTICE Script Language User’s Guide](https://www.lauterbach.com/pdf/practice_user.pdf)
- [Training Script Language PRACTICE](https://www.lauterbach.com/pdf/training_practice.pdf)
- [PowerView User’s Guide](https://www.lauterbach.com/pdf/ide_user.pdf)
