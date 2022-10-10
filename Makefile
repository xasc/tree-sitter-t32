.PHONY: build parse test test-all test-debug test-graph

build:
	yarn build

parse:
	yarn parse example-file

test:
	yarn test --filter Macro

test-debug:
	yarn test --debug --filter IF

test-graph:
	yarn test --debug-graph --filter Macro

test-all:
	yarn test
