#!/bin/bash

# Usage as `./add_test.sh <Test name> <Source file>`

if [[ -f "$2" ]]; then
	echo "
add_executable($1 $2)
target_link_libraries($1 strings)
add_test(NAME $1 COMMAND $1)" >> CMakeLists.txt
fi