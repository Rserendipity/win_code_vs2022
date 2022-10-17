#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

long long count(int days, int second) {
    if (days == 1) {
        return 1;
    }
    else if (days == 2) {
        return second;
    }
    else {
        return count(days - 1, second) + count(days - 2, second) * 2;
    }
}

int main() 
{
    int input = 0;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        int second = 0;
        scanf("%d", &second);

        printf("%lld", count(30, second));
    }

    return 0;
}
