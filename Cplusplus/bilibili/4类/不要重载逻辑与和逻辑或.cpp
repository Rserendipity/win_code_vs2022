//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data(int m, int n) :m(m), n(n)
//    {
//        cout << "�в�" << endl;
//    }
//
//    bool operator&&(const Data& d)
//    {
//        return this->m&& d.m&& this->n&& d.n;
//    }
//
//    Data& operator++()
//    {
//        this->m++;
//        this->n++;
//        return *this;
//    }
//
//private:
//    int m;
//    int n;
//};
//
//void test1()
//{
//    Data d1(0,0);
//    Data d2 = d1;
//    if (d1 && ++d2) // ϵͳ�ṩ�� && ���߼���ʱ����һ������Ϊfalseʱ�ͻ��Ϻ�������������·����
//                    // ��������ز���ʵ�֣���Ϊ��������ر���ʱ�����ĵ��ã����ȼ���ȫ���Ĳ���ֵ�ٴ���
//    {
//        cout << "true" << endl;
//    }
//    else
//    {
//        cout << "false" << endl;
//    }
//
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
