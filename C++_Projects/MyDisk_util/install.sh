#!/usr/bin/bash

# Installation script

# Parameters
src="./bin/test_bin"
dest=$(which mydisk)

# Copying to /usr/bin/
sudo cp $src $dest
