#!/bin/bash

config_file="./config.yaml"
makefile_path="./Template"
gitignore_path="./.gitignore"

tests=()
names=()

names+=("**/obj")

while IFS= read -r line; do

	if [[ ! "$line" =~ ^[[:space:]]+- ]] && [[ -n $tests ]]; then
		formatted_tests=""
		for test in "${tests[@]}"; do
			test=$(echo "$test" | sed 's/VALGRIND/valgrind --leak-check=full --show-leak-kinds=all .\/\$(NAME)/')
			if [[ "$test" =~ END ]]; then
				test=$(echo "$test" | sed 's/END/2>\&1 | ..\/..\/eval.sh/')
			else
				test+=" 2>&1 | ../../eval.sh"
			fi
			formatted_tests+=$'\t'"$test"$'\n'
		done

		tmp_file=$(mktemp)
		echo -n "$formatted_tests" > "$tmp_file"
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
		names+=($(echo "$path/$name" | sed 's/^\.\///'))
		sed -i "" "s/NAME=/NAME=$name/" "$path/Makefile"
	elif [[ "$line" =~ ^[[:space:]]+- ]]; then
		test="${line##*- }"
		tests+=("$test")
	fi
done < "$config_file"

echo -n > "$gitignore_path"
for name in "${names[@]}"; do
	echo "$name" >> "$gitignore_path"
done