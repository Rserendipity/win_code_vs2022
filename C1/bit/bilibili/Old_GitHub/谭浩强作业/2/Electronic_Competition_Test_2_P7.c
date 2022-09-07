#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a[10] = { 0 };
	int temp;
	printf("请一共输入10个数\n");
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个数>:",i+1);
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	printf("由小到大排序：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
