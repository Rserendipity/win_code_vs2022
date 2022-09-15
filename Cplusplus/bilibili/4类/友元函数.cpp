//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Data {
//    friend void coutData(const Data&);
//private:
//    int data;
//public:
//    int a;
//    Data() :a(10), data(20) {}
//};
//void coutData(const Data& d)
//{
//    cout << d.a << endl;
//    cout << d.data << endl; // ok这个函数是Data的友元函数
//}
///// <summary>
///// 友元函数
///// </summary>
//void test1()
//{
//    // 普通函数不能访问类内的成员
//    // 当用友元修饰以后可以访问类内的私有属性
//    // 友元破坏了类的封装性，可以直接访问私有属性
//    // 
//    Data d1;
//    coutData(d1);
//}
//
//class Room;
//class Friend {
//private:
//public:
//    void coutData(const Room& r);
//};
//class Room {
//    friend void Friend::coutData(const Room& r);
//public:
//    string classRoom;
//    Room():bedRoom("卧室"), classRoom("教室") {}
//private:
//    string bedRoom;
//};
//void Friend::coutData(const Room& r)
//{
//    cout << r.classRoom << endl;
//    cout << r.bedRoom << endl;
//}
///// <summary>
///// 类成员函数作为另一个类的友元
///// </summary>
//void test2()
//{
//    Room r;
//    Friend f;
//    f.coutData(r);
//}
//
//class Room2;
//class Friend2 {
//public:
//    void countData(const Room2& r);
//    void setData(Room2& r);
//};
//class Room2 {
//    friend Friend2;
//private:
//    int a;
//    int b;
//    int c;
//public:
//    Room2():a(10),b(20),c(30){}
//};
//void Friend2::setData(Room2& r)
//{
//    r.a = 100;
//    r.b = 200;
//    r.c = 300;
//}
//void Friend2::countData(const Room2& r)
//{
//    cout << r.a << endl;
//    cout << r.b << endl;
//    cout << r.c << endl;
//}
///// <summary>
///// 类整体作为另一个类的友元
///// </summary>
//void test3()
//{
//    // 一个类的所有成员函数访问另一个类的所有数据
//    // 
//    Room2 r;
//    Friend2 f;
//    f.countData(r);
//    f.setData(r);
//    f.countData(r);
//}
//
//int main() 
//{
//    // test1();
//    // test2();
//    test3();
//    return 0;
//}
