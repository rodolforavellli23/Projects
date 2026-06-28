#!/usr/bin/bash

# Script to slim down large pdf documents 

# Global Variables
USERDICT="userdict begin \
	/ColorImgDict << /QFactor 0.15 >> def \
	/GrayImgDict << /QFactor 0.15 >> def \
end"

PAD=$(printf "%4c" " ")

USSAGE=""
USSAGE+="\n${PAD}!!! USAGE OF THIS SCRIPT !!!\n"
USSAGE+="\n${PAD}User must provide an INPUT_PDF to be slimed down,"
USSAGE+="\n${PAD}and a OUTPUT_PDF name for ghostscript to write to, like so:\n"
USSAGE+="\n${PAD}this_script.sh /PATH/TO/INPUT_PDF /PATH/TO/OUTPUT_PDF\n"

# Check to see if INPUT_PDF and OUTPUT_PDF arguments have been provided
if [[ $# -lt 2 ]]; then
	echo -e "\n\n${PAD}This script requires both INPUT_PDF and OUTPUT_PDF arguments\n${USSAGE}"
	exit 1
elif [[ $# -gt 2  ]]; then
	echo -e "\n\n${PAD}Only give two arguments to this script, an INPUT_PDF, and a OUTPUT_PDF\n${USSAGE}"
	exit 1
elif [[ ! -f "$1" ]]; then
	echo -e "\n\n${PAD}Provided INPUT_PDF either does not exist, or isn't a regular file\n${USSAGE}"
	exit 1
elif [[ "$2" == "$1" ]]; then
	echo -e "\n\n${PAD}Provided OUTPUT_PDF must be diferent from INPUT_PDF!\n${USSAGE}"
	exit 1
fi

# Should both arguments pass the checks above, assign them to INPUT_PDF and 
INPUT_PDF="$1"
OUTPUT_PDF="$2"

# Calling ghostscript
gs \
	-sDEVICE=pdfwrite \
	-dCompatibilityLevel=1.4 \
	-dPDFSETTINGS=/ebook \
	-dNOPAUSE \
	-dQUIET \
	-dBATCH \
	-dPDFFitPage \
	-dFIXEDMEDIA \
	-sPAPERSIZE=a4 \
	-sOutputFile="${OUTPUT_PDF}" \
	-c "${USERDICT}" \
	-f "${INPUT_PDF}"

# Ghostscript has its own error messaging system, but I put like to put this at the end anyway
if [[ "$?" -eq 0 ]]; then
	echo -e "\n\n${PAD}Success!\n\n"
else
	echo -e "\n\n${PAD}Failure!\n\n"
	exit 1
fi
