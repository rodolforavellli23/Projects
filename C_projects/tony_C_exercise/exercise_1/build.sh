#!/usr/bin/bash

# Basic build script for C in bash

# Compilation Variables
SRC="./main.c"
OUTPUT_DIR="bin"
TARGET="test"
FLAGS="-Wall -Wextra"

# Create the output directory if it doesn't already exist
if [ ! -d "$OUTPUT_DIR" ]; then
	mkdir -p "$OUTPUT_DIR"
fi

# Compile Program
gcc $SRC \
	$FLAGS \
	-o $TARGET 

# Move Program
mv ./"$TARGET" ./"$OUTPUT_DIR"/"$TARGET"
