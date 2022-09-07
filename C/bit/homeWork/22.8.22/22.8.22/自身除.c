//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//    int* p = (int*)malloc(sizeof(int) * numsSize);
//    p[0] = 1;
//    p[numsSize - 1] = 1;
//    int n = numsSize - 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        p[i] = nums[i - 1] * p[i - 1];
//        p[n - 1 - i] = nums[n - i+1] * p[n - i+1];
//    }
//    *returnSize = numsSize;
//    return p;
//}
//
//int main() 
//{
//    int size = 0;
//    int arr[] = { 1,2,3,4 };
//    int* p = productExceptSelf(arr, 4, &size);
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    return 0;
//}