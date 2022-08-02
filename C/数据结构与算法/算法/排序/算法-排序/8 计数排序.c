//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void printArr(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void countSort(int* arr, int size)
//{
//	if (arr == NULL || size == 0 || size == 1)
//		return;
//
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	int* count = (int*)malloc(sizeof(int) * (max + 1));
//	memset(count, 0, sizeof(int) * (max + 1));
//
//	for (int i = 0; i < size; i++) 
//	{
//		count[arr[i]] += 1;
//	}
//
//	for (int i = 1; i < max + 1; i++)
//	{
//		count[i] += count[i - 1];
//	}
//
//	int* out = (int*)malloc(sizeof(int) * size);
//
//	for (int i = 0; i < size; i++)
//	{
//		out[count[arr[i]] - 1] = arr[i];
//		count[arr[i]] -= 1;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = out[i];
//	}
//}
//
//int main()
//{
//	int arr[] = { 9, 5, 2, 7, 12, 4, 3, 1, 11 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	printArr(arr, size);
//
//	countSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}