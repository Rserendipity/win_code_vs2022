#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int bijiao(int a[10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i != j)
			{
				if (a[i] == a[j])
				{
					a[j] = '\0';
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] != '\0')
		{
			printf("%d ", a[i]);
		}
	}
	return 0;
}
int main()
{
	int a[10] = { 0 };
	printf("请一共输入10个数\n");
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个数>:",i+1);
		scanf("%d", &a[i]);
	}
	bijiao(a);
	return 0;
}
