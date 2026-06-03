#!/usr/bin/bash

# Variables
TARGET_DIR="./build/"
TARGET_NAME="test"
SOURCE="main.cpp"
FLAGS="-std=c++20"

# Compilation
g++ ${SOURCE} \
	${FLAGS} \
	-o ${TARGET_DIR}${TARGET_NAME}

# Run Compiled Executable
${TARGET_DIR}${TARGET_NAME}
