#!/usr/bin/bash

# ffmpeg basic audio extraction
# Usage: ./basic_extraction.sh file output

# Set default output directory
OUTPUT_DIR="$HOME/Documentos/ffmpeg_audio_extraction/audio/"

# Create the output directory if it doesn't already exist
if [ ! -d "$OUTPUT_DIR" ]; then
	mkdir -p "$OUTPUT_DIR"
fi

PAD=$(printf "%4c" " ")

USSAGE=""
USSAGE+="\n${PAD}!!! USAGE OF THIS SCRIPT !!!\n"
USSAGE+="\n${PAD}User must provide an INPUT_FILE .mp4 to be extracted,"
USSAGE+="\n${PAD}and an OUTPUT_FILE .m4a name for ffmpeg to write to, like so:\n"
USSAGE+="\n${PAD}this_script.sh /PATH/TO/INPUT_FILE.mp4 /PATH/TO/OUTPUT_FILE.m4a\n"

# Check to see if INPUT_FILE and OUTPUT_FILE arguments have been provided
if [[ "$#" -lt 2 ]]; then
        echo -e "\n\n${PAD}This script requires both INPUT_FILE and OUTPUT_FILE arguments\n${USSAGE}"
        exit 1
elif [[ "$#" -gt 2 ]]; then
        echo -e "\n\n${PAD}Only give two arguments to this script, an INPUT_FILE, and a OUTPUT_FILE\n${USSAGE}"
        exit 1
elif [[ ! -f "$1" ]]; then
        echo -e "\n\n${PAD}Provided INPUT_FILE either does not exist, or isn't a regular file\n${USSAGE}"
        exit 1
elif [[ "$2" == "$1" ]]; then
        echo -e "\n\n${PAD}Provided OUTPUT_FILE must be diferent from INPUT_FILE!\n${USSAGE}"
        exit 1
fi

# Should both arguments pass the checks above, assign them to INPUT_FILE and 
INPUT_FILE="$1"
OUTPUT_FILE="$2"

# Extract Audio
echo "Ripping audio from: $INPUT_FILE"
ffmpeg \
	-i "$1" \
	-vn \
	-acodec copy "$OUTPUT_FILE"

# Move OUTPUT_FILE to OUTPUT_DIR
mv "$OUTPUT_FILE" "$OUTPUT_DIR"

if [ $? -eq 0 ]; then
    echo -e "\n\n✓ Process Complete!"
else
    echo -e "\n\n✗ Process Failed!"
    exit 1
fi
