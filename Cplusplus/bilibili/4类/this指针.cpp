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
    }
    void setNum(int num)
    {
        this->data = num;
    }
    int getNum()
    {
        return this->data;
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

int main() 
{
    test1();
    return 0;
}
