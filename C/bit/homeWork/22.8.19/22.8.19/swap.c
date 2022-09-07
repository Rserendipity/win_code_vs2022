//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
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
//void swap(int* arr1, int * arr2, int size)
//{
//    char* s1 = (char*)arr1;
//    char* s2 = (char*)arr2;
//    char ch = 0;
//    for (int i = 0; i < size; i++)
//    {
//        ch = *s1;
//        *s1 = *s2;
//        *s2 = ch;
//        s1++;
//        s2++;
//    }
//}
//
//int main() 
//{
//    int arr1[] = { 1,2,3,4,5,6 };
//    int arr2[] = { 9,8,7,6,5,4 };
//    int size = sizeof(arr1) / sizeof(arr1[0]);
//    printArr(arr1, size);
//    printArr(arr2, size);
//
//    swap(arr1, arr2, sizeof(arr1));
//
//    printArr(arr1, size);
//    printArr(arr2, size);
//
//    return 0;
//}