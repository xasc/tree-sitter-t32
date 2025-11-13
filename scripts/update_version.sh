#!/usr/bin/env bash

# SPDX-FileCopyrightText: 2022 Christoph Sax <c_sax@mailbox.org>
#
# SPDX-License-Identifier: MIT

readonly version_cmake=$(cat << EOF
VERSION "$1"
EOF
)

readonly version_node=$(cat << EOF
"version": "$1",
EOF
)

readonly version_rust=$(cat << EOF
version = "$1"
EOF
)

readonly version_python="$version_rust"
readonly version_treesitter="$version_node"

readonly version_zig=$(cat << EOF
.version = "$1",
EOF
)

sed --in-place "s#\(.*\)\<VERSION\s\+\".*\$#\1$version_cmake#" "CMakeLists.txt"
sed --in-place "s#\(.*\)\"version\":.*\$#\1$version_node#" "package.json"
sed --in-place "s#\(.*\)version\s*=.*\$#\1$version_python#" "pyproject.toml"
sed --in-place "s#\(.*\)version\s*=.*\$#\1$version_rust#" "Cargo.toml"
sed --in-place "s#\(.*\)\"version\":.*\$#\1$version_treesitter#" "tree-sitter.json"
sed --in-place "s#\(.*\)\.version\s*=.*\$#\1$version_zig#" "build.zig.zon"

make build
cargo build
