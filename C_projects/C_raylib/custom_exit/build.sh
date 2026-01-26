#!/usr/bin/bash

path="~/Documentos/third_party/raylib/src"
src="./main.c"
target="./bin/custom_exit"
libraries="libraylib.a"
flags="-lm"

gcc $src \
	-I$path \
	-L$path \
	-l:$libraries \
	$flags \
	-o $target 
