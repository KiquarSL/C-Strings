#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Hi Some 124");
	
	char* text = to_cstr(s);
	char** split = str_split(s, ' ');
	printf("Strings:\n");
	for(size_t i=0; i<3; i++) {
		printf("%s\n", split[i]);
	}
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	
	assert(str_len(s) == 11);
	assert(s->cap == 16); // Auto-capacity multiply 6 on 1.5
	assert(strcmp(text, "Hi Some 124") == 0);
	str_free(s);
	return 0;
}