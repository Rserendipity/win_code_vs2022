#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void quickSort(int* arr, int head, int tail) 
{

}

int main()
{
	int arr[] = { 8,4,9,12,3,7,10,1,5,2,13 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printArr(arr, size);

	quickSort(arr, 0, size - 1);

	printArr(arr, size);

	return 0;
}