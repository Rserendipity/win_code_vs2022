#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base {
public:
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
};

class Son:public Base {
public:
    int num;
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
};

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

}

int main()
{
    test1();
    test2();
    return 0;
}
