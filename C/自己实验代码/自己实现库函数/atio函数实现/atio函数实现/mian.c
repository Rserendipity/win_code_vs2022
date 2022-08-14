#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* StringToNum(const char*ps, int size)
{
	int* ret = malloc(sizeof(int) * 2);
	int flag = 1;
	double buf = 0;
	if (ps == NULL)
	{
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
	if (size == 0)
	{
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
	if (size == 1)
	{
		if (ps[0] == '+' || ps[0] == '-')
		{
			ret[0] = 1;
			ret[1] = 0;
			return ret;
		}
		if (ps[0] >= '0' && ps[0] <= '9')
		{
			ret[0] = 0;
			ret[1] = ps[0] - 48;
			return ret;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (ps[i] == '+')
		{
			flag = 1;
		}
		else if(ps[i] == '-')
		{
			flag = -1;
		}
		else if (ps[i] <= '9' && ps[i] >= '0')
		{
			buf *= 10;
			buf += ps[i] - 48;
		}
	}
	if (buf <= 0x7fffffff && buf >= (int)0x80000000)
	{
		ret[0] = 0;
		ret[1] = flag * (int)buf;
		return ret;
	}
	else
	{
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
}

int main()
{
	char inputBuf[100] = { 0 };
	scanf("%s", inputBuf);
	int* ret = StringToNum(inputBuf,strlen(inputBuf));
	if (ret[0] == 0)
	{
		printf("%d", ret[1]);
	}
	else
	{
		printf(" ‰»Î”–ŒÛ\n");
	}
	free(ret);
	return 0;
}
