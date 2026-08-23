#!/usr/bin/bash

# Print the name of the given program/file and
# the number of bytes it occupies in memory

# Definitions: pad, colors, usage message

# Decorative blank pad
myPad=$(printf "%4s" " ")

# Bright green for the program name
NAME_COLOR='\033[1;32m'

# Bright orange for the program size
SIZE_COLOR='\033[1;38;5;208m'

# Bright red for thr error color
ERROR_COLOR='\033[38;2;255;102;102m'

# No Color
NO_COLOR='\033[0m'

# Usage instructions
usage="\n${myPad}${NAME_COLOR}Usage:${NO_COLOR}"
usage+="\n${myPad}<This Script> <Program Name>\n"

# Function definition
countBytes() {
	# Array with sufixes
	declare -a t_bytes=( \
		"B"              \
		"KB"             \
		"MB"             \
		"GB"             \
	)
	# Index to put in the array
	declare -i Count=$(awk "BEGIN {
		i = $1;
		c = 0;
		while (i >= 1024 && c <= ${#t_bytes[@]}) {
			i /= 1024;
			c++;
		}
		print c;
	}")
	# Size to print
	declare Size=$(awk "BEGIN {
		i = $1;
		while (i > 1024) {
			i /= 1024;
		};
		printf(\"%.1f\", i);
	}")
	# Output
	echo "${Size} ${t_bytes[${Count}]}"
}

# Error Checking
if [[ "$#" -eq 0 ]]; then
	error1="\n${myPad}${ERROR_COLOR}Error: ${NO_COLOR}No argument has been passed"
	echo -e "$error1\n$usage"
	exit 1
elif [[ "$#" -gt 1 ]]; then
	error2="\n${myPad}${ERROR_COLOR}Error: ${NO_COLOR}This script may only accept one argument"
	echo -e "$error2\n$usage"
	exit 1
elif ! ( which "$1" ) &> /dev/null; then
	error3="\n${myPad}${ERROR_COLOR}Error: ${NO_COLOR}No program with this name is installed"
	echo -e "$error3\n$usage"
	exit 1
fi

# Note: 2> /dev/null will redirect any error messages to /dev/null, effectively
# suppressing them. &> /dev/null will suppress both the stdout and stderr streams.

# Variable definitions
mySize=$(wc -c < $(which "$1"))
myResult="$(countBytes "$mySize")"

# Script Output
myOutput="\n${myPad}Size of ${NAME_COLOR}${1}${NO_COLOR} in disk storage: ${SIZE_COLOR}${myResult}${NO_COLOR}\n"

echo -e "$myOutput"
