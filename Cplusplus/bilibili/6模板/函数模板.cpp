#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 普通函数
int func1(int a, int b) 
{
    return a + b;
}
double func2(double a, double b) 
{
    return a + b;
}

// template<class T>
template<typename T>
T funcT(T a, T b) 
{
    return a + b;
}

/// <summary>
/// 函数模板定义
/// </summary>
void test1()
{
    // 所谓函数模板，实际就是写一个通用函数，返回值和参数的类型都是可变的，用一个特定格式的变量来指定
    // 然后调用此函数的时候，编译器会根据参数的数据类型，自动推导类型，从而达到函数在不同的类型参数下可复用的目的
    // 这个通用函数，就是函数模板
    // 
    // template<class T>  T是一个变量名，不是固定非要用T，写T是一个编程习惯，除了用class 关健字之外，还可以用 typename
    // 参数也可以有多个, T1, T2等
    int a = 1;
    int b = 2;

    double c = 1.1;
    double d = 2.2;

    int x = func1(a, b);
    double y = func2(c, d);
    cout << x << "--" << y << endl;

    int X = funcT(a, b);
    double Y = funcT(c, d);
    cout << X << "--" << Y << endl;
}

int main() 
{
    test1();



    return 0;
}
