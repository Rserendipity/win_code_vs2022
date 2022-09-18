#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    double d;
    char c;
    int i;
}Node;

struct A{
    char c1;
    Node node;
    double d;
};

int main() 
{
    printf("%d", sizeof(struct A));
    return 0;
}
