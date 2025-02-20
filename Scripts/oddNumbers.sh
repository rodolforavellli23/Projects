#!/bin/bash

declare -a arr;

arr=({0..16});

for num in "${arr[@]}"; do
	if (( "${arr[${num}]}" & 1 )); then
		sub_arr+="${arr[${num}]} ";
	fi
done

echo -e "\n\tOdd Numbers from 0 to 16: ${sub_arr}\n";
