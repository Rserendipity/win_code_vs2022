#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int e = 0, tu = 36;
	while (1)
	{
		if ((2 * e + 4 * tu) == 100)
		{
			printf("有%d只鹅，有%d只兔", e, tu);
			break;
		}
		if (tu == 0)
		{
			printf("此题无解！");
			break;
		}
		e++;
		tu--;
	}
	return 0;
}
