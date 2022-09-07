#include <stdio.h>

int Fib(int x)
{
	int a = 1, b = 1, c = 0;
	if (x <= 2)
		return 1;
	else
	{
		for (int i = 2; i < x; i++)
		{
			c = a + b;
			b = a;
			a = c;
		}
		return c;
	}
}
int main()
{
	int input, temp;
	printf("输入你要求的第几个斐波那契数:>");
	scanf("%d", &input);
	temp = Fib(input);
	printf("%d", temp);
	return 0;
}
