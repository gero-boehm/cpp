#!/bin/bash

config_file="./config.yaml"
makefile_path="./Makefile"

tests=()

while IFS= read -r line; do

	if [[ ! "$line" =~ ^[[:space:]]+- ]] && [[ -n $tests ]]; then
		formatted_tests=""
		for test in "${tests[@]}"; do
			formatted_tests+=$'\t'"$test"$'\n'
		done

		tmp_file=$(mktemp)
		echo "$formatted_tests" > "$tmp_file"

		sed -i "" "/valgrind: all/r $tmp_file" "$path/Makefile"

		rm "$tmp_file"

		tests=()
	fi

	if [[ "$line" =~ ^cpp[0-9]+: ]]; then
		folder="${line%%:*}"
	elif [[ "$line" =~ ^[[:space:]]+ex[0-9]+: ]]; then
		subfolder=$(echo "${line%%:*}" | sed 's/^[[:space:]]*//')
		path="./$folder/$subfolder"
		mkdir -p "$path"
		cp "$makefile_path" "$path/Makefile"
	elif [[ "$line" =~ ^[[:space:]]+name: ]]; then
		name="${line##*: }"
		sed -i "" "s/NAME=/NAME=$name/" "$path/Makefile"
	elif [[ "$line" =~ ^[[:space:]]+- ]]; then
		test="${line##*- }"
		tests+=("$test")
	fi
done < "$config_file"
