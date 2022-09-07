#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
    int i = 0; // 优先在高地址区域开辟了空间
    // 数组的下标增长是从低到高
    // 数组在往后越界的时候会访问到函数在之前开辟的局部变量
    int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };
    for (int i = 0; i <= 15; i++)
    {
        arr[i] = 0;
    }
    return 0;
}
