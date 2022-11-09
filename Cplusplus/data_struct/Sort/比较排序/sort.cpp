#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"
using namespace std;

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int x = arr[end + 1];

		while (end >= 0)
		{
			if (arr[end] > x)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = x;
	}
}

void ShellSort(int* arr, int size)
{
	int step = size;
	while (step > 1)
	{
		step /= 2;

		for (int i = 0; i < size - step; i++)
		{
			int end = i;
			int x = arr[end + step];

			while (end >= 0)
			{
				if (arr[end] > x)
				{
					arr[end + step] = arr[end];
					end -= step;
				}
				else
				{
					break;
				}
			}
			arr[end + step] = x;
		}
	}
}

void SelectSort(int* arr, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		swap(arr[begin], arr[min]);
		if (max == begin)
		{
			max = min;
		}
		swap(arr[end], arr[max]);
		begin++;
		end--;
	}
}

void heap(int* arr, int pos, int size)
{
	int child = pos * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[pos])
		{
			swap(arr[child], arr[pos]);
			pos = child;
			child = pos * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int size)
{
	// ½¨¶Ñ
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		heap(arr, i, size);
	}

	// ¶ÑÅÅÐò
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		heap(arr, 0, i);
	}
}
