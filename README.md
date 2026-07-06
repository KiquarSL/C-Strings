# Strings lib


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

**WARNING**: text in str is not c-string and not correct print. Use `to_cstr` for it.

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

## Docs

```c
/// Return new str with minimal capacity
str* str_new();

// Exmaple
str* s = str_new();
```

```c
/// Return new str from c-string
str* to_str(char* text);

// Exmaple
str* s = to_str("Kiquar");
```

```c
/// Free str and text inside
void str_free(str* s);

// Exmaple
str_free(s);
```

```c
/// Push char to end of string
str* str_push(str* s, char c);

// Exmaple
str* s = to_str("Hell");
str_push(s, 'o');
```

```c
/// Push c-string to end of string
str* str_push_cstr(str* s, char* text);

// Exmaple
str* s = to_str("Hello");
str_push_cstr(s, ", World");
```

```c
/// Push str2 to end of str
str* str_push_str(str* s, str* s2);

// Exmaple
str* s = to_str("Hello, ");
str* s2 = to_str("World!");
str_push_str(s, s2);
```

```c
/// Insert char by position
str* str_ins(str* s, size_t pos, char c);

// Exmaple
str* s = to_str("Helo");
str_ins(s, 2, 'l');
```

```c
/// Insert c-string by position
str* str_ins_cstr(str* s, size_t pos, char* text);

// Exmaple
str* s = to_str("Hello, ");
str_ins_cstr(s, 7, "World!);
```

```c
/// Insert str by position
str* str_ins_str(str* s, size_t pos, str* s2);

// Exmaple
str* s = to_str("Hello, ");
str* s2 = to_str("Kiquar!");
str_ins_str(s, 7, s2);
```

```c
/// Get c-string from str (copy with '\0')
char* to_cstr(str* s);

// Exmaple
str* s = to_str("Hello");
printf("%s\n", to_cstr(s));
```

```c
/// Return string length
size_t str_len(str* s);

// Exmaple
str* s = to_str("Hello");
printf("Length string: %zu\n", str_len(s));
```