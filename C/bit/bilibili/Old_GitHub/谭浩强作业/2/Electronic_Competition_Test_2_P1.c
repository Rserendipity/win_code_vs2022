#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int sum()
{
	int temp = 0, sum = 0;
	printf("\n");
	while (temp <= 1000)
	{
		sum = sum + temp;
		temp++;
	}
	printf("1~1000的和为：%d\n\n\n", sum);
	return 0;
}
int zhengchu()
{
	int temp1 = 1, temp2 = 0, sum = 0, tj1 = 0, tj2 = 0, tj3 = 0, tj = 0;//temp1控制循环 temp2控制输出一行为10个数
	printf("\n1~1000中能被3整除或者个十百位有3的数据：\n");
	while (temp1 <= 1000)
	{
		tj = tj1 = tj2 = tj3 = 0;
		if (temp1 % 3 == 0)
		{
			tj1 = 1;
		}
		if (temp1 > 100)
		{
			if ((temp1 / 100) == 3)//判断百位是否为3
			{
				tj2 = 1;
			}
			else if ((temp1 / 10 - (temp1 / 100) * 10) == 3)//判断十位是否为3
			{
				tj2 = 1;
			}
			else if((temp1 % 10) == 3)
			{
				tj2 = 1;
			}
		}
		else
		{
			if (temp1 / 10 == 3)
			{
				tj3 = 1;
			}
			else if(temp1 % 10 == 3)
			{
				tj3 = 1;
			}
		}

		tj = tj1 || tj2 || tj3;

		if (tj)
		{
			printf("%d\t", temp1);
			sum = temp2 + sum;
			temp2++;
			if ((temp2 % 10) == 0)
			{
				printf("\n");
			}
		}
		temp1++;
	}
	printf("\n\n有%d个数", temp2);
	printf("\n它们的和为：%d\n\n\n", sum);
	return 0;
}
int main()
{
	int input;
	while (1)
	{
		printf("**********************************************************\n");
		printf("*              输出1~1000的和，请输入1                   *\n");
		printf("*   输出1~1000之间能被3整除，个十百位有3的数字，请输入2  *\n");
		printf("*                 退出请输入0                            *\n");
		printf("**********************************************************\n");
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:sum(); break;
		case 2:zhengchu(); break;
		case 0:exit(1);
		default:printf("输入错误，请正确选择!\n");
		}
	}
}
