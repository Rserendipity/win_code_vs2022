#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int myFun(int num, ...)
{
    va_list arg;
    __crt_va_start(arg, num);
    int max = __crt_va_arg(arg, int);
    for (int i = 1; i < num; i++) 
    {
        int temp = __crt_va_arg(arg, int);
        if (temp > max)
            max = temp;
    }
    __crt_va_end(arg);
    return max;
}

int main() 
{
    printf("max = %d", myFun(6, 10, 20, 30, 40, 50, 100));
    return 0;
}
