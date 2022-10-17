#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int my_atoi(const char* s)
{
	if (s == NULL)
		return 0;
	int flag = 0;
	int count = 0;
	while (isdigit(*s) == 0)
		//一直循环直到遇到第一个数字
	{
		if (*s == '\0')
			//一直循环，直到最后都没找到一个数字
		{
			return 0;
		}
		s++;
	}

	//判断此时第一个数字之前有没有+-号
	s--;
	if (*s == '-')
		//如果第一个数字之前是-号
	{
		flag = -1;
		s++;
	}
	else
		//如果前面是+号或者其它杂七八拉的东西都默认转换的是正数
	{
		flag = 1;
		s++;
	}
	//此时s指向的仍然是第一个要转换的数字
	while (isdigit(*s) != 0)
		//因为在转换的时候可能会碰到不是数字的内容
		//这是就停止
	{
		count = count * 10 + (*s - '0');
		if (count < INT_MIN || count > INT_MAX)
			return 0;
		s++;
	}
	return count * flag;
}
int main() 
{
	int a = my_atoi("123222222222222");
	printf("%d", a);
	return 0;
}
