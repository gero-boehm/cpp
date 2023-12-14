#!/bin/bash

output=$(cat)

if echo "$output" | grep -q "LEAK SUMMARY" ; then
	echo -e "\033[0;31m$output\033[0m"
else
	echo -e "\033[1;32mOK!\033[0m"
fi
