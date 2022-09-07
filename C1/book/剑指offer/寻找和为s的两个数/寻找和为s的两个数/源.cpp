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
				cout << "���ҵ�" << s << endl;
			}
		}
	}
	cout << "δ�ҵ�" <<  endl;
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
			cout << "�ҵ���" << " " << s << endl;
			return;
		}
	}
	cout << "δ�ҵ�" << endl;
	return;
}
int main()
{
	int arr[] = { 1,7,8,12,15,45 };
	int s = 21;

	int* head = arr;
	int* tail = arr + sizeof(arr)/sizeof(arr[0]) - 1;
	
	//ʱ�临�Ӷ�O(N^2)
	Find1(arr, sizeof(arr) / sizeof(arr[0]),s);
	//ʱ�临�Ӷ�O(N)
	Find2(head, tail, s);

	return 0;
}

