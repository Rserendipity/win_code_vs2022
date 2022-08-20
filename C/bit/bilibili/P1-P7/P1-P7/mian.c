#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	char arr[] = "China";
	char* p = arr;
	while (*p != '\0')
	{
		*p += 3;
		p++;
	}

	printf("%s", arr);

	return 0;
}

