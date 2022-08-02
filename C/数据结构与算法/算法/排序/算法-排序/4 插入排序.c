//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//void PrintArr(int* arr, int lenth)
//{
//	for (int i = 0; i < lenth; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void InsertSort(int* arr, int lenth)
//{
//	if (arr == NULL || lenth < 2)
//		return;
//
//	for (int i = 1; i < lenth; i++)
//	{
//		if (arr[i] > arr[i - 1])
//			continue;
//		int temp = arr[i];
//		int k = i - 1;
//		while (arr[k] > temp)
//		{
//			arr[k + 1] = arr[k];
//			k--;
//		}
//		arr[k + 1] = temp;
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,3,5,123,1,44,9,7 };
//	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
//	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
//	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
//
//	return 0;
//}