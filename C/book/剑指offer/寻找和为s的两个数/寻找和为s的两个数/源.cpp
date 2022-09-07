#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void Find1(int* arr, int size, int s)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (arr[i] + arr[j] == s)
			{
				cout << "已找到" << s << endl;
			}
		}
	}
	cout << "未找到" <<  endl;
}
void Find2(int* head, int* tail, int s)
{
	while (*head < *tail)
	{
		if (*head + *tail > s)
		{
			tail--;
		}
		else if (*head + *tail < s)
		{
			head++;
		}
		else
		{
			cout << "找到了" << " " << s << endl;
			return;
		}
	}
	cout << "未找到" << endl;
	return;
}
int main()
{
	int arr[] = { 1,7,8,12,15,45 };
	int s = 21;

	int* head = arr;
	int* tail = arr + sizeof(arr)/sizeof(arr[0]) - 1;
	
	//时间复杂度O(N^2)
	Find1(arr, sizeof(arr) / sizeof(arr[0]),s);
	//时间复杂度O(N)
	Find2(head, tail, s);

	return 0;
}

