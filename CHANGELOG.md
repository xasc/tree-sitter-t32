# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Added support for ENTRY %LINE
- Added support for parameterized paths starting with a macro

### Fixed

- Fixed detection of paths with hypens

## [1.2.1] - 2022-12-16

### Fixed

- Fixed Microsoft Visual C/C++ Compiler builds

## [1.2.0] - 2022-11-16

### Added

- Added query to mark comments as language injection point
- Added query for tag generation
- Added support for SUBROUTINE command
- Added ENTRY, PARAMETERS and RETURNVALUES as parameter declarations
- Added internal C-Style variables as node type

### Changed

- Improved syntax highlighting for:
  - Comments
  - Commands ENTRY, PARAMETERS, RETURNVALUES and SUBROUTINE
  - C-style expressions
  - Parameters
- Nested comments in IF, WHILE, RePeaT or SUBROUTINE block statements become child nodes

### Fixed

- Fixed capture names in locals query

## [1.1.0] - 2022-11-06

### Added

- Added frequency and percentage literal detection.
- Added operators for OS commands, for example ">>".
- Added function names with line number offset as symbols.

### Changed

- Detect macros inside of string
- Inverted order of call expressions and unary operators, for
  example "!RUN() -> (unary_operator (call_expression))".
- Highlight first subroutine argument in GOTO as label.
- Updated highlight queries for new literal types.

### Fixed

- Fixed parsing of nested blocks, if statements and comments.
- Fixed detection of macros in complex expressions.

## [1.0.0] - 2022-11-05

### Added

- Initial release
