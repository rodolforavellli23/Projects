#!/usr/bin/bash

# Compilation Parameters
_source="./main.c"
bin_dir="./bin/"
target="${bin_dir}test"
flags="-std=c99"

# Calling The Compiler
gcc $_source $flags -o $target

# Run the executable
${target}
