#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

int main()
{
	//printf("%2.7d\n", 123);
	//// "%2.7d"  .7  -->  占用7位,不够会补齐0
	//// "%2.7d"  2d  -->  至少占用2个位子,没有用完会在前面添加空格
	//printf("%2d1\n", 1);
	//// "%2d1\n"  %2占用了两个位子, 所以输出为 " (空格)11"
	//printf("%-2d1\n", 1);
	//// "%-2d"  表示左对齐
	
	/* 题目1
	int i = 2, j = 3;
	int k = i * j == 6;
	printf("%d", k);*/
	/* 题目2
	int i = 5, j = 10, k = 1;
	printf("%d", k > i < j);*/
	/* 题目3
	int i = 3, j = 4, k = 5;
	printf("%d", i % j + i < k);*/
	int i = 1, j = 2, k = 3;
	printf("%d\n", i < j || ++j < k);
	printf("%d %d %d \n", i, j, k);

	return 0;
}

