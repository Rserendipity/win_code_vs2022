#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long int input = 0;
	int temp1 = 0, temp2 = 0, temp3 = 0, n = 0;
	int a[100] = { 0 };
	printf("请输入一个0~65536之间的数>:");
	scanf("%d", &input);
	printf("请输入要转换为几进制(2~16进制之间)>:");
	scanf("%d", &n);
	char output[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (input != 0)
	{
		temp1 = input % n;
		a[temp2] = temp1;
		input = input / n;
		temp2++;
	}
	if (n == 16)
	{
		printf("0x");
	}
	for (temp2 = temp2 - 1; temp2 >= 0; temp2--)
	{
		temp3 = a[temp2];
		printf("%c", output[temp3]);
	}
	if (n == 2)
	{
		printf("B");
	}
	return 0;
}

