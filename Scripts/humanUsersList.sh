#!/bin/bash

# List all human users
all_users=$(awk -F: '$3 >= 1000 && $1 != "nobody" {print $1}' /etc/passwd)

# List currently logged-in users
logged_in_users=$(who | awk '{print $1}' | sort | uniq)

# Display the results
echo -e "\n\tAll Human Users In This System:"
echo -e "\t$all_users\t"
echo -e "\n\tCurrently Logged-In Human Users:"
echo -e "\t$logged_in_users\n"
