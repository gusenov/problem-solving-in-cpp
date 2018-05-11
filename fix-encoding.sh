#!/bin/bash
#set -x  # echo on

convert_files_encoding_sh="/home/abbas/repo/lang/sh/convert-files-encoding-sh/convert-files-encoding.sh"

target_project_dir="$(pwd)/"  # should include a trailing slash.

"$convert_files_encoding_sh" \
    -p="$target_project_dir" \
    -t="*.hpp *.cpp" \
    -i="windows-1251" \
    -o="utf-8"

# Предполагается, что все файлы в папке target_project_dir
# либо в кодировке utf-8, либо в кодировке windows-1251.

