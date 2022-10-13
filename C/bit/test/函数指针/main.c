#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}

int main()
{
    int (*p)(int, int) = add;

    printf("%p\n", p);
    printf("%p\n", add);
    int (*parr[1])(int, int) = { add };

    printf("%p\n", parr[0]);
    printf("%p\n", add);
    return 0;
}