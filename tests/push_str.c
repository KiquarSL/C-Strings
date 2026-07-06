#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Hello, ");
	str* s2 = to_str("World!");
	str_push_str(s, s2);
	
	char* text = to_cstr(s);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	
	assert(str_len(s) == 6);
	assert(s->cap == MIN_CAPACITY);
	assert(strcmp(text, "Hello, World!") == 0);
	str_free(s);
	return 0;
}