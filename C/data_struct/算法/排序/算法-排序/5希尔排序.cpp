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
//void shellSort(int* arr, int size)
//{
//	int i, j, inc, temp;
//	for (inc = size / 2; inc > 0; inc /= 2)
//	{
//		for (i = inc; i < size; i++)
//		{
//			for (j = i; j >= inc && arr[j] < arr[j - inc]; j -= inc)
//				swap(arr[j], arr[j - inc]);
//		}
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
//	shellSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}