#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void* my_memove(void* des, void* s, size_t size)
{
    char* m = (char*)des;
    char* p = (char*)s;
    if (m > p)
    {
        while (size--)
        {
            *(m + size) = *(p + size);
        }
    }
    else
    {
        while (size--)
        {
            *m = *p;
            m++;
            p++;
        }
    }
}

int main() 
{
    char arr[] = "abcdefg";
    my_memove(arr + 2, arr, 4);
    printf("%s", arr);
    return 0;
}
