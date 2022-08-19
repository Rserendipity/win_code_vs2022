#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int ar[10] = { 0 };
	int i = 0, max, j = 0;
	printf("请输入10个整数:");
	for (int i = 0; i <= 9; i++)
	{
		scanf("%d", &ar[i]);
	}
	max = ar[0];
	for (int j = 0; j <= 9; j++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
	}
	printf("%d", max);

}