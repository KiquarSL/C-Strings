#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Hello");
	
	char* text = to_cstr(s);
	char* subs = str_subs(s, 0, 4);
	
	if(subs == NULL) {
		printf("subs is NULL. Out of bounds");
		assert(0==1);
	}
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	printf("Substring by index 0, length 4: %s\n", subs);
	
	assert(strcmp(subs, "Hell") == 0);
	assert(str_len(s) == 5);
	assert(s->cap == 7); // Auto-capacity multiply 6 on 1.5
	assert(strcmp(text, "Hello") == 0);
	str_free(s);
	return 0;
}