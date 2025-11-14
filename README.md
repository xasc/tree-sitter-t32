<!--
SPDX-FileCopyrightText: 2022 Christoph Sax <c_sax@mailbox.org>

SPDX-License-Identifier: MIT
-->

# tree-sitter-t32
[![CI Status](https://ci.codeberg.org/api/badges/xasc/tree-sitter-t32/status.svg)](https://ci.codeberg.org/xasc/tree-sitter-t32)
[![status-badge](https://ci.codeberg.org/api/badges/14550/status.svg?branch=dev)](https://ci.codeberg.org/repos/14550/branches/dev)

Lauterbach TRACE32® script language grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter).
Support for HLL expressions was adapted from [tree-sitter-c](https://github.com/tree-sitter/tree-sitter-c.git).

A demo is available [here](https://xasc.codeberg.page/tree-sitter-t32-playground/).

## Features

- Full coverage of the PRACTICE script language including TRACE32® commands & functions
- Extended support for HLL expressions


## Quick Start

### Dependencies

- [Tree-sitter CLI](https://github.com/tree-sitter/tree-sitter/blob/master/cli/README.md) for generating the parser from the grammar.
- A C compiler
- [Make](https://www.gnu.org/software/make/manual) [optional]
- [Yarn](https://yarnpkg.com/) [optional]


### Commands

#### Generate parser

Create and build the tree-sitter parser for the TRACE32® grammar.
```bash
tree-sitter generate
```

#### Parse TRACE32® Script

<details>

<summary>Use tree-sitter to parse a TRACE32® script.</summary>

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
  (parameter_declaration [10, 0] - [11, 0]
    command: (identifier [10, 0] - [10, 10])
    macro: (macro [10, 11] - [10, 18]))
  (if_block [12, 0] - [18, 0]
    command: (identifier [12, 0] - [12, 2])
    condition: (binary_expression [12, 3] - [12, 16]
      left: (string [12, 3] - [12, 12]
        (macro [12, 4] - [12, 11]))
      right: (string [12, 14] - [12, 16]))
    (block [13, 0] - [17, 0]
      (command_expression [14, 2] - [15, 0]
        command: (identifier [14, 2] - [14, 18])
        arguments: (argument_list [14, 18] - [14, 24]
          (path [14, 19] - [14, 24])))
      (parameter_declaration [15, 2] - [16, 0]
        command: (identifier [15, 2] - [15, 7])
        (identifier [15, 8] - [15, 13])
        macro: (macro [15, 14] - [15, 21]))))
  (if_block [18, 0] - [32, 0]
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
          (format_expression [20, 7] - [20, 18]
            value: (identifier [20, 8] - [20, 13])
            value: (identifier [20, 14] - [20, 18]))
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
          (option_expression [23, 14] - [23, 23]
            option: (identifier [23, 15] - [23, 23]))))
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
          (format_expression [26, 7] - [26, 19]
            value: (identifier [26, 8] - [26, 13])
            value: (identifier [26, 14] - [26, 19]))
          (string [26, 20] - [26, 41]
            (macro [26, 33] - [26, 40])))))
    (else_block [28, 0] - [32, 0]
      command: (identifier [28, 0] - [28, 4])
      (block [29, 0] - [32, 0]
        (command_expression [30, 2] - [31, 0]
          command: (identifier [30, 2] - [30, 6])
          arguments: (argument_list [30, 6] - [30, 44]
            (format_expression [30, 7] - [30, 13]
              value: (identifier [30, 8] - [30, 13]))
            (string [30, 14] - [30, 44]
              (macro [30, 36] - [30, 43])))))))
  (command_expression [33, 0] - [34, 0]
    command: (identifier [33, 0] - [33, 5])))
```

</details>

#### Highlight TRACE32® Script

Use tree-sitter to highlight a TRACE32® script.
```bash
tree-sitter highlight <path>
```

<details>

<summary>Prints the highlighted file</summary>

[![asciicast](https://asciinema.org/a/fY05yHO74XYG6vPngFG3zAgUb.svg)](https://asciinema.org/a/fY05yHO74XYG6vPngFG3zAgUb)

</details>

#### Create Code Navigation Tags

<details>

<summary>Use tree-sitter to create a tags file from a TRACE32® script.</summary>

```
; --------------------------------------------------------------------------------
; @Title: Example test case for Unittests
; @Description:
;   This is an example for a test case which can be executed with lbunit.cmm.
; @Keywords: lbtest test case
; @Author: MOB
; @Copyright: (C) 1989-2015 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: test_example.cmm 8648 2015-09-03 17:04:05Z mobermeir $

; the following block must be present in the beginning of every test case
PRIVATE &func &args &result
ENTRY &func %LINE &args
GOSUB &func &args // call subroutine and return result
ENTRY %LINE &result
ENDDO &result
; end of mandatory block

; SetupTestCase will be called once at the beginning of the test case
; It can be removed if it is not needed.
SetupTestCase:
(
  PRIVATE &date
  &date=DATE.DATE()+" "+DATE.TIME()
  PUTS "test case started at: &date"
  RETURN
)

; SetupTest will be called just before every test
; It can be removed if it is not needed.
SetupTest:
(
  ; here can be some setup
  Data.Set VM:0x0--0xFF 0xA
  RETURN
)

; All tests must start with "Test_"
Test_MyFirstTest:
(
  ; Assertions can be used:
  A_FALSE FALSE()
  A_TRUE (1.+1.==2.)
  RETURN
)

Test_MySecondTest:
(
  A_NUM_EQ 0xA Data.Byte(VM:0x0)
  A_X_PASS Data.Set VM:0x0 0xB
  A_NUM_EQ 0xB Data.Byte(VM:0x0)
  RETURN
)

Test_MyThirdTest:
(
  ; Tests can return "PASS", "FAIL" or "NOT_EXEC"
  ; (alternatively or in addition to assertions)
  IF (0xA!=Data.Byte(VM:0x0))
  (
    RETURN "FAIL"
  )
  ELSE IF (0xB==Data.Byte(VM:0x0))
  (
    RETURN "NOT_EXEC"
  )
  ELSE
  (
    RETURN "PASS"
  )
  RETURN // same as "PASS"
)

MyHelper:
(
  A_NUM_EQ 0xA Data.Byte(VM:0x10)
  RETURN
)

Test_MyFourthTest:
(
  ; tests can call helper functions
  RePeaT 2.
  (
    GOSUB MyHelper
  )
  RETURN
)

DisabledTest_MyFifthTest:
(
  ; this routine will not be executed since it doesn't start with "Test_"
  RETURN
)

; TearDownTest will be called just after every test
; It can be removed if it is not needed.
TearDownTest:
(
  ; here could be some cleanup
  Break.RESet
  RETURN
)

; TearDownTestCase will be called once at the end of the test case
; It can be removed if it is not needed.
TearDownTestCase:
(
  PRIVATE &date
  &date=DATE.DATE()+" "+DATE.TIME()
  PUTS "test case ended at: &date"
  RETURN
)
```

</details>

```bash
tree-sitter tags <path>
```

<details>

<summary>Prints a list of tags</summary>

```
func      	 | call    	ref (13, 7) - (13, 11) `GOSUB &func &args // call subroutine and return result`
SetupTestCase	 | function	def (20, 0) - (20, 13) `SetupTestCase:`
SetupTest 	 | function	def (30, 0) - (30, 9) `SetupTest:`
Test_MyFirstTest	 | function	def (38, 0) - (38, 16) `Test_MyFirstTest:`
Test_MySecondTest	 | function	def (46, 0) - (46, 17) `Test_MySecondTest:`
Test_MyThirdTest	 | function	def (54, 0) - (54, 16) `Test_MyThirdTest:`
MyHelper  	 | function	def (73, 0) - (73, 8) `MyHelper:`
Test_MyFourthTest	 | function	def (79, 0) - (79, 17) `Test_MyFourthTest:`
MyHelper  	 | call    	ref (84, 10) - (84, 18) `GOSUB MyHelper`
DisabledTest_MyFifthTest	 | function	def (89, 0) - (89, 24) `DisabledTest_MyFifthTest:`
TearDownTest	 | function	def (97, 0) - (97, 12) `TearDownTest:`
TearDownTestCase	 | function	def (106, 0) - (106, 16) `TearDownTestCase:`
```

</details>


## Development

There is a makefile to simplify the most common activities. The makefile expects you to have Yarn installed and set up.

To build the parser from the grammar:

    make build


To run all tests:

    make test-all


## Editor Support

| Editor                                                     | Plugin                                                                | Syntax Highlighting | Local Variables  | Folds  | Indents  |
| -------------                                              | -------------                                                         | :-----------------: | :--------------: | :----: | :------: |
| [Neovim](https://github.com/neovim/neovim)                 | [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter) | ✓                   | ✓                | ✓      | ✓        |
| [Helix](https://github.com/helix-editor/helix/tree/master) |                                                                       | ✓                   |                  |        |          |

### nvim-treesitter

Run
```vim
:TSInstall t32
```
to automatically install the supported grammar.

## Limitations

- `(symbol)` nodes that represent an unquoted module, like `\module`, cannot be
  differentiated from user-defined TRACE32 internal HLL variables, e.g. `\x`.
- `(symbol)` nodes that depend on the hex radix mode cannot always be
  kept apart from `(address)` nodes, e.g. `P:A::B:0x800`. To avoid conflicts always add
  the radix mode to the number.
- Commands from the `Var` command group that contain multiple chained
  `(format_expression) (_hll_expression)` blocks
- Unquoted `(path)` nodes are not clearly distinguishable from other literal types
  in command argument lists.
- For HLL expressions used at the top level of commands, the use of spaces is more restricted
  than for nested expressions inside parentheses. The grammar only models the strict behavior.
- `(recursive_macro_expansion)` nodes are restricted to the left-hand side of assignment
  expressions. In other contexts, recursive PRACTICE macro expansions cannot be distinguished
  from `&&` operators.


## Packages

| Language      | Package                                               | Download                                              |
| ------------- | ----------------------------------------------------- | ----------------------------------------------------- |
| Node.js       | [npm](https://www.npmjs.com/package/tree-sitter-t32)  |                                                       |
| Python        | [PyPI](https://pypi.org/project/tree-sitter-t32/)     | [📦](https://pypi.org/project/tree-sitter-t32/#files) |
| Rust          | [crates.io](https://crates.io/crates/tree-sitter-t32) |                                                       |


## Mirrors

This repository is mirrored to https://gitlab.com/xasc/tree-sitter-t32 and https://github.com/xasc/tree-sitter-t32.
The main repository is https://codeberg.org/xasc/tree-sitter-t32.


## Contributing

For the time being, we are not accepting pull requests.
However, please feel free to open issues for changes you would like to see.


## License

Distributed under the MIT license.
[REUSE](https://reuse.software/) is used for managing licensing information throughout the project.
For more accurate licensing information, please check the individual files.


## References

- [PRACTICE Script Language User’s Guide](https://www.lauterbach.com/pdf/practice_user.pdf)
- [Training Script Language PRACTICE](https://www.lauterbach.com/pdf/training_practice.pdf)
- [PowerView User’s Guide](https://www.lauterbach.com/pdf/ide_user.pdf)
