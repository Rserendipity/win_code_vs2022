#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void* my_memcpy(void* des, const void* sou, size_t num)
{
    char* m = (char*)des;
    char* s = (char*)sou;
    if (des > sou)
    {
        m += num - 1;
        s += num - 1;
        while (num--)
        {
            *m = *s;
            m--;
            s--;
        }
    }
    else
    {
        while (num--)
        {
            *m = *s;
            m++;
            s++;
        }
    }
    return des;
}

void test1()
{
    char arr[] = "22490778622222@qq.com";
    const char p[] = "2@.";

    for (char* s = strtok(arr, p); s != NULL; s = strtok(NULL, p))
    {
        printf("%s\n", s);
    }

    char arr1[] = "1234567";
    my_memcpy(arr1 + 2, arr1, 4);
    printf("%s", arr1);
}

int yang(int x, int y)
{
    if (y == 1 || x == y)
    {
        return 1;
    }
    else
    {
        return yang(x - 1, y) + yang(x - 1, y - 1);
    }
}

int main() 
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", yang(i, j));
        }
        printf("\n");
    }
    return 0;
}
