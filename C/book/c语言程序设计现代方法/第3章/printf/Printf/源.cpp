#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

int main()
{
	//printf("%2.7d\n", 123);
	//// "%2.7d"  .7  -->  ռ��7λ,�����Ჹ��0
	//// "%2.7d"  2d  -->  ����ռ��2��λ��,û���������ǰ����ӿո�
	//printf("%2d1\n", 1);
	//// "%2d1\n"  %2ռ��������λ��, �������Ϊ " (�ո�)11"
	//printf("%-2d1\n", 1);
	//// "%-2d"  ��ʾ�����
	
	/* ��Ŀ1
	int i = 2, j = 3;
	int k = i * j == 6;
	printf("%d", k);*/
	/* ��Ŀ2
	int i = 5, j = 10, k = 1;
	printf("%d", k > i < j);*/
	/* ��Ŀ3
	int i = 3, j = 4, k = 5;
	printf("%d", i % j + i < k);*/
	int i = 1, j = 2, k = 3;
	printf("%d\n", i < j || ++j < k);
	printf("%d %d %d \n", i, j, k);

	return 0;
}

