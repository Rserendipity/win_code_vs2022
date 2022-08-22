//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    int* p = (int*)malloc(sizeof(int) * 10000);
//    *returnSize = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int temp = i;
//        int n = 1;
//        while (temp /= 10)
//            n++;
//        int flag = 0;
//        for (int j = 0; j < n; j++)
//        {
//            int div = (int)pow(10, j);
//            temp = i / div % 10;
//            if (temp == 0)
//            {
//                flag = 1;
//                break;
//            }
//            if (i % temp != 0)
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 0)
//        {
//            p[(*returnSize)++] = i;
//        }
//    }
//    return p;
//}
//
//int main() 
//{
//    int size = 0;
//    int* p = selfDividingNumbers(1, 22, &size);
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    return 0;
//}