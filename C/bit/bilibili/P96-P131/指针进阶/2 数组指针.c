//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	// 数组指针,本质是指针,指针指向的内容是数组
//	int arr[10] = { 0 };
//	arr;		// 首元素地址
//	&arr;		// 对整个数组取地址,取出的是整个数组的地址,在加减解引用跳过的是整个数组
//	
//	int* p1 = arr;			// 由于是首元素地址,所以 arr 可以用 int* 类型来存放
//	int(*p2)[10] = &arr;	// 由于是整个数组的地址,所以 &arr 要用数组指针来存放
//
//
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);
//
//	printf("\n");
//
//	printf("%p\n", p1);
//	printf("%p\n", p1 + 1);
//	printf("%p\n", p2);
//	printf("%p\n", p2 + 1);
//
//
//	return 0;
//}