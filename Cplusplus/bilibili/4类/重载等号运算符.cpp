//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data():pNum(new int(0)),size(0) 
//    {
//        cout << "无参" << endl;
//    }
//    Data(int num, int size):pNum(new int(num)),size(size)
//    {
//        cout << "有参" << endl;
//    }
//    Data(const Data& d)
//    {
//        cout << "拷贝" << endl;
//        this->pNum = new int(*d.pNum);
//        this->size = d.size;
//    }
//    ~Data()
//    {
//        if (pNum != NULL)
//        {
//            delete pNum;
//            pNum = NULL;
//        }
//        cout << "析构" << endl;
//    }
//    Data& operator=(const Data& d)
//    {
//        cout << "重载" << endl;
//        this->~Data();
//        this->pNum = new int(*d.pNum);
//        this->size = d.size;
//        return *this;
//    }
//
//    void ShowData()
//    {
//        cout << *this->pNum << " " << this->size << endl;
//    }
//
//private:
//    int* pNum;
//    int size;
//};
//
//void test1()
//{
//    Data d1(10, 20);  // 有参
//    Data d2 = d1;     // 拷贝构造，浅拷贝（没写拷贝构造），在释放时会重复释放
//    Data d3;          // 无参
//    // 必须要进行析构，d3默认是有无参构造的，会申请堆区空间，运算符重载的时候必须要释放掉，不然会内存泄漏
//    d3 = d1;          // 默认赋值，前赋值（没有重载=运算符），在释放时会重复释放
//    
//    Data d4, d5;
//    d4 = d5 = d3;     // 运算符重载返回的是自身引用，所以可以连续赋值
//
//    d4.ShowData();
//    d5.ShowData();
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
