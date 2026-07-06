#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "str.h"

str* str_realloc(str* s, size_t new_size) {
	s->cap = new_size;
	s->text = realloc(s->text, s->cap);
	return s;
}

bool str_is_fit(str* s, size_t len) {
	return s->len + len < s->cap;
}

// Public

str* str_new() {
	str* s = malloc(sizeof(str));
	s->cap = MIN_CAPACITY;
	s->len = 0;
	s->text = malloc(sizeof(s->cap));
	return s;
}

str* to_str(char *text) {
	str* s = malloc(sizeof(str));
	s->text = malloc(strlen(text));
	strcpy(s->text , text);
	size_t len = strlen(text);
	s->cap = len*1.5;
	s->len = len;
	return s;
}

char* to_cstr(str* s) {
	size_t len = s->len;
	char* text = malloc(len+1);
	memcpy(text, s->text, len);
	// C-Strings require '\0' for correct 
	text[len] = '\0';
	return text;
}

void str_free(str* s) {
	free(s->text);
	free(s);
}

size_t str_len(str *s) {
	return s->len;
}

// push
str* str_push(str* s, char c) {
	if(!str_is_fit(s, 1)) {
		str_realloc(s, s->cap*2);
	}
	s->text[s->len] = c;
	s->len += 1;
	return s;
}

str* str_push_cstr(str* s, char* text) {
	size_t text_len = strlen(text);
	if(!str_is_fit(s, text_len)) {
		size_t new_cap = (s->cap + text_len) * 2;
		str_realloc(s, new_cap);
	}
	memcpy(s->text+s->len, text, text_len);
	s->len += text_len;
	return s;
}

str* str_push_str(str* s, str* s2) {
	size_t text_len = s2->len;
	if(!str_is_fit(s, text_len)) {
		size_t min_cap = s->cap + text_len;
		size_t new_cap = min_cap * 1.5;
		str_realloc(s, new_cap);
	}
	memcpy(s->text+s->len, s2->text, text_len);
	s->len += text_len;
	return s;
}
// push end

// insert
str* str_ins(str* s, size_t pos, char c) {
	if(!str_is_fit(s, 1)){
		str_realloc(s, s->cap*2);
	}
	memmove(s->text+pos+1, s->text+pos, s->len-pos);
	s->text[pos] = c;
	s->len += 1;
	return s;
}

str* str_ins_cstr(str* s, size_t pos, char* text) {
	size_t len = strlen(text);
	if(!str_is_fit(s, len)){
		size_t min_cap = s->len + len;
		size_t new_cap = min_cap * 1.5;
		str_realloc(s, new_cap);
	} 
	memmove(s->text+pos+len, s->text+pos, s->len-pos);
	memcpy(s->text+pos, text, len);
	s->len += len;
	return s;
}

str* str_ins_str(str* s, size_t pos, str* s2) {
	size_t len = s2->len;
	if(!str_is_fit(s, len)) {
		size_t min_cap = s->len + len;
		size_t new_cap = min_cap * 1.5;
		str_realloc(s, new_cap);
	}
	memmove(s->text+pos+len, s->text+pos, s->len-pos);
	memcpy(s->text+pos, s2->text, len);
	s->len += len;
	return s;
}
// insert end