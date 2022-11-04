.PHONY: build parse test test-all test-debug test-graph

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

parse:
	yarn parse "$(file)"

highlight:
	yarn highlight "$(file)"

test:
	yarn test "$(filterFlag)"

test-debug:
	yarn test --debug $(filterFlag)

test-graph:
	yarn test --debug-graph $(filterFlag)

test-all:
	yarn test
