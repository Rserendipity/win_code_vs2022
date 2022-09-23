#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
/// <summary>
/// 0 正常转换
/// -1 下限溢出
/// 1 上线溢出
/// 
/// </summary>
int AtoiFlag = 0;

int atoi(const char* str)
{
    int flag = 1;
    if (*str == '-')
    {
        flag = -1;
        str++;
    }
    if (*str == '+')
    {
        flag = 1;
        str++;
    }

    long long num = 0;
    while (isdigit(*str) && *str != '\0')
    {
        num = num * 10 + *str - '0';
        str++;
    }
    num *= flag;
    if (num > INT_MAX) // 上限溢出
    {
        AtoiFlag = 1;
        return INT_MAX;
    }
    else if (num < INT_MIN)
    {
        AtoiFlag = -1;
        return INT_MIN;
    }
    else
    {
        return num;
    }
}

int main() 
{
    printf("%d\n", atoi("-123"));
    return 0;
}
