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
//    // �����ֵ
//    int max = pArr[0];
//    for (int i = 0; i < n; i++)
//    {
//        if (pArr[i] > max)
//            max = pArr[i];
//    }
//
//    // ���ٿռ䣬����Ͱ��˼�룬�ҵ�ֻ����һ�ε�����
//    int* bucket = calloc(1, sizeof(int) * (max + 1));
//    for (int i = 0; i < n; i++)
//    {
//        bucket[pArr[i]]++;
//    }
//
//    // ��ֻ����һ�ε�����
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
