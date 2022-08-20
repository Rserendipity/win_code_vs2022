#include<stdio.h>
#include<conio.h> 
#include<string.h>
int main()
{
	int b, c, d, j, e, i; char a[3][80];
	b = 0, c = 0, d = 0, e = 0;
	for (i = 0; i < 3; i++)
	{
		gets_s(a[i]);
		for (j = 0; j < 80 && a[i][j] != '\0'; j++)
		{
			{
				if ('A' <= a[i][j] && a[i][j] <= 'Z')
				{
					b = b + 1;
				}
				else if ('a' <= a[i][j] && a[i][j] <= 'z')
				{
					c = c + 1;
				}
				else if ('0' <= a[i][j] && a[i][j] <= '9')
				{
					d = d + 1;
				}
				else
					e = e + 1;
			}
		}
	}
	printf("大写字母%d\n", b);
	printf("小写字母%d\n", c);
	printf("数字%d\n", d);
	printf("其他字符%d\n", e);
	return 0;
}
