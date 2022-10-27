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

void test2()
{
    SL sl;
    SLInit(&sl);

    SLPushBack(&sl, 5);

    SLPushFront(&sl, 1);
    SLPushFront(&sl, 2);
    SLPushFront(&sl, 3);

    SLPopFront(&sl);

    SLPrint(&sl);
    SLDistory(&sl);
}

void test3()
{
    SL sl;
    SLInit(&sl);

    SLInsert(&sl, 1, 0);
    SLInsert(&sl, 2, 0);
    SLInsert(&sl, 3, 0);
    SLPrint(&sl);

    SLInsert(&sl, 10, 1);
    SLInsert(&sl, 20, 1);
    SLInsert(&sl, 30, 1);
    SLPrint(&sl);

    SLErase(&sl, 2);
    SLErase(&sl, 2);
    SLErase(&sl, 2);
    SLErase(&sl, 2);
    SLPrint(&sl);

    printf("index = %d\n", SLFind(&sl, 30));

    SLDistory(&sl);
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}
