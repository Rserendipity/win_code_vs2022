//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//void PrintArr(int* arr, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int Partition(int* arr, int i, int j)
//{
//	int temp = arr[i];
//	while (i < j)
//	{
//		while (i < j && temp <= arr[j])
//		{
//			j--;
//		}
//		if (i < j)
//		{
//			arr[i] = arr[j];
//			i++;
//		}
//		while (i < j && temp > arr[i])
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			arr[j] = arr[i];
//			j--;
//		}
//	}
//	arr[j] = temp;
//	return j;
//}
//
//void QuickSort(int* arr, int i, int j)
//{
//	if (i < j)
//	{
//		int index = Partition(arr, i, j);
//		QuickSort(arr, i, index - 1);
//		QuickSort(arr, index + 1, j);
//	}
//}
//
//
//int main(void)
//{
//	int arr[8] = { 49,38,65,97,76,13,27,49 };
//	QuickSort(arr, 0, 7);
//	PrintArr(arr, 8);
//
//	return 0;
//}
//
