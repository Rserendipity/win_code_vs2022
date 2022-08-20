#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int input = 0;
	char fh;
	printf("请输入一个 -32768~32768之间的数>:");
	scanf("%d", &input);
	if (input > 0)
	{
		fh = '+';
	}
	else if (input == 0)
	{
		fh = '\0';
	}
	else
	{
		fh = '-';
		input = -input;
	}
	int ge = input / 1 % 10;
	int shi = input / 10 % 10;
	int bai = input / 100 % 10;
	int qian = input / 1000 % 10;
	int wan = input / 10000 % 10;
	printf("\n%c %d %d %d %d %d", fh, wan, qian, bai, shi, ge);
	return 0;
}
