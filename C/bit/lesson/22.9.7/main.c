#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Test
{
    char* pc;    // 4
    short sData; // 2
    int num;     // 4 
    short sBa[4];// 8
    char cha[2]; // 2
}p;

int main() 
{
    int arr[5][5];
    int(*p)[4] = arr;
    printf("%p  %d", &p[4][2] - &arr[4][2] ,&p[4][2] - &arr[4][2]);
    return 0;
}
