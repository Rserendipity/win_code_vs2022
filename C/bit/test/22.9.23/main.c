#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int main()
{
	int i = 0;

	for (i = 10000; i <= 99999; i++)
	{
		int ret = 0;
		int j = 0;
		for (j = 1; j <= 4; j++)
		{
			ret += (i % (int)pow(10, j)) * (i / (int)pow(10, j));
		}
		if (ret == i)
			printf("%d ", ret);
	}

	return 0;
}