#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() = 0;
    virtual ~Base() = 0;
};

// ������������Ҫ������ʵ�ֶ���
// ���ø���ָ������ò��������
// �ͷ�����Ķ�����Զ����ø��������
// ���Ա���Ҫʵ����������Ķ���
Base::~Base()
{
    cout << "���Ǹ������������" << endl;
}

class Son :public Base {
    void show()
    {
        cout << "���������show����" << endl;
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
