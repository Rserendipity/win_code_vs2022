#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base {
public:
    static int data;
    int num;
    Base() :num(0)
    {
        cout << "Base wucan" << endl;
    }
    Base(int a) :num(a)
    {
        cout << "Base youcan" << endl;
    }
    ~Base()
    {
        cout << "Base xigou" << endl;
    }
    void ShowNum()
    {
        cout << "fulei:" << num << endl;
    }
    void ShowNum(int x)
    {
        cout << "fulei:int :" << x << endl;
    }
};

int Base::data = 100;

class Son:public Base {
public:
    int num;
    static int data;

    Son(int x, int y) :num(x), Base(y)
    {
        cout << "Son youcan" << endl;
    }
    void show()
    {
        // 加上作用域，调用父类的数据
        cout << "Base: " << Base::num << endl;
        cout << "Son : " << num << endl;
    }



    void ShowNum()
    {
        cout << "zilei de shownum:" << num << endl;
    }
};

int Son::data = 300;

/// <summary>
/// 数据同名
/// </summary>
void test1()
{
    Son s(10, 20);
    s.show();
}

/// <summary>
/// 成员函数同名
/// </summary>
void test2()
{
    // 继承会继承所有的成员函数（除去构造和析构）和成员变量
    // 构造和析构 只有父类自己知道怎么做
    // 
    // 一旦子类实现了一个父类的同名函数
    // 编译器会屏蔽掉所有的重载函数
    // 除非加上父类的作用域才可以调用
    // 

    Son s1(10, 20);
    s1.ShowNum(); // fulei
    s1.show();    // zilei
    s1.Base::ShowNum();
}

/// <summary>
/// 静态成员同名
/// </summary>
void test3()
{
    // 子类和父类的静态变量同名了
    // 默认访问子类的
    // 想要访问父类的要加上作用域
    // 
    cout << Base::data << endl;
    cout << Son::data << endl;
    cout << Son::Base::data << endl;
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}
