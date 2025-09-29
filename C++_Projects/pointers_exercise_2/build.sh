#!/usr/bin/bash

# C++ build script in Bash

# Compilation Parameters
src="./main.cpp"
out="./bin/test_bin"
std="c++20"

# Build the test executable
g++ $src \
	-o $out \
	-std=$std
