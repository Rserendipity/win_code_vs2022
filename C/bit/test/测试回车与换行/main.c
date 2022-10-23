#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    const char* s = "\n\r";
    printf("%d %d", s[0], s[1]);
    return 0;
}
