//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//
// void printArr(int* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
//
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void randixToFront(int* arr, int size) {
//	int head = 0;
//	int tail = size - 1;
//	// 从头找偶数，从尾找奇数，和快排相似
//	while (head < tail) {
//		while (head < tail && arr[head] % 2 == 1) {
//			head++;
//		}
//		while (head < tail && arr[tail] % 2 == 0) {
//			tail--;
//		}
//		if (head < tail) {
//			swap(&arr[head], &arr[tail]);
//		}
//	}
//}
//
//int main() {
//	int arr[] = { 3,2,4,6,34,6,7,8,6,5,5,8, };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	randixToFront(arr, sz);
//	printArr(arr, sz);
//	return 0;
//}