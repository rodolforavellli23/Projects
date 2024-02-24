#!/bin/bash/

echo "Please identify yourself:  "
read text

case ${text} in 
	rodolfo | root)
	echo "Hello User!"
	;;
	help)
	echo "Input Username!"
	;;
	*)
	echo "Access Denied!"
	esac

