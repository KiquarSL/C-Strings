# Strings lib

**WARNING**: text in str is not c-string and not correct print. Use `to_cstr` for it.

## Generate docs
```sh
doxygen

# Open docs/html/index.html
```

## Scripts
#### run.sh

Use for fast run tests.

**Flags**
* `-r` - reconfigurate project with cmake
* `-c` - clean before run tests
* `-v` - verbose for ctest

**Commands**
* `test` - run one test as binary
* `tests` - run tests with ctest

**Usage**
```bash
./run <cmd> [flags]
```

**Example**
```bash
./run.sh test test_push_cstr -r -c -v
```

#### tests/add_test.sh

Add test in `tests/CMakeLists.txt`

**Usage**
```bash
cd tests
./add_test.sh <Test name> <Test source file (.c)>
```

**Example**
```bash
cd tests
./add_test.sh push push.c
```