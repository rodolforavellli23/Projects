#!/usr/bin/bash

# C++ build script in Bash

# Compilation Parameters
b_dir="./bin"
src="./main.cpp"
out="./$(b_dir)/test_bin"
std="c++20"

# Check if there's a bin directory

if [ ! -d "$(b_dir)" ]; then 
	mkdir $b_dir;
fi

# Build the test executable
g++ $src \
	-o $out \
	-std=$std
