#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() = 0;
    virtual ~Base() = 0;
};

// 纯虚析构必须要在类外实现定义
// 在用父类指针或引用操作子类后
// 释放子类的对象会自动调用父类的析构
// 所以必须要实现这个函数的定义
Base::~Base()
{
    cout << "这是父类的析构调用" << endl;
}

class Son :public Base {
    void show()
    {
        cout << "这是子类的show调用" << endl;
    }
};

void test1()
{
    Base* b = new Son;
    b->show();
    delete b;
}

int main()
{
    test1();
    return 0;
}
