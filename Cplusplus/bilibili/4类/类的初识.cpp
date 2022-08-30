//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//// C -- 结构体
////struct People {
////    char name[30];
////    int age;
////};
////struct Dog {
////    char name[30];
////    int age;
////};
////void PeopleEat(struct People* p)
////{
////    cout << p->name << "正在吃饭" << endl;
////}
////void DogEat(struct People* p)
////{
////    cout << p->name << "正在吃狗粮" << endl;
////}
////void test1()
////{
////    struct People p1 = { "老王",30 };
////    struct Dog d1 = { "旺财",10 };
////    PeopleEat(&p1);
////    // 数据和方法分开了，所以有可能操作错误的数据
////    // DogEat((struct People*)&p1); // 调用了错误的方法 
////
////}
//
//// 类的封装性：
//// 把变量（属性）和方法（函数）封装到一起，并添加权限，进行控制
//// 在类内，没有权限之分，类内可以访问全部的数据和方法
//// 在类外，只能用共有部分的 属性/方法
//// 访问属性    属性     对象内部    对象外
//// public     公有     可以访问    可访问
//// protected  保护     可以访问    不可访问
//// private    保护     可以访问    不可访问
//// 
//// 类是一种类型，在没有实例化一个具体的对象的时候，系统不会为其分配空间
//// 类的默认权限是私有的，结构体默认是公有的
//// 
//class People { // 在大括号内都是类的内部，
//public:
//    void dese()
//    {
//        m_money = 100;
//        cout << "老子有" << m_money <<  "钱" << endl;
//    }
//
//protected:
//    int m_money;
//private:
//    int age;
//};
//void test2()
//{
//    // 用类来实例化一个对象
//    People p1;
//    p1.dese(); // 公有部分可以直接访问
//    // p1.m_money = 200; // err 类外不可以访问保护数据
//    // p1.age = 20; // err 类外不可以访问私有数据
//    // 用户不可以直接操作类的 保护/私有 数据
//    // 但是可以用公用的方法间接的修改数据
//    // 
//}
//// 类既可以有变量也可以有函数
//// 自身的属性  ---->   数据
//// 自身的行为  ---->   方法（函数）
//// 类既可以对数据封装，也可以对函数封装
//// 类外只能调用类共有的 数据/方法 所以对数据和方法进行了封装
//// 所以每一个对象只能调用自身对应的 数据/方法
//// 
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
