#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void Sleep()
    {
        cout << "动物在睡觉" << endl;
    }
};

class Dog :public Animal {
public:
    void Sleep()
    {
        cout << "Dog在睡觉" << endl;
    }
};

class Cat :public Animal {
public:
    void Sleep()
    {
        cout << "cat在睡觉" << endl;
    }
};

class Horse :public Animal {
public:
    void Sleep()
    {
        cout << "Horse在睡觉" << endl;
    }
};

/// <summary>
/// 父类引用作为参数，可以通过传入不同的对象，调用不同对象的方法，实现动态多态
/// </summary>
/// <param name="animal"> 父类引用 </param>
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
