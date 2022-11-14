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


build:
	yarn build

build-wasm:
	yarn build-wasm

parse:
	yarn parse "$(file)"

highlight:
	yarn highlight "$(file)"

tags:
	yarn tags "$(file)"

playground:
	yarn playground

test:
	yarn test "$(filterFlag)"

test-debug:
	yarn test --debug $(filterFlag)

test-graph:
	yarn test --debug-graph $(filterFlag)

test-all:
	yarn test
