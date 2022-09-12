#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


class Data {
public:
    Data()
    {
        // this 指针指向的当前对象的成员
        // 所以用this指针指向的对应的变量就可以找到对应对象的值
        this->data = 10;
        this->a = 1;
    }
    void setNum(int num)
    {
        this->data = num;
    }
    int getNum()
    {
        return this->data;
    }
    // 在函数的右边加上const就可以告诉编译器，这是一个常函数
    // 注：当把const放到左边的时候表示的是返回值是一个常量
    // 这个函数不会在函数内部更改成员对象的值
    // 当变量声明成 mutable 时，可以在常函数内更改
    void printData() const 
    {
        // this->data = 100; // err 函数已经被声明成了常函数，内部不可以修改
        this->a = 100l; // 可以修改，a是 mutable 变量
        cout << this->data << endl;
        cout << this->a << endl;
    }
    Data& getThis()
    {
        return *this;
    }
private:
    // 非静态成员变量直接存储在类中
    // 数据和方法被封装在一起，但是他们是分开存储的
    // 每个对象有独立的非静态数据
    // 所有的对象共用所有的方法
    // 
    int data;

    // a变量可以在常函数中被更改
    mutable int a;
};
/// <summary>
/// this指针
/// </summary>
void test1()
{
    Data d1;
    d1.setNum(10);
    cout << d1.getNum() << endl;

    Data d2;
    d1.setNum(20);
    cout << d1.getNum() << endl;

    Data d3;
    d1.setNum(30);
    cout << d1.getNum() << endl;

    cout << &d3.getThis().getThis().getThis() << endl;

    auto d4 = new Data;
    d4->setNum(100);
    cout << d4->getThis().getNum() << endl;

}

/// <summary>
/// const修饰成员函数
/// </summary>
void test2()
{
    Data d1;
    d1.printData();
}

/// <summary>
/// const对象
/// </summary>
void test3()
{
    // 常对象只能调用const修饰的函数
    // 普通的成员函数被编译器认为是不安全的
    // 可能发生对成员的修改，而常对象又不允许被修改
    // 
    const Data d1; // 构造时，a的值时1
    // d1中的a是mutable变量，在print函数中修改了他的值
    d1.printData(); // 打印输出a的值时100
}

int main() 
{
    // test1();
    // test2();
    test3();
    return 0;
}
