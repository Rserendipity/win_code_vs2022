#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() 
{
    int i = 1;
    int ret = ++i + ++i + ++i;
    printf("%d\n", ret);
    return 0;
}
