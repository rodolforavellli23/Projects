#!/bin/bash

# Factorial function in bash

echo " "
read -p "Compute the factorial of: " input

input2=$input
result=1

while [ "$input2" -gt 0 ] ; do
	result=$[ $result * $input2 ]
	input2=$[ $input2 - 1 ]
done

echo " "
echo "The factorial of $input is $result"
echo " "
