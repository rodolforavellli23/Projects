#!/bin/bash

# What this does is append the first line with a '!' character
# Where 1 - first line
# 	s/ - substitution operation
# 	$/ - to end-of-file
# 	!/ - text to be appended to the end-of-file, could be <any char string>/ as well

sed -i '1s/$/!/' test.txt
