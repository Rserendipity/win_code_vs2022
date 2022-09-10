#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


class Person {
public:
    Person()
    {
        this->num = 0;
    }
    Person(int num)
    {
        this->num = num;
    }
    ~Person()
    {

    }
    // 普通的成员函数必须通过对象调用，所以必须先创建对象
    // 如果没有实例化对象就访问不了
    int getData() 
    {
        return this->data;
    }
    void setData(int val)
    {
        this->data = val;
    }

    // 静态成员函数
    // 函数公有，可以直接通过类名访问
    // 也可以通过对象来访问
    // 
    static int getDataByStatic()
    {
        return data;
    }
    static void setDataByStatic(int num)
    {
        data = num;
    }

 private:
    // static修饰的成员变量是静态的
    // 即所有的对象共用这个一个变量，静态成员属于类，不属于对象
    // 静态变量在编译时期就分配了空间
    // 没有创建任何对象的时候就已经存在
    // 类没有空间，只是类型，静态成员不算做类的类型空间
    // 即在sizeof类名的时候不算static的空间大小
    // 因此，静态成员变量必须在类内定义，在外部实现
    // 
    static int data; // 静态成员
    int num; // 普通变量
};
int Person::data = 100;

void test1()
{
    //// 直接访问，要求data的权限是公开的
    //cout << Person::data << endl;

    // 使用类来访问
    Person p1;
    cout << p1.getData() << endl;
    // 通过一个对象更改静态变量后，其余对象访问到的也会改变
    p1.setData(2000);

    Person p2;
    cout << p2.getData() << endl; // 2000，已被改变
    
    // 通过静态类函数直接访问类的静态成员
    cout << Person::getDataByStatic() << endl; 

    // 通过静态类函数直接修改静态成员
    Person::setDataByStatic(1234);

    // 也可以通过
    cout << p2.getDataByStatic() << endl;
}

int main() 
{
    test1();
    return 0;
}
