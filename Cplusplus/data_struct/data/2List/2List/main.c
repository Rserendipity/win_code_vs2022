#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void test1()
{
    Node* list = ListInit();
    ListPushBack(list, 1);
    ListPushBack(list, 2);
    ListPushBack(list, 3);
    ListPushBack(list, 4);
    ListPushBack(list, 5);

    ListPrint(list);

    ListPopBack(list);
    ListPopBack(list);

    ListPrint(list);

    ListDestroy(list);
}

void test2()
{
    Node* list = ListInit();
    ListPushBack(list, 1);
    ListPushBack(list, 2);
    ListPushBack(list, 3);
    ListPushBack(list, 4);
    ListPushBack(list, 5);

    ListPrint(list);

    ListPushFront(list, 10);
    ListPushFront(list, 20);

    ListPrint(list);

    ListPopFront(list);
    ListPopFront(list);
    ListPopFront(list);
    ListPopFront(list);
    ListPopFront(list);
    ListPopFront(list);
    ListPopFront(list);

    ListPrint(list);
    ListDestroy(list);
}

void test3()
{
    Node* list = ListInit();
    ListPushBack(list, 1);
    ListPushBack(list, 2);
    ListPushBack(list, 3);
    ListPushBack(list, 4);
    ListPushBack(list, 5);
    ListPrint(list);
    ListPushFront(list, 10);
    ListPushFront(list, 20);
    ListPrint(list);

    Node* pos = ListFind(list, 4);
    if (pos != NULL) {
        ListErase(list, pos);
    }
    ListPrint(list);

    pos = ListFind(list, 2);
    if (pos != NULL) {
        ListInsert(list, pos, 99);
    }
    ListPrint(list);

    ListDestroy(list);
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}
