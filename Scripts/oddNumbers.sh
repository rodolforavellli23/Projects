#!/bin/bash

declare -a arr;

arr=({0..32});

echo -e " ";

for num in "${arr[@]}"; do
	if (( "${arr[${num}]}" & 1 )); then
		echo -n "${arr[${num}]} ";
	fi
done

echo -e "\n";
