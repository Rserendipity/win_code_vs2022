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
//    cout << d.data << endl; // ok���������Data����Ԫ����
//}
///// <summary>
///// ��Ԫ����
///// </summary>
//void test1()
//{
//    // ��ͨ�������ܷ������ڵĳ�Ա
//    // ������Ԫ�����Ժ���Է������ڵ�˽������
//    // ��Ԫ�ƻ�����ķ�װ�ԣ�����ֱ�ӷ���˽������
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
//    Room():bedRoom("����"), classRoom("����") {}
//private:
//    string bedRoom;
//};
//void Friend::coutData(const Room& r)
//{
//    cout << r.classRoom << endl;
//    cout << r.bedRoom << endl;
//}
///// <summary>
///// ���Ա������Ϊ��һ�������Ԫ
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
///// ��������Ϊ��һ�������Ԫ
///// </summary>
//void test3()
//{
//    // һ��������г�Ա����������һ�������������
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
