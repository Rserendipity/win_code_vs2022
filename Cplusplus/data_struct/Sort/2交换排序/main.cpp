#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void test1()
{
    const int n = 10;
    int arr[n] = { 0 };
    for (auto& num : arr)
        num = rand() % (n * 2);
    PrintArr(arr, n);

    QuickSort(arr, 0, n - 1);

    PrintArr(arr, n);
}


int main()
{
    // srand(time(nullptr));
    test1();

    return 0;
}
