#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char arr[1001] = { 0 };
    gets(arr);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        putchar(arr[i]);
    return 0;
}