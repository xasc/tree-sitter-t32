#!/usr/bin/env bash

# SPDX-FileCopyrightText: 2022 Christoph Sax <c_sax@mailbox.org>
#
# SPDX-License-Identifier: MIT

echo "Generating parser..."
make build

echo "Running tests..."
make test-all
