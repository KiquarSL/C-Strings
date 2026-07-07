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
	if(s == NULL) {
		return NULL;
	}
	s->cap = MIN_CAPACITY;
	s->len = 0;
	s->text = malloc(sizeof(s->cap));
	if(s->text == NULL) {
		free(s);
		return NULL;
	}
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

splited* str_split(str* s, char divider) {
	size_t strs_size = sizeof(char*) * 10;
	char** strs = malloc(strs_size);
	size_t strs_last = 0;
	size_t start = 0;
	
	for (size_t i=0; i<s->len; i++) {
		// Not using cheking on error because get char inside text
		if(*str_get(s, i) == divider){
			if(strs_last >= strs_size) {
				strs_size *= 1.5;
				strs = realloc(strs, strs_size);
			}
			
			size_t len = i-start;
			
			strs[strs_last] = malloc(len+1);
			
			char* subs = str_subs(s, start, len);
			if(subs == NULL) {
				for(size_t j=0; j<strs_last; j++) {
					free(strs[j]);
				}
				free(strs);
				return NULL;
			}
			
			memcpy(strs[strs_last], subs, len);
			strs[strs_last][len] = '\0';
			start = i+1; // +1 for skip divider
			
			strs_last++;
		}
	}
	if(start < s->len) {
		size_t len = s->len-start;	
		strs[strs_last] = malloc(len+1);
		
		char* subs = str_subs(s, start, len);
		if(subs == NULL) {
			for(size_t j=0; j<strs_last; j++) {
				free(strs[j]);
			}
			free(strs);
			return NULL;
		}
		
		memcpy(strs[strs_last], subs, len);
		strs[strs_last][len] = '\0';
		
		strs_last++;
	}
	splited* spltd = malloc(sizeof(splited));
	spltd->text = strs;
	spltd->size = strs_last;
	return spltd;
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

char* str_get(str* s, size_t index) {
	if(index >= s->len) {
		return NULL;
	}
	return &s->text[index];
}

char* str_subs(str* s, size_t index, size_t len) {
	if(index >= s->len || index+len > s->len) {
		return NULL;
	}
	char* copy = malloc(len+1);
	if (copy == NULL) {
		return NULL;
	}
	memcpy(copy, s->text+index, len);
	copy[len] = '\0';
	return copy;
}

ssize_t str_lfind(str* s, char* to_find) {
	size_t len = strlen(to_find);
	ssize_t pos = -1;
	for(size_t i=0; i<s->len; i++) {
		if(i+len >= s->len) {
			break;
		}
		char* subs = str_subs(s, i, len);
		if(strcmp(subs,to_find) == 0) {
			pos = i;
			break;
		}
	}
	return pos;
}

ssize_t str_rfind(str* s, char* to_find) {
	size_t len = strlen(to_find);
	if (len > s->len) {
		return -1;
	}
	ssize_t pos = -1;
	for(size_t i=s->len-1-len; i>= 0; i--) {
		char* subs = str_subs(s, i, len);
		if(strcmp(subs,to_find) == 0) {
			pos = i;
			break;
		}
	}
	return pos;
}

int str_rep(str* s, char* from, char* to) {
	size_t from_len = strlen(from);
	if (from_len > s->len) {
		return 1;
	}
	for (size_t i=0; i<s->len; i++) {
		char* subs = str_subs(s, i,from_len);
		if (strcmp(subs, from) == 0) {
			size_t to_len = strlen(to);
			
			int diff = from_len-to_len;
			diff = abs(diff);
			s->len += diff;
			if(!str_is_fit(s, diff)) {
				str_realloc(s, s->len + diff);
			}
			
			memmove(s->text+i+to_len, s->text+i+to_len+1, from_len);
			memcpy(s->text+i, to, to_len);
			return 0;
		}
	}
	return 1;
}