#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int arr[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				arr[i][0] = 1;
			else if (i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
