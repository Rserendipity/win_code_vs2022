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
//void swap(int* arr, int size)
//{
//    int head = 0;
//    int tail = size - 1;
//    for (int i = 0; i < size / 2; i++)
//    {
//        int temp = arr[head];
//        arr[head] = arr[tail];
//        arr[tail] = temp;
//        head++;
//        tail--;
//    }
//}
//
//void init(int* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = 0;
//    }
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6 };
//
//    int size = sizeof(arr) / sizeof(arr[0]);
//    printArr(arr, size);
//
//    swap(arr, size);
//
//    printArr(arr, size);
//
//    init(arr, size);
//
//    printArr(arr, size);
//
//    return 0;
//}