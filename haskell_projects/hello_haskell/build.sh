#!/bin/bash

# Compiling in Haskell

MyProgram="main.hs"

MyOutputDir="build"

MyTarget="hello"

MyFlags="-dynamic"

ghc $MyProgram \
    -hidir $MyOutputDir/ \
    -odir $MyOutputDir/ \
    $MyFlags \
    -o ./$MyOutputDir/$MyTarget

strip ./$MyOutputDir/$MyTarget
