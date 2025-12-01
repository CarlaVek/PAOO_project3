#!/bin/bash

set -e
ROOT_DIR="$(pwd)"
BUILD_DIR="$ROOT_DIR/build"

mkdir -p "$BUILD_DIR"
cmake -S "$ROOT_DIR" -B "$BUILD_DIR"
make -C "$BUILD_DIR"

"$BUILD_DIR/safe_writer"
"$BUILD_DIR/unsafe_writer"