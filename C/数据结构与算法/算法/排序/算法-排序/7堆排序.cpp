//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//void printArr(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
//void heapity(int* arr, int size, int pos)
//{
//	int lch = pos * 2 + 1;
//	int rch = pos * 2 + 2;
//	int max = pos;
//
//	if (lch < size && arr[lch] > arr[max])
//		max = lch;
//	if (rch < size && arr[rch] > arr[max])
//		max = rch;
//
//	if (max != pos)
//	{
//		swap(arr[max], arr[pos]);
//		heapity(arr, size, max);
//	}
//}
//
//void heapSort(int* arr, int size)
//{
//	for (int i = (size - 1) / 2; i >= 0; i--)
//		heapity(arr, size, i);
//
//	for (int i = size - 1; i >= 0; i--)
//	{
//		swap(arr[i], arr[0]);
//		heapity(arr, i, 0);
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,3,5,123,1,44,9,7 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArr(arr, size);
//
//	heapSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}