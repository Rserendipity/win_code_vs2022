#include<stdio.h>
#include<conio.h> 
#include<string.h>
int main()
{
	int a[10];
	int temp, i, j;
	//实现动态输入
	printf("输入十个数，自动排序!\n");
	for ( i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for ( j = 0; j < 9; j++)
	{
		for ( i = 0; i < 9 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	//实现输出
	printf("由小到大排序：");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	printf("由大到小排序：");
	for (j = 9; j >= 0; j--)
	{
		printf("%d\t", a[j]);
	}
	return 0;
}
