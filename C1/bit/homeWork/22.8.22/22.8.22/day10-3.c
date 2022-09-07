#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
    int w = 1, x = 2, y = 3, z = 4; 
    printf("%d", w < x ? w : y < z ? y : z);
    return 0;
}