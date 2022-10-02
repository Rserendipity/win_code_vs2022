//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//    int data;
//};
//
/////// <summary>
/////// 普通菱形继承
/////// </summary>
////class Yang:public Animal {
////public:
////
////};
////
////class Tuo :public Animal {
////public:
////
////};
////
////class YangTuo :public Yang, public Tuo {
////public:
////
////};
//
///// <summary>
///// 虚继承
///// </summary>
//class Yang:virtual public Animal {
//public:
//
//};
//
//class Tuo :virtual public Animal {
//public:
//
//};
//
//class YangTuo :public Yang, public Tuo {
//public:
//
//};
//
///// <summary>
///// 菱形继承
/////         Animal
/////         /    \
/////       Yang   Tuo
/////         \   /
/////        YangTuo
///// </summary>
//void test1()
//{
//    //YangTuo y;
//    //// y.data = 100; // err 多个继承过来的data
//    //y.Yang::data = 100; // 有二义性的时候加上作用域，即可解决问题
//}
//
///// <summary>
///// 虚继承，解决菱形继承的二义性以及重复继承问题
///// </summary>
//void test2()
//{
//    YangTuo y;
//    // 虚继承体系中只会有一份data
//    // 所有的派生类使用虚基类指针和虚基类表共用同一份数据
//    // 解决了二义性，也解决了内存的占用问题
//    y.data = 100; 
//    cout << y.data << endl;
//}
//
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
