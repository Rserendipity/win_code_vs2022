#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

void test1() {
	int x = 0;
	int y = 0;

	scanf("%d%d", &x, &y);

	int min = x > y ? y : x;

	// 暴力遍历
	for (int i = min; i >= 1; i++) {
		if (x % i == 0 && y % i == 0) {
			printf("%d", i);
			break;
		}
	}
}

void test2() {
	int x = 0;
	int y = 0;

	scanf("%d%d", &x, &y);

	// 辗转相除法
	int t = x % y;
	while (t) {
		x = y;
		y = t;
		t = x % y;
	}
	printf("%d", y);
}

int main() {
	// test1();
	test2();


	return 0;
}