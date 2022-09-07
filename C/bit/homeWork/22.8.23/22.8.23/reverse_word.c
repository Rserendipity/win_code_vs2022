#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char str[10001] = { 0 };
    char ch = 0;
    int  i = 0;
    for (i = 0; (ch = getchar()) != '\n'; i++)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            str[i] = ch;
        else
        {
            if (i == 0)
                str[i] = ' ';
            if (i > 0 && str[i - 1] != ' ')
                str[i] = ' ';
        }
    }
    int head = 0, tail = i - 1;
    while (head < tail)
    {
        ch = str[head];
        str[head] = str[tail];
        str[tail] = ch;
        head++;
        tail--;
    }
    int index = 0;
    head = 0;
    tail = 0;
    for (int j = 0; ; j++)
    {
        if (str[j] == ' ' || str[j] == '\0')
        {
            tail = j - 1;
            while (head < tail)
            {
                ch = str[head];
                str[head] = str[tail];
                str[tail] = ch;
                head++;
                tail--;
            }
            head = j + 1;
            if (str[j] == '\0')
                break;
        }
    }
    printf("%s\n", str);
    return 0;
}