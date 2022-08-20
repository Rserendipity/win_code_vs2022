#include <stdio.h>

int JieCheng(int x)
{
	if (x <= 1)
		return 1;
	else 
		return x * JieCheng(x - 1);
}

int main()
{
	int input, temp;
	scanf("%d", &input);
	temp = JieCheng(input);
	printf("%d", temp);
	return 0;
}
