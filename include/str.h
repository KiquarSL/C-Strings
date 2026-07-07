#ifndef STR_H
#define STR_H

#define MIN_CAPACITY 10

#include<stddef.h>

typedef struct str {
	char* text;
	size_t len;
	size_t cap;
} str;


/// Return new str with minimal capacity
str* str_new();

/// Return new str with text
str* to_str(char* text);

/// Free str and text inside
void str_free(str* s);

/// Push char to end of string
str* str_push(str* s, char c);

/// Push c-string to end of string
str* str_push_cstr(str* s, char* text);

/// Push str2 to end of str
str* str_push_str(str* s, str* s2);

/// Insert char by position
str* str_ins(str* s, size_t pos, char c);

/// Insert c-string by position
str* str_ins_cstr(str* s, size_t pos, char* text);

/// Insert str by position
str* str_ins_str(str* s, size_t pos, str* s2);

/// Get c-string from str (copy with '\0')
char* to_cstr(str* s);

/// Return string length
size_t str_len(str* s);

/// Get char pointer by index
/// Return NULL by out of bounds
char* str_get(str* s, size_t index);

/// Substring by index with length
/// Return NULL by out of bounds
char* str_subs(str* s, size_t index, size_t len);

/// Split string with divider
/// Return list of c-strings
char** str_split(str* s, char divider);

#endif