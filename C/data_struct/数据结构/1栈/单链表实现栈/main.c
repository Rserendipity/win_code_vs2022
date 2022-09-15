#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#define OPT 10


int main() 
{
    void* p = malloc(sizeof(1));
    srand((unsigned int)p);
    free(p);

    Stack* s = StackInit();
    
    for (int i = 0; i < OPT; i++)
    {
        int val = rand() % OPT;
        printf("%d ", val);
        StackPush(s, val);
    }
    printf("\n");
    
    for (int i = 0; i < OPT; i++)
    {
        printf("%d ", StackPop(s));
    }
    printf("\n");

    return 0;
}
