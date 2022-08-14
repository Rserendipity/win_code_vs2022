//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
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
//int maxRadix(int max)
//{
//	int i = 0;
//	while (max /= 10)
//		i++;
//	return i + 1;
//}
//
//void radixSort(int* arr, int size)
//{
//	int* temp = (int*)malloc(sizeof(int) * size);
//	int* count = (int*)malloc(sizeof(int) * 10);
//	memset(count, 0, sizeof(int) * 10);
//
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	// 几位数
//	int n = maxRadix(max);
//
//	for (int i = 0; i < n; i++)
//	{
//		// 从个位开始,一直到最高位数
//		int div = (int)pow(10, i);
//		
//		for (int i = 0; i < size; i++)
//		{
//			count[arr[i] / div % 10] += 1;
//		}
//
//		for (int i = 1; i < 10; i++)
//		{
//			count[i] += count[i - 1];
//		}
//
//		for (int i = size - 1; i >= 0; i--)
//		{
//			temp[count[arr[i] / div % 10] - 1] = arr[i];
//			count[arr[i] / div % 10] -= 1;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = temp[i];
//		}
//
//		memset(count, 0, sizeof(int) * 10);
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,3,5,123,1,44,9,7,54,77,165,754,6235 };
//	// int arr[] = { 9, 5, 2, 7, 12, 4, 3, 1, 11 ,123};
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArr(arr, size);
//
//	radixSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}