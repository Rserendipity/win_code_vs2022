#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

void test1()
{
    Hp heap;
    HeapInit(&heap);

    HeapPush(&heap, 70);
    HeapPush(&heap, 56);
    HeapPush(&heap, 30);
    HeapPush(&heap, 25);
    HeapPush(&heap, 15);
    HeapPush(&heap, 10);
    HeapPush(&heap, 75);

    HeapPirnt(&heap);

    HeapPop(&heap);

    HeapPirnt(&heap);

    HeapPush(&heap, 100);
    HeapPush(&heap, 200);
    HeapPirnt(&heap);

    HeapDestroy(&heap);
}


void test2()
{
    int arr[] = { 10,2345,352,35,67,2,456 };
    for (int i = (7 - 1) / 2; i >= 0; i--)
    {
        CheckHeapUp(arr, i);
    }

    for (int i = 6; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        CheckHeapDown(arr, 0, i);
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // test1();
    test2();

    return 0;
}
