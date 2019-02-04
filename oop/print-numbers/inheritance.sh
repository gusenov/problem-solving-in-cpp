#!/bin/bash

input_file="inheritance.gv"
output_file="inheritance.png"

#while inotifywait -e close_write "$input_file"; do dot -Tpng "$input_file" -o "$output_file"; done
echo "$input_file" | entr -s "clear; dot -Tpng \"$input_file\" -o \"$output_file\""

