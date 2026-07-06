#include<stddef.h>
#include<stdio.h>
#include<str.h>
#include<assert.h>

int main() {
	str* s = str_new();
	printf("Length: %zu\n", s->len);
	printf("Capacity: %zu\n", s->cap);
	
	assert(str_len(s) == 0);
	assert(s->cap == MIN_CAPACITY);

	str_free(s);
	return 0;
}