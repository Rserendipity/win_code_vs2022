#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* my_strstr(const char* des, const char* s)
{
    const char* m = des;
    const char* p = s;
    while (*m)
    {
        m = des;
        p = s;
        while (*m == *p && *p != '\0')
        {
            m++;
            p++;
        }
        if (*p == '\0')
            return des;
        des++;
    }
    return NULL;
}
int main()
{
    char arr1[] = "abcabc";
    char arr2[] = "cab";
    printf("%s", my_strstr(arr1, arr2));
    return 0;
}
