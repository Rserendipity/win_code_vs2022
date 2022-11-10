#include "sort.h"

int part(int* arr, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
			--right;
		while (left < right && arr[left] <= arr[key])
			++left;
		std::swap(arr[left], arr[right]);
	}
	std::swap(arr[left], arr[key]);
	return left;
}

void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = part(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
}

void PrintArr(int* arr, int size)
{
	for (int i = 0 ;  i < size; i++) 
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
