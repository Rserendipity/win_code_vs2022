#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int is_pre(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() 
{
    int input = 0;
    scanf("%d", &input);
    int* arr = (int*)calloc(sizeof(int) * 100000000, 1);
    int count = 0;

    int i = 2;
    while (input > 1)
    {
        if (input % i == 0)
        {
            arr[count++] = i;
            input /= i;
        }
        else
            i++;
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i] == 0)
            break;
        printf("%d ", arr[i]);
    }
    return 0;
}