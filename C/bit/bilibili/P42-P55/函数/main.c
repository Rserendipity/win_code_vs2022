#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

static int i = 0;

int test1()
{
	i++;
	return i > 100 ? i : test2();
}


int test2()
{
	i++;
	return i > 100 ? i : test1();
}



int main()
{
	//printf("%d", test2());
	printf("%d", printf("%d", printf("%d",43))); // Êä³ö4321

	return 0;
}


