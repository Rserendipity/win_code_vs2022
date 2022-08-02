//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
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
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void heapity(int* arr, int size, int pos)
//{
//	int max = pos;
//	int lch = pos * 2 + 1;
//	int rch = pos * 2 + 2;
//
//	if (lch < size && arr[lch] > arr[max])
//		max = lch;
//	if (rch < size && arr[rch] > arr[max])
//		max = rch;
//
//	if (max != pos)
//	{
//		swap(&arr[max], &arr[pos]);
//		heapity(arr, size, max);
//	}
//}
//
//void heapitySort(int* arr, int size)
//{
//	for (int i = (size - 1) / 2; i >= 0; i--)
//	{
//		heapity(arr, size, i);
//	}
//
//	for (int i = size - 1; i >= 0; i--)
//	{
//		swap(&arr[0], &arr[i]);
//		heapity(arr, i, 0);
//	}
//}
//
//int main()
//{
//	int arr[] = { 9, 5, 2, 7, 12, 4, 3, 1, 11 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArr(arr, size);
//
//	heapitySort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}