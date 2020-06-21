#!/bin/sh
 
pattern="/* <$1> */"

lib_path="library"

filename=( $(grep -n -r -F "$pattern" $lib_path | awk '{split($0,a,":");print a[1]}') )

if [ -z "$filename" ]
then
	echo "file not found"
	exit 0
else
	echo "including from ${filename[0]}"
fi

nums=( $(grep -n -F "$pattern" "${filename[0]}" | awk '{split($0,a,":");print a[1]}') )

n=( $(grep -n -F "/*-*/" main.cpp | awk '{split($0,a,":");print a[1]}') )

cat main.cpp > .lib_tmp

head -$n .lib_tmp > main.cpp
head -$((${nums[1]} - 1)) "${filename[0]}" | tail -n +$((${nums[0]} + 1)) >> main.cpp
tail -n +$(($n + 1)) .lib_tmp >> main.cpp
