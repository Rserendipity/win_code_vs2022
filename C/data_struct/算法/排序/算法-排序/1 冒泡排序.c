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
//void BulletSort(int* arr, int lenth)
//{
//	int temp;
//	for (int i = 0; i < lenth; i++)
//	{
//		for (int j = 0; j < lenth - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 4,3,5,123,1,44,9,7 };
//	BulletSort(arr, 8);
//	PrintArr(arr, 8);
//	
//
//	return 0;
//}