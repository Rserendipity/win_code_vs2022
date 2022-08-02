#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int BinarySearch(int arr[], int size, int findNum)
{
	int head = 0;
	int mid = size / 2;
	int tail = size - 1;
	if (arr == NULL)
	{
		return -1;
	}
	if (size < 2)
	{
		return arr[0] == findNum ? 0 : -1;
	}

	while (head<=tail)
	{
		if (arr[mid] > findNum)
		{
			tail = mid;
			mid = (mid + head) / 2;
		}
		else if(arr[mid] < findNum)
		{
			head = mid;
			mid = (mid + tail) / 2 + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,4,5 };
	int ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 5);
	if (ret != -1)
	{
		printf("Find it %d\n",ret);
	}
	else printf("No Find\n");

	return 0;
}