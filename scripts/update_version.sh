#!/usr/bin/env bash

readonly version_node=$(cat << EOF
"version": "$1",
EOF
)

readonly version_rust=$(cat << EOF
version = "$1"
EOF
)

sed --in-place "s#\(.*\)\"version\":.*\$#\1$version_node#" "package.json"
sed --in-place "s#\(.*\)version\s*=.*\$#\1$version_rust#" "Cargo.toml"
