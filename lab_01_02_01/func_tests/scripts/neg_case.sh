#!/bin/bash

if [ $# -ne 1 ]; then
	exit 1
fi

ok="0"
fail="1"
in_test=$1
tmp_out="tmp_out.txt"
command="../../app.exe"

$command < "$in_test" > "$tmp_out"
error="$?"

if [[ $error -ne 0 ]]; then
    exit 0
else
    exit 1
fi
rm -f "tmp_out.txt"