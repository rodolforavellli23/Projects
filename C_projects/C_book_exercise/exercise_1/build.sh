#!/usr/bin/bash

# Compilation Parameters
_source="./main.c"
bin_dir="./bin/"
target="${bin_dir}test"
flags="-lm"

# Calling The Compiler
gcc $_source $flags -o $target
