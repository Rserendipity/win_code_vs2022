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

template<class T>
T funcT1(T a, T b) 
{
    return a + b;
}

template<class T>
void funcT2() 
{
    cout << "funcT2" << endl;
}

template<class T1, class T2, class T3>
T3 funcT3(T1 a, T2 b) 
{
    return a + b;
}

template<class T3, class T1, class T2>
T3 funcT4(T1 a, T2 b) 
{
    return a + b;
}

/// <summary>
/// 参数推导
/// </summary>
void test2()
{
    // 编译器会通过传入的参数推导模板类型
    cout << funcT(10, 20) << endl; // 传入的是int，参数推导也是int
    cout << funcT(10.13, 20.43) << endl; // 传入的是double，参数推导也是double

    // 也可以强制指定类型，按照强制指定的类型进行相应的函数调用
    cout << funcT<double>(10, 20) << endl; // 传入的是double，强制调用double


    cout << funcT1(10, 20) << endl; // 默认让他自己推导
    cout << funcT1<>(10, 20) << endl; // 可以不指定类型，自动推导
    // cout << funcT1(10, 20.567) << endl; //这种写法，传了两个不同类型的参数，编译器无法推导用哪种类型，在函数模板里面，无法进行隐式类型转换
    cout << funcT1<int>(10, 20.567) << endl;//但是可以显式指定类型
    cout << funcT1<double>(10, 20.567) << endl;//要么告诉编译器是什么类型，要么让其自动推导，但是要保证同一个类型参数的数据类型必须一样


    //funcT2(); // 虽然在函数中没有使用到类型参数，但是也必须得告诉编译器，这里要调用的是函数模板
    funcT2<int>(); // 因为没有参数，所以编译器就没办法根据参数推导出类型，所以必须得强制指定


    //cout<<funcT3(a,b)<<endl;//这种写法，有三个类型参数，但是只传了两个值，所以编译器无法推导出最后一个类型
    cout << funcT3<int, int, int>(10, 20) << endl;
    cout << funcT4<int>(10, 20) << endl;//此处，第一个类型参数要指定，第二个，第三个，可以由编译器自动推导
}

/// <summary>
/// 函数模板的调用时机
/// </summary>
void test3()
{
    // 函数模板在编译期间确定，所以在编译到函数调用这里才会确定函数模板的具体类型
    funcT<int>(10, 20);       // 生成了一个int型的函数
    funcT<double>(10, 20.2);  // 生成了一个doubel型的函数
}

template <typename T>
T add(T x, T y)
{
    cout << "函数模板" << endl;
    return x + y;
}
int add(int x, int y)
{
    cout << "普通函数" << endl;
    return x + y;
}
/// <summary>
/// 函数模板与普通函数之间的重载
/// </summary>
void test4()
{
    cout << add(10, 20) << endl; // 默认调用的是普通的函数
    cout << add<int>(10, 20) << endl; // 显式的指定了调用函数模板

}




//指定类型和值
template<class T1, class T2 = int> // 这里表示的是类型参数的默认值
void funcT1(T1 a, T2 b = 123) 
{
    // 这里表示的是函数中T2类型的参数的默认值
    cout << a << endl;
    cout << b << endl;
}
//指定类型
template<class T1 = int, class T2>
void funcT2(T2 b) 
{
    T1 a = b;
    cout << b << "--" << a << endl;
}

/// <summary>
/// 模板的默认类型以及参数
/// </summary>
void test5()
{
    funcT1<char>('a'); // t1 为char型， t2没有指定，所以默认给了int型
    funcT2<>('a');

}

int main() 
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}
