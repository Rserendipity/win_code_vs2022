#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int reverse(int x, int wei)
{
    if (x < 10)
    {
        return x;
    }
    else
    {
        return x % 10 * (int)pow(10, --wei) + reverse(x / 10, wei);
    }

}
int main() 
{
    int in = 0;
    scanf("%d", &in);
    int temp = in;
    int flag = 1;
    while (temp /= 10) {
        flag++;
    }

    printf("%d\n", reverse(in, flag));
    return 0;
}
