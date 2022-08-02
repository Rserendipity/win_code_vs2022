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
//void countSort(int* arr, int size)
//{
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//		if (arr[i] > max)
//			max = arr[i];
//
//	int* count = new int[max + 1]();
//	
//	for (int i = 0; i < size; i++)
//		count[arr[i]]++;
//	
//	for (int i = 1; i < max + 1; i++)
//		count[i] += count[i - 1];
//
//	int* output = new int[size]();
//	for (int i = 0; i < size; i++)
//	{
//		output[count[arr[i]] - 1] = arr[i];
//		count[arr[i]]--;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = output[i];
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
//	countSort(arr, size);
//	
//	printArr(arr, size);
//
//	return 0;
//}
//
