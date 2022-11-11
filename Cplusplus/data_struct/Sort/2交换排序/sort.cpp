#include "sort.h"

// 寻找中间值
int midNum(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else
	{
		if (arr[mid] > arr[right])
			return mid;
		else if (arr[right] > arr[left])
			return left;
		else
			return right;
	}
}

// 左右交换
int part1(int* arr, int left, int right)
{
	int mid = midNum(arr, left, right);
	std::swap(arr[left], arr[mid]);
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

// 挖坑法
int part2(int* arr, int left, int right)
{
	int mid = midNum(arr, left, right);
	std::swap(arr[left], arr[mid]);
	int val = arr[left];
	while (left < right)
	{
		while (left < right && val <= arr[right])
			--right;
		if (left < right)
		{
			arr[left] = arr[right];
			++left;
		}
		while (left < right && val >= arr[left])
			++left;
		if (left < right)
		{
			arr[right] = arr[left];
			--right;
		}
	}
	arr[left] = val;
	return left;
}

// 前后指针法
int part3(int* arr, int left, int right)
{
	int mid = midNum(arr, left, right);
	std::swap(arr[left], arr[mid]);
	
	int cur = left + 1;
	int pre = left;
	while (cur <= right)
	{
		if (arr[cur] < arr[left] && ++pre != cur)
		{
			std::swap(arr[pre], arr[cur]);
		}
		++cur;
	}
	std::swap(arr[left], arr[pre]);
	return pre;
}

void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = part3(arr, left, right);
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


void merge(int* arr, int l, int r, int* temp)
{
	if (l >= r)
		return;
	int mid = l + (r - l) / 2;
	merge(arr, l, mid, temp);
	merge(arr, mid + 1, r, temp);

	int begin1 = l, end1 = mid;
	int begin2 = mid + 1, end2 = r;
	int index = l;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}
	while (begin1 <= end1)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = arr[begin2++];
	}
	index = l;
	while (index <= r)
	{
		arr[index] = temp[index];
		index++;
	}
}

void MergeSort(int* arr, int size)
{
	int* temp = new int[size];

	merge(arr, 0, size - 1, temp);

	delete[] temp;
}

void QuickSortNonR(int* arr, int letf, int right)
{
	std::stack<int> st;
	st.push(right);
	st.push(letf);

	while (!st.empty())
	{
		int l = st.top();
		st.pop();
		int r = st.top();
		st.pop();

		int mid = part3(arr, l, r);
		// [l, mid - 1] mid [mid + 1, r]

		if (mid + 1 < r)
		{
			st.push(r);
			st.push(mid + 1);
		}
		if (l < mid - 1)
		{
			st.push(mid - 1);
			st.push(l);
		}
	}
}


