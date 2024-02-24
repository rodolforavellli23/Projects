#!/bin/bash/

if [ ${1,,} = rodolfo ]; then
	echo "Welcome User!"
elif [ ${1,,} = help ]; then
	echo "Input Username!"
else
	echo "Access Denied!"
fi
