#!/bin/bash

cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../

echo ""
echo "gcov result:"
echo ""
gcov main.c