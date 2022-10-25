#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test1()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPushBack(&sl, 4);
    SLPushBack(&sl, 5);
    SLPrint(&sl);

    SLPopBack(&sl);
    SLPopBack(&sl);
    SLPopBack(&sl);
    SLPopBack(&sl);
    SLPopBack(&sl);
    SLPopBack(&sl);

    SLPushBack(&sl, 5);
    SLPushBack(&sl, 5);
    SLPushBack(&sl, 5);

    SLPrint(&sl);
    SLDistory(&sl);
}

int main()
{
    test1();
    return 0;
}
