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
//void ShellSort(int* arr, int lenth) 
//{
//	int j;
//	for (int step = 6 / 2; step > 0; step /= 2)
//	{
//		for (int i = step; i < lenth; i++)
//		{
//			int temp = arr[i];
//			for (j = i; j >= step && temp < arr[j - step]; j -= step)
//				arr[j] = arr[j - step];
//			arr[j] = temp;
//		}
//		PrintArr(arr, 8);
//	}
//}
//
//int main()
//{
//	int arr[] = { 49,38,65,97,76,13,27,49 };
//
//	ShellSort(arr, 8);
//
//	return 0;
//}