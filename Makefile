.PHONY: build build-wasm highlight parse tags test test-all test-debug test-graph

filter ?=
file ?=

, := ,
blank :=
space := $(blank) $(blank)
$(space) := $(space)

spaces-to-commas = $(subst $( ),$(,),$1)
commas-to-spaces = $(subst $(,),$( ),$1)

filterFlag = $(call commas-to-spaces,$(addprefix --filter ,$(call spaces-to-commas,"$(filter)")))


build: src/parser.c

build-wasm:
	yarn build-wasm

parse: build
	yarn parse "$(file)"

highlight: build
	yarn highlight "$(file)"

tags: build
	yarn tags "$(file)"

playground:
	yarn playground

test: build
	yarn test "$(filterFlag)"

test-debug: build
	yarn test --debug $(filterFlag)

test-graph: build
	yarn test --debug-graph $(filterFlag)

test-all: build
	yarn test


src/parser.c: grammar.js src/scanner.c
	yarn build
