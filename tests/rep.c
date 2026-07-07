#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>
#include<string.h>

int main() {
	str* s = to_str("You is stupid");
	
	char* text = to_cstr(s);
	int rep = str_rep(s, "stupid", "really stupid, lol");
	char* new_text = to_cstr(s);
	
	printf("Length: %zu\n", str_len(s));
	printf("Capacity: %zu\n", s->cap);
	printf("Text: %s\n", text);
	printf("New text: %s\n", new_text);
	
	assert(strcmp("You is really stupid, lol", new_text) == 0);
	
	str_free(s);
	return 0;
}