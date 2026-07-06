#!/bin/bash

REBUILD=0
VERBOSE=0
CLEAN=0
GDB=0

# r - re-config with cmake
# v - verbose
# c - clean before run tests
while getopt "rvcd" opt; do
	case "$opt" in
		r) REBUILD=1 ;;
		v) VERBOSE=1 ;;
		c) CLEAN=1 ;;
		d) GDB=1 ;;
		*) break ;;
	esac
done

# Run tests with ctest
tests() {
	cd build || exit
	if [[ "$REBUILD" -eq 1 ]]; then
		cmake ..
	fi
	make
	if [[ "$VERBOSE" -eq 1 ]]; then
		if [[ "$CLEAN" -eq 1 ]]; then
			clean
		fi
		ctest -V --verbose-on-failure
	else 
		ctest
	fi
}

# Run test as binary
test() {
	cd build || exit
	if [[ "$REBUILD" -eq 1 ]]; then
		cmake ..
	fi
	make
	if [[ "$CLEAN" -eq 1 ]]; then
		clean
	fi
	
	if [[ "$GDB" -eq 1 ]]; then
		gdb ./tests/"$2"
	else
		./tests/"$2"
	fi
	
}

case "$1" in
	"tests") tests "$@" ;;
	"test") test "$@" ;;
	*) echo "Unknown command";;
esac