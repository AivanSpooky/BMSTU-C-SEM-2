#!/bin/bash

test_ok="0"
count_errors=0

files="../data/pos_??_in.txt"
for file_in in $files; do
	number=$(echo "$file_in" | grep -o "[0-9]*")

	file_out="../data/pos_""$number""_out.txt"

	if [ -f "$file_out" ]; then
		./pos_case.sh $file_in $file_out
        error="$?"
	else
		echo "pos_""$number""_in"": FAILED"
		count_errors=$((count_errors + 1))
		continue
	fi

	if [ "$error" -eq "$test_ok" ]; then
		echo "pos_""$number""_in"": PASS"
	else
		echo "pos_""$number""_in"": FAIL"
		count_errors=$((count_errors + 1))
	fi
done

files="../data/neg_??_in.txt"
for file_in in $files; do
	number=$(echo "$file_in" | grep -o "[0-9]*")
	if [ -z "$number" ]; then
		break
	fi

    ./neg_case.sh $file_in
    error="$?"

	if [ "$error" -eq "$test_ok" ]; then
		echo "neg_""$number""_in"": PASS"
	else
		echo "neg_""$number""_in"": FAIL"
		count_errors=$((count_errors + 1))
	fi
done

exit "$count_errors"