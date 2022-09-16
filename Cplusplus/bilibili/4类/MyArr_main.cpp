#define _CRT_SECURE_NO_WARNINGS 1
#include "MyArr.h"
int main() 
{
    int arr[] = { 1,2,3,4,5,6 };
    MyArr a(arr, 6);
    a.PushByTail(10);
    a.PushByHead(20);
    a.PushByPos(30, 0);
    a.PushByPos(40, 2);
    a.PushByPos(100, 12);

    a.ShowAllVal();
    
    a.PopByHead();
    a.PopByHead();
    
    a.ShowAllVal();

    a.PopByTail();
    a.PopByPos(1);

    a.ShowAllVal();

    a.~MyArr();

    return 0;
}
