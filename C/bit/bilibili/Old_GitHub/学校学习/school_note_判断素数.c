#include <stdio.h>


int shuru();
int panduan();


int main()
{
	panduan();
	return 0;
}


int shuru()
{
	int a;
	scanf_s("%d", &a);
	return (a);
}


int panduan()
{
	int x, i, temp;
	x = shuru();
	if (x <= 1)
	{
		printf("请输入大于1的整数进行判断！\n");
	}
	else
	{
		for (i = 2; i < x; i++)
		{
			temp = x % i;
			if (temp == 0)
			{
				printf("不是素数！\n");
				break;
			}
			else if (i >= x / 2)
			{
				printf("是素数！\n");
				break;
			}
		}
	}
	return 0;
}
