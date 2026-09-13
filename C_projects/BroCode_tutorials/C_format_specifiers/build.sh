#!/usr/bin/bash

# Build script

## Variables

TARGET_DIR="bin"
TARGET_BIN="test"
SOURCE="main.c"
# FLAGS="--version"
CC="gcc"

## Make the bin directory if it doesn't exist

if ! (ls "$TARGET_DIR") &>/dev/null; then
	mkdir "$TARGET_DIR"
fi

## Compilation

"$CC" \
	"$SOURCE" \
	-o ./"$TARGET_DIR"/"$TARGET_BIN"
