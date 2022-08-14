#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int (*pfArr[5])(int, int) = { NULL };
	int sz = sizeof(pfArr) / sizeof(pfArr[0]);
	printf("%d\n", sz);
	return 0;
}