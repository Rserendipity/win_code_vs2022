#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
int main()
{
	union 
	{
		short a;
		char arr[2];
	}*p,a;

	p = &a;
	p->arr[0] = 0x39;
	p->arr[1] = 0x38;
	printf("%x", p->a);

	return 0;
}
