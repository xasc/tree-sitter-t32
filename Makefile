.PHONY: build parse test

build:
	yarn build

parse:
	yarn parse example-file

test:
	yarn test --debug
