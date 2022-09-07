#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int isPre(int n) {
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	for (int i = 100; i <= 200; i++) {
		if (isPre(i))
			printf("%d ", i);
	}
	return 0;
}