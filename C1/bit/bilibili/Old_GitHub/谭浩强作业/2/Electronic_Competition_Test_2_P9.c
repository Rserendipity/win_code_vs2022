#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	double n = 0, sum = 1;
	printf("请输入你要求几的阶层>:");
	scanf("%lf", &n);
	while (n)
	{
		sum = sum * n;
		n--;
	}
	printf("结果为：%.0lf", sum);
	return 0;
}
