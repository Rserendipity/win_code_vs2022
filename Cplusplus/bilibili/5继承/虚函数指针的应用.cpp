#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void Sleep()
    {
        cout << "������˯��" << endl;
    }
};

class Dog :public Animal {
public:
    void Sleep()
    {
        cout << "Dog��˯��" << endl;
    }
};

class Cat :public Animal {
public:
    void Sleep()
    {
        cout << "cat��˯��" << endl;
    }
};

class Horse :public Animal {
public:
    void Sleep()
    {
        cout << "Horse��˯��" << endl;
    }
};

/// <summary>
/// ����������Ϊ����������ͨ�����벻ͬ�Ķ��󣬵��ò�ͬ����ķ�����ʵ�ֶ�̬��̬
/// </summary>
/// <param name="animal"> �������� </param>
void Sleep(Animal& animal) 
{
    animal.Sleep();
}

void test1()
{
    Dog d;
    Cat c;
    Horse h;
    Sleep(d);
    Sleep(c);
    Sleep(h);
}

int main() 
{
    test1();
    return 0;
}
