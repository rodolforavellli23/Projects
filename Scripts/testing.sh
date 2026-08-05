#!/usr/bin/bash

# bash functions and how to invoke them

str_builder() {
	local str_result=""

	for ((i=1; i<="$1"; i++))
	do
		str_result+="$2"
	done

	echo "$str_result"
}

my_str=$(str_builder 10 "*")

printf "\n%4s|%s|\n\n" \
	" " \
	"$my_str"
