//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* retArr = (int*)calloc(sizeof(int) * numsSize, 1);
//    int* temp = (int*)calloc(sizeof(int) * (numsSize+1), 1);
//    *returnSize = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        temp[nums[i]-1] += 1;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (temp[i] == 0)
//        {
//            retArr[(*returnSize)++] = i + 1;
//        }
//    }
//    return retArr;
//}
//
//int main() 
//{
//    int count = 0;
//    int arr[] = { 4,3,2,7,8,2,3,1 };
//    int* p = findDisappearedNumbers(arr, 8, &count);
//    for (int i = 0; i < 8; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    printf("\n");
//    return 0;
//}
