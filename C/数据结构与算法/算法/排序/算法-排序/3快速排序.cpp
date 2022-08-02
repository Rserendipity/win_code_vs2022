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
//int patition(int* arr, int l, int r)
//{
//	int temp = arr[l];
//	while (l < r)
//	{
//		while (l < r && temp <= arr[r])
//			r--;
//		if (l < r)
//		{
//			arr[l] = arr[r];
//			l++;
//		}
//		while (l < r && temp > arr[l])
//			l++;
//		if (l < r)
//		{
//			arr[r] = arr[l];
//			r--;
//		}
//	}
//	arr[l] = temp;
//	return l;
//}
//
//void quickSort(int* arr, int l, int r)
//{
//	if (l < r)
//	{
//		int mid = patition(arr, l, r);
//		quickSort(arr, l, mid - 1);
//		quickSort(arr, mid + 1, r);
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
//	quickSort(arr, 0, size - 1);
//
//	printArr(arr, size);
//
//	return 0;
//}