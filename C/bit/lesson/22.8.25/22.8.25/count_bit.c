//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//// �����Ƶļ��㣬���Ʋ���
//int count_bit1(int n)
//{
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if ((n >> i & 1) == 1)
//            count++;
//    }
//    return count;
//}
//
//// �޷��ŵ�����Ȼ�����ȡ�࣬����Ϊ1��count++
//int count_bit2(unsigned int n)
//{
//    int count = 0;
//    while (n)
//    {
//        if (n % 2 == 1)
//            count++;
//        n /= 2;
//    }
//    return count;
//}
//
//// n & (n - 1)����ȥ���ұߵ�1��ֱ�������Ϊ0ʱ�����Ƕ�����1�ĸ���
//int count_bit3(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n = n & (n - 1);
//    }
//    return count;
//}
//int main() 
//{
//    int a = -1;
//    printf("%d\n", count_bit1(a));
//    printf("%d\n", count_bit2(a));
//    printf("%d\n", count_bit3(a));
//    return 0;
//}
