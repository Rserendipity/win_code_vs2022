#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <array>

using namespace std;
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int getMax(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int getRank(int num) {
	int rank = 1;
	while (num /= 10)
		rank++;
	return rank;
}

void radixSort(int* arr, int size) {
	int* count = new int[10]();
	int* temp = new int[size]();
	
	int max = getMax(arr, size);

	int n = getRank(max);

	for (int j = 0; j < n; j++) {
		int div = (int)pow(10, j);

		for (int i = 0; i < size; i++) {
			count[arr[i] / div % 10] += 1;
		}

		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		for (int i = size - 1; i >= 0; i--) {
			temp[count[arr[i] / div % 10] - 1] = arr[i];
			count[arr[i] / div % 10] -= 1;
		}

		for (int i = 0; i < size; i++) {
			arr[i] = temp[i];
		}

		memset(count, 0, sizeof(int) * 10);
	}
	delete[] count;
	delete[] temp;
}

int main()
{
	int arr[] = { 4,3,5,123,1,44,9,7,54,77,165,754,6235 };
	//int arr[] = { 4,3,5,123,1,44,9,7,54,77,165,754 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printArr(arr, size);

	radixSort(arr, size);
	
	printArr(arr, size);

	return 0;
}

