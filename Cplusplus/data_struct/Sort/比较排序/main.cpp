#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void test1()
{
    int arr[10] = { 0 };
    for (auto& n : arr)
    {
        n = rand() % 100;
    }

    PrintArr(arr, 10);
    InsertSort(arr, 10);
    PrintArr(arr, 10);
}

void test2()
{
    int arr[10] = { 0 };
    for (auto& n : arr)
    {
        n = rand() % 100;
    }

    PrintArr(arr, 10);
    ShellSort(arr, 10);
    PrintArr(arr, 10);
}

void test3()
{
    int arr[10] = { 0 };
    for (auto& n : arr)
    {
        n = rand() % 100;
    }

    PrintArr(arr, 10);
    SelectSort(arr, 10);
    PrintArr(arr, 10);
}

void test4()
{
    int arr[10] = { 0 };
    for (auto& n : arr)
    {
        n = rand() % 100;
    }

    PrintArr(arr, 10);
    HeapSort(arr, 10);
    PrintArr(arr, 10);
}


int main()
{
    srand(time(0));
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}
