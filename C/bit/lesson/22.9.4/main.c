#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main() 
//{
//    int a = -1;
//    // 11111111 11111111 11111111 11111111
//    // 1 11111111 111111111111111111111
//    // e = 11111111
//    // 表示正负无穷
// 
//    float* p = (float*)&a;
//    printf("%d", a); 
//    return 0;
//}

int func(unsigned int x)
{
	int n = 0;
	while (x + 1)
	{
		n++;
		x = x | (x + 1);
	}
	return n;
}

int main()
{
	printf("%d",func(2014));
	return 0;
}
