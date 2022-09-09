#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int arr[3] = { 0 };
    while (scanf("%d%d%d", &arr[0], &arr[1], &arr[2]) != EOF)
    {
        qsort(arr, 3, sizeof(int), cmp);
        if (arr[0] + arr[1] <= arr[2])
            printf("Not a triangle!\n");
        else if (arr[0] == arr[1] == arr[2])
            printf("Equilateral triangle!\n");
        else if (arr[0] == arr[1])
            printf("Isosceles triangle!\n");
        else if (arr[1] == arr[2])
            printf("Isosceles triangle!\n");
        else
            printf("Ordinary triangle!\n");
    }
    return 0;
}