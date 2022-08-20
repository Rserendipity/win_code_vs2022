#include <stdio.h>

int JieCheng(int x)
{
	int i, j = 1;
	for (i = 1; i <= x; i++)
	{
		j *= i;
	}
	return j;
}

int main()
{
	int input, temp;
	scanf("%d", &input);
	temp = JieCheng(input);
	printf("%d", temp);
	return 0;
}
