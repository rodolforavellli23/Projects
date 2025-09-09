#!/bin/bash

# Notes: The 'while read user; do' construction works like a 'for each' loop, but in BASH script syntax. 

# Color definitions - alternative scheme

USER_COLOR='\033[1;32m'    # Bright green for all users
LOGGED_COLOR='\033[1;36m'  # Bright cyan for logged-in users
NC='\033[0m'               # No Color

# List all human users
all_users=$(awk -F: '$3 >= 1000 && $1 != "nobody" {print $1}' /etc/passwd)

# List currently logged-in users
logged_in_users=$(who | awk '{print $1}' | sort | uniq)

# Display the results with colors
echo -e "\n\tAll Human Users In This System:"
echo "$all_users" | while read user; do
    echo -e "\t${USER_COLOR}$user${NC}"
done

echo -e "\n\t${HEADER_COLOR}Currently Logged-In Human Users:${NC}"
echo "$logged_in_users" | while read user; do
    echo -e "\t${LOGGED_COLOR}$user${NC}"
done
echo
