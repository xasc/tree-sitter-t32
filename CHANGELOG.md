<!--
SPDX-FileCopyrightText: 2022 Christoph Sax <c_sax@mailbox.org>

SPDX-License-Identifier: MIT
-->

# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [6.0.7] - 2025-09-28

### Fixed

- Use GitLab package registry for artifact publishing.

## [6.0.6] - 2025-09-28

### Fixed

- Fixed release artifact publishing.

## [6.0.5] - 2025-09-28

### Fixed

- Fixed release artifact publishing.

## [6.0.4] - 2025-09-28

### Added

- Publish Node.js package with prebuilt binaries.
- Automatically create releases with WebAssembly module on GitLab.

## [6.0.3] - 2025-09-26

### Added

- Add GitLab CI builds for publishing Node.js packages on npm.

## [6.0.2] - 2025-09-26

### Added

- Added missing license information.
- Added "Contributing" and "License" sections to readme.
- Switch to Tree-sitter v0.25.10

### Fixed

- Fixed parsing errors for `(elif)` and `(else)` blocks.

### Removed

- Dropped `(comment)` limitation from readme file.

## [6.0.1] - 2025-07-18

### Added

- Bump package version.

## [6.0.0] - 2025-07-18

### Changed

- Switch to manual parsing of `(comment)` nodes. Keeping them in the `extras`
  array prevents us from handling then in HLL expressions or `(string)` nodes.

### Fixed

- Fixed parsing errors for `(string)` nodes that contain `//` or `;`.

## [5.5.5] - 2025-07-17

### Added

- Add GitLab CI builds for Python sdist package
- Add GitLab CI builds for Rust package

## [5.5.4] - 2025-07-16

### Added

- Automated GitLab CI builds for Python package (Linux & Windows)

## [5.5.3] - 2025-07-13

### Added

- Switch to Tree-sitter v0.25.7

### Changed

- Reduce number of conflicts for `(if_block)` and `(else_block)`. The capture range
  after `(if_block)` is now clearly defined.

## [5.5.2] - 2025-07-11

### Added

- Switch to Tree-sitter v0.25.6

### Fixed

- Fix capture range for `(if_block)` expressions. Empty lines after the block
  are no longer considered part of the expression anymore.

## [5.5.1] - 2025-05-30

### Added

- Switch to Tree-sitter v0.25.4

### Fixed

- Fix detection of unquoted `(path)` expressions with interposed `(macro)`
  nodes.

## [5.5.0] - 2025-05-08

### Added

- Allow use of unquoted scope resolution operator (`::`) for namespaces, method names,
  etc. in `(symbol)` nodes.

## [5.4.3] - 2025-04-28

### Fixed

- Fix detection of `GOSUB` command if a different capitalization variant is used.
- Shorten regular expression patterns for commands with identical long and short
  forms.

## [5.4.2] - 2025-03-08

### Added

- Switch to Tree-sitter v0.25.3

## [5.4.1] - 2025-02-08

### Added

- Update Tree-sitter dependency for language bindings

## [5.4.0] - 2025-02-08

### Added

- Register grammar for "*.cmmt" files. These are TRACE32 script templates.
- Switch to Tree-sitter v0.25.1
- Add Zig language bindings

## [5.0.3] - 2025-01-17

### Added

- Switch to Tree-sitter v0.24.7

## [5.0.2] - 2024-12-05

### Fixed

- Allow `(recursive_macro_expansion)` on left side of assignment expressions.

## [5.0.1] - 2024-12-01

### Fixed

- Fix incorrect command range in `Var` function expressions and commands.

## [5.0.0] - 2024-11-30

### Added

- `Var.NEWGLOBAL` and `Var.NEWLOCAL` commands with value assignment.
- Better PRACTICE macro detection in strings.

### Changed

- `(option_expression)` can capture multiple macros as values.

### Fixed

- Fix parsing of commands with multiple options and trailing options that are specified
  as macros.
- Fix detection of `"&"` as string literal.
- Do not accept comma as command option delimiter.
- Allow multiple spaces between option and its value.

## [4.0.2] - 2024-11-26

### Fixed

- Fix `labeled_expression` that are continued with an indented command.

## [4.0.1] - 2024-11-11

### Changed

- Update language bindings.

## [4.0.0] - 2024-10-23

### Changed

- `RePeaT` blocks with post condition capture the `WHILE` keyword as `(command)`, so that highlights are
  correctly applied.

## [3.0.0] - 2024-04-13

### Added

- New node `(elif)` for `ELSE IF` blocks.

### Changed

- Long chains of `ELSE IF` blocks do not increase the nesting depth of the tree
  with each `ELSE` keyword. Each chained `(elif)` node is assigned to the topmost `(if)`.
- Use REUSE for license management.

### Fixed

- Fix Node.js CI builds.

## [2.8.1] - 2024-03-23

### Fixed

- Fix build errors for Rust language bindings.

## [2.8.0] - 2024-03-23

### Added

- Language bindings for C, Go, Python, and Swift.
- Switch to Tree-sitter v0.22

## [2.7.0] - 2024-03-03

### Added

- Switch to Tree-sitter v0.21

### Changed

- Convert queries to last-wins precedence.

### Removed

- Remove unnecessary conflict resolution for node `(hll_pointer_declarator)`.

## [2.6.2] - 2023-11-15

### Fixed

- Logical AND operators with parenthesized on right hand side are parsed
  without error.

## [2.6.1] - 2023-10-25

### Fixed

- Commands including the device prefix `B::` are not mixed up with `(labeled_expression)`.

## [2.6.0] - 2023-09-27

### Added

- `Var` commands with multiple `(format_expression) (_hll_expression)` blocks
  are supported.

### Fixed

- `Var` commands with string as first parameter.

## [2.5.0] - 2023-09-17

### Added

- Support `(symbol)` nodes with `\<line number>\<column number>\<instance number>` postfix.
- Support `(symbol)` nodes with file path as replacement for module name.

## [2.4.0] - 2023-09-13

### Changed

- Better support for scripts with both `(repeat_block)` in post condition format
  and `(while_block)` nodes. Ambiguities are resolved during runtime.

### Fixed

- Fix parsing of `(block)`, `(if_block)`, `(while_block)` and `(repeat_block)` nodes with
  additional line breaks.

## [2.3.0] - 2023-09-07

### Changed

- Do not include empty lines in range of last expression.

### Fixed

- Comments end at line break

## [2.2.1] - 2023-08-02

### Fixed

- Stop parsing host command argument lists after seeing a line terminator.

### Added

- Detect `(string)` nodes in arguments of host commands

## [2.2.0] - 2023-07-29

### Changed

- Reduce number of highlighting queries for variables in HLL expressions.
  A single `(identifier) @variable` capture is sufficient.

## [2.1.1] - 2023-07-27

### Fixed

- Revert highlighting of PRACTICE function call expressions back to `@function.builtin`

## [2.1.0] - 2023-07-23

### Added

- Extend tests for syntax highlighting

### Changed

- Interpret nodes `(float)`, `(frequency)`, `(percentage)` and `(time)` as floating point
  instead of integers numbers.
- Interpret node `(access_class)` as constant instead of number.

### Fixed

- Fix highlighting of `(identifier)` nodes as variables.

## [2.0.0] - 2023-07-23

### Added

- New node types for PRACTICE commands with HLL expressions, for example
  `(hll_update_expression)`.
- Integrated [tree-sitter-c](https://github.com/tree-sitter/tree-sitter-c) C grammar with TRACE32® HLL extensions (range operator, symbols, ...)
- Updated queries for syntax highlighting and tests.
- Node `(option_expression)` supports command options with option values.
- Node `(format_expression)` identifies format parameters in commands.

### Changed

- All values of command format parameters accessible.

### Removed

- Nodes `(c_type_declaration)`, `(c_subscript_expression)`,
  `(c_cast_expression)`, `(c_field_expression)`, `(internal_c_variable)`, `(type_identifier)`, `(c_pointer_expression)` and `(c_field_expression)` were removed.

## [1.3.2] - 2023-05-10

### Fixed

- Fix Microsoft Visual C/C++ Compiler builds.

## [1.3.1] - 2023-05-09

### Added

- Check syntax highlighting of standalone address classes, e.g. `N:`.

### Fixed

- Fix syntax highlighting of `ENTRY %LINE`.

## [1.3.0] - 2023-04-27

### Added

- Add support for `ENTRY %LINE`.
- Add support for parameterized paths starting with a macro.
- Add node `(memory_space)` for machine, memory space and memory segment identifiers.
- Improve support for nested expressions in memory space.

### Changed

- To support more PRACTICE command and functions identifiers can now start with a number.
- The structure of the access class and memory space components of addresses are
  checked for correctness.

### Fixed

- Fix detection of paths with hyphens.
- Fix detection of percentage literals.
- Fix detection CPU names with hyphens.
- Fix detection of standalone access classes, e.g. `N:` or `Z:`.

## [1.2.1] - 2022-12-16

### Fixed

- Fix Microsoft Visual C/C++ Compiler builds.

## [1.2.0] - 2022-11-16

### Added

- Add query to mark comments as language injection point.
- Add query for tag generation.
- Add support for `SUBROUTINE` command.
- Add `ENTRY`, `PARAMETERS` and `RETURNVALUES` as parameter declarations.
- Add internal C-Style variables as node type.

### Changed

- Improve syntax highlighting for:
  - Comments
  - Commands `ENTRY`, `PARAMETERS`, `RETURNVALUES` and `SUBROUTINE`
  - C-style expressions
  - Parameters
- Nested comments in `IF`, `WHILE`, `RePeaT` or `SUBROUTINE` block statements become child nodes.

### Fixed

- Fix capture names in locals query.

## [1.1.0] - 2022-11-06

### Added

- Add frequency and percentage literal detection.
- Add operators for OS commands, for example `>>`.
- Add function names with line number offset as symbols.

### Changed

- Detect macros inside of string
- Inverted order of call expressions and unary operators, for
  example `!RUN() -> (unary_operator (call_expression))`.
- Highlight first subroutine argument in `GOTO` as label.
- Update highlight queries for new literal types.

### Fixed

- Fix parsing of nested blocks, if statements and comments.
- Fix detection of macros in complex expressions.

## [1.0.0] - 2022-11-05

### Added

- Initial release
