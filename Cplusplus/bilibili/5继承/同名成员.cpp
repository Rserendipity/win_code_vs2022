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
        // ���������򣬵��ø��������
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
    // �̳л�̳����еĳ�Ա��������ȥ������������ͳ�Ա����
    // ��������� ֻ�и����Լ�֪����ô��
    // 
    // һ������ʵ����һ�������ͬ������
    // �����������ε����е����غ���
    // ���Ǽ��ϸ����������ſ��Ե���
    // 

    Son s1(10, 20);
    s1.ShowNum(); // fulei
    s1.show();    // zilei
    s1.Base::ShowNum();
}

/// <summary>
/// ��̬��Աͬ��
/// </summary>
void test3()
{
    // ����͸���ľ�̬����ͬ����
    // Ĭ�Ϸ��������
    // ��Ҫ���ʸ����Ҫ����������
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
