#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNums(int* next, char* s, int len)
{
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && s[j] != s[i])
        {
            j = next[j - 1];
        }
        if (s[j] == s[i])
            j++;
        next[i] = j;
    }
}

int main()
{
    char s[] = "aabaaf";
    int len = strlen(s);
    int* nums = (int*)malloc(sizeof(int));

    getNums(nums, s, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}