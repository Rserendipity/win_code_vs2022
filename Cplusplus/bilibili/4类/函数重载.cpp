#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 同一个函数在不同的使用场景下有不同的含义
// 类似于汉语的多音字
// 函数重载是c++多态的体现
// 
// 函数重载的条件：同一个作用域下
// 参数个数不同 
// 参数类型不同 or
// 参数顺序不同
// 满足一个就可以重载
// 

void myFunc(int a)
{
    cout << "int 函数" << endl;
}
void myFunc(int a, int b)
{
    cout << "int,int 函数" << endl;
}
void myFunc(double a, int b)
{
    cout << "double,int函数" << endl;
}
void myFunc(int a, double b)
{
    cout << "int,double函数" << endl;
}
void test1()
{
    myFunc(10);
    myFunc(10, 20);
    myFunc(10, 20.2);
    myFunc(10.5, 10);
}
int main() 
{
    test1();
    return 0;
}
