#!/usr/bin/bash

# Installation script

# Parameters
target="bin_name" # This will be the name of the binary to be installed
src="./bin/test_bin"
dest="/usr/bin/$(target)"

# Copying to /usr/bin/
sudo cp $src $dest
