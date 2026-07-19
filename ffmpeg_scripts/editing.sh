#!/usr/bin/bash

# Non-contiguous audio extraction with ffmpeg

# Must provide user input:
# ./editing.sh input.mp3 output.mp3
input="$1"
output="$2"

# Segment 1: 0:44 to 0:57 (13 seconds)
ffmpeg -i "$input" -ss 00:00:44 -t 00:00:13 -c:a copy -vn segment1.mp3

# Segment 2: 2:48 to 3:37 (49 seconds)
ffmpeg -i "$input" -ss 00:02:48 -t 00:00:49 -c:a copy -vn segment2.mp3

# Create a list file for concatenation
cat > list.txt <<EOF
file 'segment1.mp3'
file 'segment2.mp3'
EOF

# Merge the segments
ffmpeg -f concat -safe 0 -i list.txt -c copy $output

# Clean up
rm segment1.mp3 segment2.mp3 list.txt
