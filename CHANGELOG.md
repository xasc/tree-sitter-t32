# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.3.1] - 2023-05-09

### Added

- Check syntax highlighting of standalone address classes, e.g. N:

### Fixed

- Fix syntax highlighting of ENTRY %LINE

## [1.3.0] - 2023-04-27

### Added

- Add support for ENTRY %LINE
- Add support for parameterized paths starting with a macro
- Add token (memory_space) for machine, memory space and memory segment identifiers
- Improve support for nested expressions in memory space

### Changed

- To support more PRACTICE command and functions identifiers can now start with a number
- The structure of the access class and memory space components of addresses are
  checked for correctness

### Fixed

- Fix detection of paths with hyphens
- Fix detection of percentage literals
- Fix detection CPU names with hyphens
- Fix detection of standalone access classes, e.g. N: or Z:

## [1.2.1] - 2022-12-16

### Fixed

- Fix Microsoft Visual C/C++ Compiler builds

## [1.2.0] - 2022-11-16

### Added

- Add query to mark comments as language injection point
- Add query for tag generation
- Add support for SUBROUTINE command
- Add ENTRY, PARAMETERS and RETURNVALUES as parameter declarations
- Add internal C-Style variables as node type

### Changed

- Improve syntax highlighting for:
  - Comments
  - Commands ENTRY, PARAMETERS, RETURNVALUES and SUBROUTINE
  - C-style expressions
  - Parameters
- Nested comments in IF, WHILE, RePeaT or SUBROUTINE block statements become child nodes

### Fixed

- Fix capture names in locals query

## [1.1.0] - 2022-11-06

### Added

- Add frequency and percentage literal detection.
- Add operators for OS commands, for example ">>".
- Add function names with line number offset as symbols.

### Changed

- Detect macros inside of string
- Inverted order of call expressions and unary operators, for
  example "!RUN() -> (unary_operator (call_expression))".
- Highlight first subroutine argument in GOTO as label.
- Update highlight queries for new literal types.

### Fixed

- Fix parsing of nested blocks, if statements and comments.
- Fix detection of macros in complex expressions.

## [1.0.0] - 2022-11-05

### Added

- Initial release
