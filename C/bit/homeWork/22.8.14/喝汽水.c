#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int drink(int money, int lid) {
	if (money == 0 || lid <= 2) {
		return 0;
	} else {
		lid += money;
		lid += money % 2;
		return money + drink(lid / 2, lid % 2);
	}
}

int main() {
	int n = 20;
	printf("%d", drink(n, 0));
	return 0;
}