//#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct People {
//	char name[20];
//	double weight;
//};
//
//void swap(char* s1, char* s2, int size) {
//	for (int i = 0; i < size; i++) {
//		char temp = *s1;
//		*s1 = *s2;
//		*s2 = temp;
//		s1++;
//		s2++;
//	}
//}
//
//void bubbleSort(void* dest, int num, int size, int (*cmp)(const void*, const void*)) {
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num - 1 - i; j++) {
//			if (cmp((char*)dest + j * size, (char*)dest + (j + 1) * size) > 0) {
//				swap((char*)dest + j * size, (char*)dest + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//void printInt(int* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void printStr(char arr[][20], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%s\n", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void* num1, const void* num2) {
//	return *(int*)num1 - *(int*)num2;
//}
//
//void test1() {
//	int arr[] = { 5,3,6,9,4,2,1,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printInt(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	printInt(arr, sz);
//}
//
//int cmp_str(const void* str1, const void* str2) {
//	return strcmp((char*)str1, (char*)str2);
//}
//
//void test2() {
//	char arr[][20] = { "hello", "bit", "how are you" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printStr(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_str);
//	printStr(arr, sz);
//
//}
//
//int cmp_by_name(const void* n1, const void* n2) {
//	return strcmp(((struct People*)n1)->name, ((struct People*)n2)->name);
//}
//int cmp_by_weight(const void* w1, const void* w2) {
//	return (int)(((struct People*)w1)->weight - ((struct People*)w2)->weight);
//}
//void test3() {
//	struct People {
//		char name[20];
//		double weight;
//	} p[3] = { {"zhangsan", 123.4 },{"wangwu", 110.3},{"lili", 190.7} };
//	bubbleSort(p, 3, sizeof(p[0]), cmp_by_name);
//	bubbleSort(p, 3, sizeof(p[0]), cmp_by_weight);
//}
//
//int main() {
//	test3();
//	return 0;
//}