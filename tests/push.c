#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = str_new();
	str_push(s, 'H');
	str_push(s, 'i');
	
	char* text = to_cstr(s);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	
	assert(str_len(s) == 2);
	assert(s->cap == MIN_CAPACITY);
	assert(strcmp(text, "Hi") == 0);
	str_free(s);
	return 0;
}