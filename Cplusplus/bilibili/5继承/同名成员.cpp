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
        // ���������򣬵��ø��������
        cout << "Base: " << Base::num << endl;
        cout << "Son : " << num << endl;
    }
};

/// <summary>
/// ����ͬ��
/// </summary>
void test1()
{
    Son s(10, 20);
    s.show();
}

/// <summary>
/// ��Ա����ͬ��
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
