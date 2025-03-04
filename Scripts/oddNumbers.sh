#!/bin/bash

declare -a array;
declare -a sub_arr; # Declare the array variables to make sure that they will be trated by bash as such
declare -i i;

i=0; 
array=({0..32});
	
# The binary form of odd numbers always ends in 1

for n in "${array[@]}"; do
	if  (("${array[${n}]}" & 1)); then
		sub_arr+=($n);
	fi
done

i=${#sub_arr[@]}; # Using the hashtag symbol you can access the index length of an array

echo -e "\n\tThe odd numbers sub array of 'arr' is of size ${i}";

echo -e "\n\t${sub_arr[*]}\n";
