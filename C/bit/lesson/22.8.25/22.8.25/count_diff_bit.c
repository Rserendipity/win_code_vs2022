//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//// ÿһλ���Ƚϣ���ͬ�Ļ�����count++
//int cut_diff_bit1(int m, int n)
//{
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (((m >> i) & 1) != ((n >> i) & 1))
//            count++;
//    }
//    return count;
//}
//
//// ����򣬾Ϳ����ҵ�ȫ���Ĳ�ͬ�Ķ�����
//// Ȼ�����������1�ĸ���
//int cut_diff_bit2(int m, int n)
//{
//    int count = 0;
//    int ret = m ^ n;
//    while (ret)
//    {
//        ret = ret & (ret - 1);
//        count++;
//    }
//    return count;
//}
//
//
//int main() 
//{
//    int a = 1999;
//    int b = 2299;
//    printf("%d\n", cut_diff_bit1(a, b));
//    printf("%d\n", cut_diff_bit2(a, b));
//    return 0;
//}
