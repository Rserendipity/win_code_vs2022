#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char* s)
{
    const char* head = s;
    const char* tail = s;
    while (*tail != '\0')
    {
        tail++;
    }
    return tail - head;
}

char* my_strcpy(char* sourse, const char* des)
{
    char* m = sourse;
    while (*des)
    {
        *m++ = *des++;
    }
    return sourse;
}

char* my_strcat(char* sourse, const char* des)
{
    char* m = sourse;
    while (*m)
        m++;
    while (*m++ = *des++)
        ;
    return sourse;
}

int my_strcmp(const char* s1, const char* s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char* my_strstr(const char* s, const char* des)
{
    const char* m = s;
    const char* p = des;
    assert(s && des);
    while (*s)
    {
        m = s;
        p = des;
        while (*m == *p && *p != '\0')
        {
            m++;
            p++;
        }
        if (*p == '\0')
            return s;
        s++;
    }
    return NULL;
}

int main() 
{
    char arr[20] = "abcdefabcdef";
    const char* s = "fab";
    printf("%s\n", my_strstr(arr, s));
    return 0;
}
