.PHONY: build parse test test-all test-debug test-graph

filter ?=

blank :=
space := $(blank) $(blank)
$(space) := $(space)

filterFlag = $(subst _,$( ),$(addprefix --filter ,$(subst $( ),_,"$(filter)")))


build:
	yarn build

parse:
	yarn parse example-file

test:
	yarn test "$(filterFlag)"

test-debug:
	yarn test --debug $(filterFlag)

test-graph:
	yarn test --debug-graph $(filterFlag)

test-all:
	yarn test
