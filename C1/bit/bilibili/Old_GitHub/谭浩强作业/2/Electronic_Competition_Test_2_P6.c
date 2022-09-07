#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a[10] = { 0 };
	int temp1, temp2 = 0, max;
	printf("请一共输入10个数\n");
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个数>:",i+1);
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			temp2 = i;
		}
	}
	printf("最大的是：%d，它是第%d个数", max,temp2+1);
	return 0;
}
