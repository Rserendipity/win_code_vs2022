//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data():data(0),id("")
//    {
//        cout << "无参构造" << endl;
//        numCount++;
//    }
//    Data(int data, const string s):data(data),id(s)
//    {
//        cout << "有参构造" << endl;
//        numCount++;
//    }
//    Data(const Data& d):data(d.data),id(d.id)
//    {
//        cout << "拷贝构造" << endl;
//        numCount++;
//    } 
//    static int getNum()
//    {
//        return numCount;
//    }
//    ~Data()
//    {
//        cout << "析构" << endl;
//        numCount--;
//    }
//private:
//    int data;
//    string id;
//    static int numCount;
//};
//int Data::numCount = 0;
///// <summary>
///// 统计实例化对象的个数
///// </summary>
//void test1()
//{
//    Data d1;
//    Data d2(10, "cjj");
//    cout << Data::getNum() << endl;
//    Data d3(d2);
//    cout << Data::getNum() << endl;
//    d3.~Data();
//    d2.~Data();
//    cout << Data::getNum() << endl;
//
//}
//
//class Print {
//public:
//    // 外界获取唯一的单例指针
//    static Print* getSinglePrint()
//    {
//        return p;
//    }
//    // 功能函数
//    void printData(const string& s)
//    {
//        cout << s << endl;
//        this->count += 1;
//    }
//    void PrintCount()
//    {
//        cout << count << endl;
//    }
//private:
//    Print():count(0) {}
//    Print(const Print&) {}
//
//    int count;
//    static Print* p; // 定义唯一的实例指针，指向唯一的那个实例
//};
//Print* Print::p = new Print; // 申请了唯一的一个实例
///// <summary>
///// 单例模式
///// </summary>
//void test2()
//{
//    // 通过静态类函数，获取唯一的静态实例地址
//    Print* p = Print::getSinglePrint();
//    p->printData("asdasdasd");
//    p->printData("asdasdasd");
//    p->PrintCount();
//    
//    Print* p2 = Print::getSinglePrint();
//    p2->printData("123123");
//    p2->PrintCount();
//}
//
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
