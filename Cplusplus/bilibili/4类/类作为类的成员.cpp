//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class A {
//private:
//    int a;
//public:
//    A()
//    {
//        cout << "A无参构造" << endl;
//    }
//    A(int a)
//    {
//        this->a = a;
//        cout << "A有参构造" << endl;
//    }
//    ~A()
//    {
//        cout << "A的析构" << endl;
//    }
//};
//class B {
//private:
//    int b;
//public:
//    B()
//    {
//        cout << "B无参构造" << endl;
//    }
//    B(int b)
//    {
//        this->b = b;
//        cout << "B有参构造" << endl;
//    }
//    ~B()
//    {
//        cout << "B的析构" << endl;
//    }
//};
//class Data {
//private:
//    A a;
//    B b;
//    int data;
//public:
//    Data()
//    {
//        cout << "Data无参构造" << endl;
//    }
//    Data(int a, int b, int c):a(a),b(b),data(c)
//    {
//        cout << "Data有参构造" << endl;
//    }
//    ~Data()
//    {
//        cout << "Data析构" << endl;
//
//    }
//};
///// <summary>
///// 对象成员的初始化：初始化列表
///// </summary>
//void test1()
//{
//    // 先调用成员的构造函数
//    // 在调用自己的构造函数
//    // 先析构自身，在析构对象成员
//    // 
//    // 系统默认调用的是成员的无参构造
//    // 用初始化列表调用成员的其他构造函数
//    // 
//    // Data temp; // 类内的子类默认使用的是无参构造
//    Data temp2(10, 20, 30); // 使用了初始化列表，子类调用了有参构造
//}
//
//class Temp {
//private:
//    int a;
//public:
//    explicit Temp(int num) // explicit修饰后禁止隐式转换
//    {
//        cout << num << endl;
//    }
//};
///// <summary>
///// explicit关键字：禁止隐式转换
///// </summary>
//void test2()
//{
//    // 隐式转换只针对一个成员的类，容易误认为是赋值
//    // 使用explicit关键字对有参构造函数修饰，禁止隐式转化
//    // 
//    //Temp t = 10; // 隐式转换 err
//    Temp t(10);         // 隐式调用
//    Temp t2 = Temp(20); // 显式调用
//
//}
//
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
