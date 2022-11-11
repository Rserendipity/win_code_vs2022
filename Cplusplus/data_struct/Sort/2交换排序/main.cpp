#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void test1()
{
    const int n = 30;
    int arr[n] = { 0 };
    for (auto& num : arr)
        num = rand() % (n * 2);
    PrintArr(arr, n);

    QuickSort(arr, 0, n - 1);

    PrintArr(arr, n);
}

void test2()
{
    const int n = 50;
    int arr[n] = { 0 };
    for (auto& num : arr)
        num = rand() % (n * 2);
    PrintArr(arr, n);

    MergeSort(arr, n);

    PrintArr(arr, n);
}

void test3()
{
    const int n = 50;
    int arr[n] = { 0 };
    for (auto& num : arr)
        num = rand() % (n * 2);
    PrintArr(arr, n);

    QuickSortNonR(arr, 0, n - 1);

    PrintArr(arr, n);
}

int main()
{
    // srand(time(nullptr));
    // test1();
    // test2();
    test3();
    return 0;
}
