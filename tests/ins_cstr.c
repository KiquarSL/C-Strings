#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Hello, !");
	str_ins_cstr(s, 7, "World");
	
	char* text = to_cstr(s);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	
	assert(str_len(s) == 13);
	assert(s->cap == 19); // Auto-capacity multiply 15 on 1.5
	assert(strcmp(text, "Hello, World!") == 0);
	str_free(s);
	return 0;
}