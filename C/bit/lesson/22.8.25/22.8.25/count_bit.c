//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//// 二进制的计算，左移操作
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
//// 无符号的数，然后除二取余，余数为1则count++
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
//// n & (n - 1)可以去掉右边的1，直到这个数为0时，就是二进制1的个数
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
