#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

void Print(int* p, int r,int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			printf("%d ", *(p + i * r + j));
		}
		printf("\n");
	}
}

void re(char* p) {
	if (p == NULL) return;
	int i = 0;
	int j = strlen(p) - 1;
	if (j == 0) return;
	while (i < j) {
		char temp = p[i];
		p[i] = p[j];
		p[j] = temp;
		i++, j--;
	}
}

int jisuan(int qian, int gai)
{
	if (qian) {
		gai = qian + gai;
		return qian + jisuan(gai / 2, gai % 2);
	}
	return 0;
}


void bullble_sort(int* arr, int leng)
{
	for (int i = 0; i < leng; i++) {
		for (int j = 0; j < leng - i - 1; j++) {
			int temp = arr[j];
			if (arr[j] > arr[j + 1]) {
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int partition(int arr[], int l, int r) {
	int temp = arr[l];
	while (l < r) {
		while (l < r && arr[r] >= temp) {
			r--;
		}
		if (l < r) {
			arr[l] = arr[r];
			l++;
		}
		while (l < r && arr[l] < temp) {
			l++;
		}
		if (l < r) {
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = temp;
	return l;
}

void quick_sort(int* arr, int l, int r) {
	if (l < r) {
		int index = partition(arr, l, r);
		quick_sort(arr, 0, index - 1);
		quick_sort(arr, index + 1, r);
	}
}/*
int paratition(int arr[], int l, int r) {
	int key = arr[l];
	while (l < r) {
		while (l < r && arr[r] >= key) {
			r--;
		}
		if (l < r) {
			arr[l] = arr[r];
			l++;
		}
		while (l < r && arr[l] < key) {
			l++;
		}
		if (l < r) {
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = key;
	return l;
}

void quickSort(int arr[], int head, int tail) {
	if (head < tail) {
		int index = paratition(arr, head, tail);
		quickSort(arr, 0, index - 1);
		quickSort(arr, index + 1, tail);
	}
 
}*/
int cmp(const void* base1, const void* base2) {
	return *(int*)base1 - *(int*)base2;
}
void swap(char* base1,char*base2, int width) {
	for (int i = 0; i < width; i++) {
		char temp = *base1;
		*base1 = *base2;
		*base2 = temp;
		base1++;
		base2++;
	}
}
void my_sort(void* base, int size, int width, int (*cmp)(const void* base1, const void* base2)) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				swap( (char*)base + j * width,  (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	int arr[] = { 1,6,4,7,8,9,2,3,5,0 };
	//bullble_sort(arr,10);
	//quick_sort(arr, 0, 9);
	//quickSort(arr, 0, 9);
	my_sort(arr, 10, 4, cmp);
	
	
	return 0;
}