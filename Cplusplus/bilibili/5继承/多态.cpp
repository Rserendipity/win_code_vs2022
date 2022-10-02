//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//    virtual void Sleep() // 虚函数
//    // void Sleep() // 普通成员函数
//    {
//        cout << "Animal在睡觉" << endl;
//    }
//};
//
//class Dog :public Animal {
//public:
//
//    void Sleep()
//    {
//        cout << "Dog在睡觉" << endl;
//    }
//};
//
//void test1()
//{
//    // 多态：
//    // 静态多态（静态联编，函数地址在编译期间确定）：函数重载，运算符重载
//    // 动态多态（动态联编，函数地址在运行时确定）  ：继承中的虚函数（重写）
//    // 
//    
//    // 复习部分：
//    //Dog d;
//    //d.Sleep(); // dog
//    //d.Animal::Sleep(); // animal
//
//    // 向上兼容性：
//    // 用Animal指针保存Dog的地址，访问的结果只会是dog继承的Animal部分
//    //Animal* p = new Dog;
//    //p->Sleep(); // animal
//
//    // 虚函数：
//    // 基类的虚函数，在子类中重写后，用基类指针就可以操作子类的成员
//    Animal* p = new Dog;
//    p->Sleep(); // dog
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
