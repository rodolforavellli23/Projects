#!/bin/bash

# Compiling in Haskell

MyProgram="main.hs"

MyOutputDir="build"

MyTarget="hello"

ghc $MyProgram -hidir $MyOutputDir/ -odir $MyOutputDir/ -o ./$MyOutputDir/$MyTarget