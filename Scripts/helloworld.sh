#!/bin/bash

var=$(bash --version)

sub_var=${var:17:39}

# Splicing strings in BASH works as follows: b=${a:x:y}
# b is the sub-string, a is the original string,
# x is the offset (starting point) and 
# y is the lenght (from how much of the string 
# beyond the offset must BASH copy to the sub-string.

echo -e "\n\tHello World! From Bash version ${sub_var}\n"
