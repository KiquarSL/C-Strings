#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>

int main() {
	str* s = to_str("Hello, I'm Kiquar. Hello...");
	
	char* text = to_cstr(s);
	
	ssize_t lfind = str_lfind(s, "Hello");
	ssize_t rfind = str_rfind(s, "Hello");
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	printf("Left finded at: %zu\n", lfind);
	printf("Right finded at: %zu\n", rfind);
	
	assert(lfind == 0);
	assert(lfind == 19);
	
	str_free(s);
	return 0;
}