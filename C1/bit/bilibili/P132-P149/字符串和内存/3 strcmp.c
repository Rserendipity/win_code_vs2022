#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int myStrcmp(const char* dest, const char* souse) {
	assert(dest && souse);
	
	while (*dest == *souse) {
		if (*dest == '\0')
			return 0;
		dest++;
		souse++;
	}
	return *dest - *souse;
}

int main()
{
	char str[10] = "abcd";
	char* p = "abc";
	printf("%d", myStrcmp(str, p));
}