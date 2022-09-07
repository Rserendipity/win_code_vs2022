#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a = 1;
	while (1)
	{
		if (a % 2 == 1)
		{
			if (a % 3 == 1)
			{
				if (a % 4 == 1)
				{
					if (a % 5 == 1)
					{
						if (a % 6 == 1)
						{
							if (a % 7 == 0)
							{
								printf("她有%d个鸡蛋", a);
								break;
							}
						}
					}
				}
			}
		}
		a++;
	}
	return 0;
}
