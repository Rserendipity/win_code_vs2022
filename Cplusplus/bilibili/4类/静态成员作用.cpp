//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data():data(0),id("")
//    {
//        cout << "�޲ι���" << endl;
//        numCount++;
//    }
//    Data(int data, const string s):data(data),id(s)
//    {
//        cout << "�вι���" << endl;
//        numCount++;
//    }
//    Data(const Data& d):data(d.data),id(d.id)
//    {
//        cout << "��������" << endl;
//        numCount++;
//    } 
//    static int getNum()
//    {
//        return numCount;
//    }
//    ~Data()
//    {
//        cout << "����" << endl;
//        numCount--;
//    }
//private:
//    int data;
//    string id;
//    static int numCount;
//};
//int Data::numCount = 0;
///// <summary>
///// ͳ��ʵ��������ĸ���
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
//    // ����ȡΨһ�ĵ���ָ��
//    static Print* getSinglePrint()
//    {
//        return p;
//    }
//    // ���ܺ���
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
//    static Print* p; // ����Ψһ��ʵ��ָ�룬ָ��Ψһ���Ǹ�ʵ��
//};
//Print* Print::p = new Print; // ������Ψһ��һ��ʵ��
///// <summary>
///// ����ģʽ
///// </summary>
//void test2()
//{
//    // ͨ����̬�ຯ������ȡΨһ�ľ�̬ʵ����ַ
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
