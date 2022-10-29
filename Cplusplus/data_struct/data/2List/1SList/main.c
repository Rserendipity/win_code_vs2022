#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void test1()
{
    Node* list = NULL;
    SListPushBack(&list, 1);
    SListPushBack(&list, 2);
    SListPushBack(&list, 3);
    SListPushBack(&list, 4);

    SListPushFront(&list, 10);
    SListPushFront(&list, 20);

    SListPrint(list);
    SListDistory(list);
}

void test2()
{
    Node* list = NULL;
    SListPushBack(&list, 1);
    SListPushBack(&list, 2);
    SListPushBack(&list, 3);
    SListPushBack(&list, 4);
    SListPrint(list);

    SListPopBack(&list);
    SListPopBack(&list);
    SListPopBack(&list);
    SListPrint(list);

    SListPopBack(&list);

    SListPrint(list);
    SListDistory(list);
}

void test3()
{
    Node* list = NULL;
    SListPushBack(&list, 1);
    SListPushBack(&list, 2);
    SListPushBack(&list, 3);
    SListPushBack(&list, 4);

    SListPushFront(&list, 10);
    SListPushFront(&list, 20);
    SListPrint(list);

    SListPopFront(&list);
    SListPopFront(&list);
    SListPopFront(&list);
    SListPrint(list);

    SListPushFront(&list, 20);
    SListPushFront(&list, 20);

    SListPopFront(&list);
    SListPopFront(&list);
    SListPopFront(&list);

    SListPrint(list);
    SListDistory(list);
}

void test4()
{
    Node* list = NULL;
    SListInsert(&list, 1, 0);
    SListInsert(&list, 2, 0);
    SListInsert(&list, 3, 0);
    SListInsert(&list, 4, 0);

    SListInsert(&list, 5, 3);


    SListPrint(list);
    SListDistory(list);
}

void test5()
{
    Node* list = NULL;
    SListInsert(&list, 1, 0);
    SListInsert(&list, 2, 0);
    SListInsert(&list, 3, 0);
    SListInsert(&list, 4, 0);
    SListInsert(&list, 5, 3);
    SListPrint(list);

    SListErase(&list, 2);
    SListPrint(list);

    SListErase(&list, 2);
    SListPrint(list);

    SListErase(&list, 2);
    SListPrint(list);

    SListErase(&list, 1);
    SListPrint(list);

    SListErase(&list, 0);
    SListPrint(list);


    SListDistory(&list);
}

void test6()
{
    Node* list = NULL;
    SListInsert(&list, 1, 0);
    SListInsert(&list, 2, 0);
    SListInsert(&list, 3, 0);
    SListInsert(&list, 4, 0);
    SListInsert(&list, 5, 3);
    SListInsert(&list, 3, 2);
    SListInsert(&list, 3, 3);


    int i = 0;
    for (Node* pos = SListFind(list, 3); pos != NULL; pos = SListFind(pos->next, 3))
    {
        printf("this is %d , pos is %p\n", i++, pos);
    }

    SListDistory(&list);
}

void test7()
{
    Node* list = NULL;
    SListPushBack(&list, 1);
    SListPushBack(&list, 2);
    SListPushBack(&list, 3);
    SListPushBack(&list, 4);
    SListPrint(list);

    Node* pos = SListFind(list, 2);
    if (pos != NULL)
    {
        SListInsertByFind(&list, 30, pos);
    }
    SListPrint(list);

    SListDistory(&list);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}
