#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void revers_str(char* s)
{
    int len = strlen(s);
    char temp = *s;
    *s = *(s + len - 1);
    *(s + len - 1) = '\0';
    if (strlen(s + 1) > 1)
        revers_str(s + 1);
    *(s + len - 1) = temp;
}

int main()
{
    char arr[] = "abcdef";
    printf("%s\n", arr);
    revers_str(arr);
    printf("%s\n", arr);
    return 0;
}