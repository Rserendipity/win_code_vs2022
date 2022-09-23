//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    int* pArr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//        scanf("%d", &pArr[i]);
//
//    // 找最大值
//    int max = pArr[0];
//    for (int i = 0; i < n; i++)
//    {
//        if (pArr[i] > max)
//            max = pArr[i];
//    }
//
//    // 开辟空间，利用桶的思想，找到只出现一次的数字
//    int* bucket = calloc(1, sizeof(int) * (max + 1));
//    for (int i = 0; i < n; i++)
//    {
//        bucket[pArr[i]]++;
//    }
//
//    // 找只出现一次的数字
//    for (int i = 0; i < max + 1; i++)
//    {
//        if (bucket[i] == 1)
//        {
//            printf("%d ", i);
//        }
//    }
//
//    return 0;
//}
