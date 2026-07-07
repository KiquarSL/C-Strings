#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("Magic");
	
	char* text = to_cstr(s);
	char get = *str_get(s, 1);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	printf("get by 1 index: %c\n", get);
	
	assert(get == 'a');
	assert(str_len(s) == 5);
	assert(s->cap == 7); 
	assert(strcmp(text, "Magic") == 0);
	str_free(s);
	return 0;
}