#include <stdio.h>

void print(int x)
{
	if (x > 9)
	{
		print(x / 10);
	}
	printf("%d ", x % 10);
}

int main()
{
	unsigned int num;
	scanf("%d", &num);
	print(num);
	return 0;
}
