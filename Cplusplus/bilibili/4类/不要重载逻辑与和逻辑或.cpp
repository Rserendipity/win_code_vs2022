//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data(int m, int n) :m(m), n(n)
//    {
//        cout << "有参" << endl;
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
//    if (d1 && ++d2) // 系统提供的 && 在逻辑与时，第一个参数为false时就会打断后续操作，即短路现象
//                    // 运算符重载不能实现，因为运算符重载本质时函数的调用，会先计算全部的参数值再传参
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
