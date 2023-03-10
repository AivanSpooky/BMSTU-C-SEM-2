#!/bin/bash

cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../

echo ""
echo "Coverage (in %):"
gcov main.c > "tmp.txt"
var=$(cat tmp.txt) 
echo ${var#*:} | sed 's/%*$/ /g' | sed 's/ .*//'
rm -f "tmp.txt"