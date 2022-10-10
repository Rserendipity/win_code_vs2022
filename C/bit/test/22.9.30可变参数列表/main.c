#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int myFun(int num, ...)
{
    va_list arg;
    __crt_va_start(arg, num);
    for (int i = 0; i < num; i++) 
    {
        int max = __crt_va_arg(arg, int);
        printf("%d ", max);
    }
    __crt_va_end(arg);
    return 0;
}

int main() 
{
    printf("max = %d", 4 < 5 < 3);
    return 0;
}
