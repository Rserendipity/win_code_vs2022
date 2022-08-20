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
//void merge(int* arr, int* temp, int l, int mid, int r)
//{
//	int l_pos = l;
//	int r_pos = mid + 1;
//	int pos = l;
//
//	while (l_pos <= mid && r_pos <= r)
//	{
//		if (arr[l_pos] < arr[r_pos])
//			temp[pos++] = arr[l_pos++];
//		else
//			temp[pos++] = arr[r_pos++];
//	}
//
//	while (l_pos <= mid)
//		temp[pos++] = arr[l_pos++];
//	
//	while (r_pos <= r)
//		temp[pos++] = arr[r_pos++];
//
//	while (l <= r)
//	{
//		arr[l] = temp[l];
//		l++;
//	}
//}
//
//void patition(int* arr, int* temp, int l, int r)
//{
//	if (l < r)
//	{
//		int mid = (l + r) / 2;
//		patition(arr, temp, l, mid);
//		patition(arr, temp, mid + 1, r);
//		merge(arr, temp, l, mid, r);
//	}
//}
//
//void mergeSort(int* arr, int size)
//{
//	int* temp = new int[size]();
//	patition(arr, temp, 0, size - 1);
//	delete temp;
//}
//
//int main()
//{
//	int arr[] = { 4,3,5,123,1,44,9,7 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArr(arr, size);
//
//	mergeSort(arr, size);
//
//	printArr(arr, size);
//
//	return 0;
//}