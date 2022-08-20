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
//void selectSort(int* arr, int size)
//{
//	int min = 0, i = 0, j = 0;
//	for (i = 0; i < size; i++)
//	{
//		min = i;
//		for (j = i; j < size; j++)
//		{
//			if (arr[j] < arr[min])
//				min = j;
//		}
//		swap(arr[min], arr[i]);
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
//	selectSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}