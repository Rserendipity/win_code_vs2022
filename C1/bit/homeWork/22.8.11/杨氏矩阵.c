//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int search(int(*arr)[3], int r, int c, int num) {
//	int i = 0;
//	int j = c - 1;
//	// 和每一行的最后一个元素相比
//	// 如果最后一个元素比num大就去掉最后一列，num肯定不在最后一列中
//	// 如果最后一个元素比num小，就去下一行找
//	while (i < r && j >= 0) {
//		if (arr[i][j] == num)
//			return 1;
//		else if (arr[i][j] > num)
//			j--;
//		else
//			i++;
//	}
//	return 0;
//}
//int main() {
//	int arr[3][3] = { {1,2,3}, {3,4,5}, {5,6,7} };
//	int pos = search(arr, 3, 3, 2);
//	if (pos == 1)
//		printf("find it\n");
//	else
//		printf("no find\n");
//	return 0;
//}
