#include <stdio.h>

int rewrite_strlen(char* str);

int main()
{
	char bit[] = "Hellow Warld";
	int temp = rewrite_strlen(bit);
	printf("%d", temp);
	return 0;
}

int rewrite_strlen(char* str)
{
	if (*str != '\0')
		return 1 + rewrite_strlen(str + 1);
	else return 0;
}
