//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//void printArr(int* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void merge(int* arr, int* temp, int l, int m, int r)
//{
//    // 左右位置(下标)
//    int l_pos = l;
//    
//    // 中点值的下一个才是右半部分的开始!!!
//    int r_pos = m + 1; 
//
//    // 当前arr中的元素应该放在temp的哪里
//    int pos = l;
//    
//    // 总体的储存,两边都没有到结尾
//    while (l_pos <= m && r_pos <= r)
//    {
//        // 把当前较小的存到temp中
//        if (arr[l_pos] < arr[r_pos])
//            temp[pos++] = arr[l_pos++];
//        else
//            temp[pos++] = arr[r_pos++];
//    }
//
//    // 当右半部分到尾部以后,直接复制左边剩下的到temp中
//    while (l_pos <= m)
//        temp[pos++] = arr[l_pos++];
//    // 当左半部分到尾部以后,直接复制左边剩下的到temp中
//    while (r_pos <= r)
//        temp[pos++] = arr[r_pos++];
//
//    // 现在的temp中的元素已经有序,直接复制回arr中
//    while (l <= r)
//    {
//        arr[l] = temp[l];
//        l++;
//    }
//}
//
//void partition(int* arr, int* temp, int left, int right)
//{
//    // 递归停止条件
//    if (left < right)
//    {
//        // 以中心进行划分,分为左右两侧
//        int mid = (left + right) / 2;
//        // 左边进行切分
//        partition(arr, temp, left, mid);
//        // 右边进行切分
//        partition(arr, temp, mid + 1, right);
//        // 切分完成以后进行合并
//        merge(arr, temp, left, mid, right);
//    }
//}
//
//void mergeSort(int* arr, int size)
//{
//    // 开辟空间,用于存放分组后的元素
//    int* temp = (int*)malloc(size * sizeof(int));
//    
//    // 递归的切分,然后合并,这里是归并的核心
//    partition(arr, temp, 0, size - 1);
//
//    // 释放空间
//    free(temp);
//}
//
//int main()
//{
//    int arr[] = { 9, 5, 2, 7, 12, 4, 3, 1, 11 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    printArr(arr, size);
//
//    mergeSort(arr, size);
//
//    printArr(arr, size);
//	return 0;
//}