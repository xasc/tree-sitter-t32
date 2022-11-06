# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
