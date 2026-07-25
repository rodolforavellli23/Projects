#!/usr/bin/awk -f

# My first awk script

BEGIN {
	# Variables
	pad = sprintf("%4s", " ");
	one = "Hello";
	two = "World!";
	
	# Getting the version of awk
	cmd = "awk --version";
	output = "";
	
	while ((cmd | getline line) > 0) {
		output = output line "\n"
	};

	close(cmd);
	
	# Get the version substring
	version = substr(output, 1, 13);

	# Text Output
	printf "\n" pad one " " two " From " version "\n";
} 
