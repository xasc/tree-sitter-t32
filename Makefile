# SPDX-FileCopyrightText: 2022 Christoph Sax <c_sax@mailbox.org>
#
# SPDX-License-Identifier: MIT

.PHONY: build build-wasm highlight parse playground publish tags test test-all test-debug test-graph

filter ?=
file ?=

, := ,
blank :=
space := $(blank) $(blank)
$(space) := $(space)

spaces-to-commas = $(subst $( ),$(,),$1)
commas-to-spaces = $(subst $(,),$( ),$1)

filterFlag = $(call commas-to-spaces,$(addprefix --include ,$(call spaces-to-commas,"$(filter)")))

yarn := yarnpkg

build: src/parser.c

build-wasm:
	$(yarn) build-wasm --output tree-sitter-t32.wasm

parse: build
	$(yarn) parse "$(file)"

highlight: build
	$(yarn) highlight "$(file)"

tags: build
	$(yarn) tags "$(file)"

publish:
	cargo publish

playground:
	$(yarn) playground

test: build
	$(yarn) test "$(filterFlag)"

test-debug: build
	$(yarn) test --debug $(filterFlag)

test-graph: build
	$(yarn) test --debug-graph $(filterFlag)

test-all: build
	$(yarn) test


src/parser.c: grammar.js src/scanner.c
	$(yarn) build
