.PHONY: build parse test test-all test-debug test-graph

filter ?=

build:
	yarn build

parse:
	yarn parse example-file

test:
	yarn test $(addprefix --filter ,$(filter))

test-debug:
	yarn test --debug $(addprefix --filter ,$(filter))

test-graph:
	yarn test --debug-graph $(addprefix --filter ,$(filter))

test-all:
	yarn test
