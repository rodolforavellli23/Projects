#!/usr/bin/bash

# Print the name of the given program/file and 
# the number of bytes it occupies in memory

# Color definitions - alternative scheme

declare -g NAME_COLOR='\033[1;32m'       # Bright green for the program name
declare -g SIZE_COLOR='\033[1;38;5;208m' # Bright orange for the program size
declare -g NO_COLOR='\033[0m'            # No Color

# Function definition
countBytes() {
	# Array with sufixes
	declare -a t_bytes=( \
		"B"          \
		"KB"         \
		"MB"         \
		"GB"         \
	)
	# Index to put in the array
	declare -i Count=$(awk "BEGIN {
		i = $1;
		c = 0;
		while (i >= 1024 && c <= 3) {
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

# Variable definitions
declare -g myPad=$(printf "%4s" " ")
declare -g mySize=$(wc -c < $(which "$1"))
declare -g myResult="$(countBytes "$mySize")"

# Script Output
printf "\n%sSize of %b%s%b in disk storage: %b%s%b\n\n" \
	"$myPad"                                        \
	"$NAME_COLOR"                                   \
	"$1"                                            \
	"$NO_COLOR"                                     \
	"$SIZE_COLOR"                                   \
	"$myResult"                                     \
	"$NO_COLOR"
