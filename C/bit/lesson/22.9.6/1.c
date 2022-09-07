#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>

int Yangh(int m, int n) {
    if (n == 0 || n == m) {
        return 1;
    } else {
        return Yangh(m - 1, n) + Yangh(m - 1, n - 1);
    }
}
int main() {
    int m = 5;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", Yangh(i, j));
        }
        printf("\n");
    }
    return 0;
}