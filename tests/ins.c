#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Hllo!");
	str_ins(s, 1, 'e');
	
	char* text = to_cstr(s);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	
	assert(str_len(s) == 6);
	assert(s->cap == 7); // Auto-capacity multiply 6 on 1.5
	assert(strcmp(text, "Hello!") == 0);
	str_free(s);
	return 0;
}