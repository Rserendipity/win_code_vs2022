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

void PrintTopK(int* arr, int size, int k)
{
    Hp h;
    HeapInit(&h);
    for (int i = 0; i < k; i++)
    {
        HeapPush(&h, arr[i]);
    }
    for (int i = k; i < size; i++)
    {
        if (arr[i] > HeapTop(&h))
        {
            HeapPop(&h);
            HeapPush(&h, arr[i]);
        }
    }

    HeapPirnt(&h);
    HeapDestroy(&h);
}

void test3()
{
    Hp h;
    HeapInit(&h);
 
    for (int i = 0; i < 10; i++)
    {
        HeapPush(&h, rand() % 100);
    }
    HeapPirnt(&h);
    
    HeapDestroy(&h);
}

void TopK()
{
    int n = 10000;
    int* a = (int*)malloc(sizeof(int) * n);
    srand(time(0));
    for (size_t i = 0; i < n; ++i)
    {
        a[i] = rand() % 1000000;
    }
    a[5] = 1000000 + 1;
    a[1231] = 1000000 + 2;
    a[531] = 1000000 + 3;
    a[5121] = 1000000 + 4;
    a[115] = 1000000 + 5;
    a[2335] = 1000000 + 6;
    a[9999] = 1000000 + 7;
    a[76] = 1000000 + 8;
    a[423] = 1000000 + 9;
    a[3144] = 1000000 + 10;
    PrintTopK(a, n, 11);
}

int main()
{
    // test1();
    // test2();
    TopK();
    // test3();

    return 0;
}
