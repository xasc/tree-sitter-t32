#!/usr/bin/env bash

echo "Generating parser..."
make build

echo "Running tests..."
make test-all
