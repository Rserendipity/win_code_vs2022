//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//     friend ostream& operator<<(ostream& out, Data& d);
//public:
//    Data() :a(0), b(0) 
//    {
//        cout << "无参" << endl;
//    }
//    Data(int a, int b):a(a),b(b)
//    {
//        cout << "有参" << endl;
//    }
//    Data(const Data& d)
//    {
//        this->a = d.a;
//        this->b = d.b;
//        cout << "拷贝构造" << endl;
//    }
//    ~Data()
//    {
//        cout << "析构" << endl;
//    }
//    
//    //ostream& operator<<(ostream& out)
//    //{
//    //    out << this->a;
//    //    return out;
//    //}
//
//    // 重载前置自增
//    // 返回自身引用，可以进行迭代
//    Data& operator++()
//    {
//        this->a++;
//        this->b++;
//        return *this;
//    }
//
//    // 重载后置自减
//    // 后置自增返回的结果，不是引用，是固定的值，不能进行迭代
//    Data operator++(int)
//    {
//        // 先备份以前的值，把当前的值加加，返回备份的值
//        Data temp = *this;
//        this->a++;
//        this->b++;
//        return temp;
//    }
//
//    Data& operator--()
//    {
//        this->a--;
//        this->b--;
//        return *this;
//    }
//
//    // 重载后置自减
//    // 后置自增返回的结果，不是引用，是固定的值，不能进行迭代
//    Data operator--(int)
//    {
//        // 先备份以前的值，把当前的值减一，返回备份的值
//        Data temp = *this;
//        this->a--;
//        this->b--;
//        return temp;
//    }
//
//private:
//    int a;
//    int b;
//};
//// 重载输出
//ostream& operator<<(ostream& out, Data& d)
//{
//    out << "a = " << d.a << endl;
//    out << "b = " << d.b << endl;
//    return out;
//}
//
///// <summary>
///// 重载++或--
///// </summary>
//void test1()
//{
//    // 自增和自减，都有两种，一种是前置，一种是后置
//    // 为了解决这样的问题，可以使用占位参数进行区分
//    // operator++(a)     ---->  ++a;
//    // operator++(a,int) ---->  a++; 
//    // 
//    Data d(10, 20);
//    //cout << "原来的值" << endl;
//    //cout << d << endl;
//
//    ////cout << "后自增的值" << endl;
//    ////cout << d++ << endl; // err前置++结果是引用，后置加加结果是值
//    //
//    //cout << "自增后的值" << endl;
//    //cout << d << endl;
//
//    //cout << "前自增的值" << endl;
//    //cout << ++d << endl;
//    //
//    //cout << "自增后的值" << endl;
//    //cout << d << endl;
//    
//    cout << d << endl;
//    d++; // 后置加加的结果是值，不是引用，所以必须先接收这个值
//    cout << d << endl;
//    d--;
//    cout << d << endl;
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
