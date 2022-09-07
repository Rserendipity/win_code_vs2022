//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define SIZE 3
//int main()
//{
//	int row = 0;
//	int low = 0;
//	int arr[SIZE][SIZE] = { 0 };
//	low = SIZE / 2;
//
//	for (int i = 1; i <= SIZE*SIZE; i++) {
//		arr[row][low] = i;
//		row--;
//		low++;
//		if (row < 0)
//			row = SIZE - 1;
//		if (low > SIZE - 1)
//			low = 0;
//		if (arr[row][low] != 0)
//			row++;
//	}
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}