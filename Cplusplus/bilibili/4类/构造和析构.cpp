//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cassert>
//
//using namespace std;
//class Data {
//public:
//    int num;
//    
//    // 无参构造
//    Data()
//    {
//        num = 0;
//        cout << "无参构造 num的值是"<< num << endl;
//    }
//    // 有参构造
//    Data(int n)
//    {
//        num = n;
//        cout << "有参构造 num的值是" << num << endl;
//    }
//    // 拷贝构造
//    Data(const Data& d)
//    {
//        // 不对类成员进行拷贝时，类成员是随机值
//        // 所以要自己写好对象的拷贝
//        // 
//
//        // 手动写了拷贝构造并赋值
//        num = d.num;
//        cout << "拷贝构造函数的调用"  << endl;
//    }
//    // 析构函数 没有返回值，没有参数，不能重载
//    ~Data()
//    {
//        cout << "析构调用 num的值是" << num << endl;
//    }
//};
//
//void test1()
//{
//    // 局部变量
//    // 没有传入参数，所以会调用无参构造
//    // 函数结束时局部对象被销毁
//    // 自动调用析构函数
//    // 在同一个作用域下，析构函数的调用是栈的关系
//    // 即先被构造的，后被析构
//    // 
//    Data d1; // 无参构造 或者 默认构造   隐式的调用
//    Data d2 = Data(); // 无参构造    显式调用无参构造
//    
//    Data d3(10); // 有参构造  隐式调用
//    Data d4 = Data(20); // 有参构造  显式调用
//
//    // 隐式转换，仅针对一个成员的类
//    Data d5 = 30; //会转换成  Data d5(30);
//
//    // 匿名对象（当前语句结束，匿名对象立即释放）
//    cout << "-------匿名构造------" << endl;
//    Data(40); // 用于拷贝构造
//    cout << "-------匿名析构------" << endl;
//
//}
//
//void test2()
//{
//    // 不写拷贝构造函数系统会自己提供一个
//    // 但是自动的构造是直接赋值操作
//    // 如果用户写了自己的拷贝构造，那就会调用自己实现的拷贝构造
//    // 
//    // 用旧的对象初始化一个新的对象，就会调用拷贝构造
//    // 只有在定义（初始化）的时候才是新的对象，否则都是就对象
//    // 
//    Data d1(10); // 隐式有参构造
//    Data d2(d1); // 隐式拷贝构造
//    Data d3 = Data(d1); // 显式拷贝构造
//    Data d4 = d1; // 隐式转换的拷贝构造，会转换成上面的形式
//}
//
//void test3()
//{
//    Data d1(10);// 调用了隐式的有参构造
//    Data d2;   // 已经调用了隐式无参构造
//    d2 = d1;   // 单纯的赋值操作（没有运算符重载时）
//
//
//}
//
//void test4()
//{
//    // 无参构造陷阱
//    // 无参构造只有两种：显式和隐式
//    Data d1;          // 隐式
//    Data d2 = Data(); // 显式
//
//    // 声明了一个没有参数，返回值是Data的函数名
//    Data d3();   // 这个是函数的声明！！！
//}
//
//void test5()
//{
//    // 系统会提供三个默认的函数
//    // 默认构造(空)，默认析构(空)
//    // 默认拷贝构造(单纯的赋值)
//    // 
//    // 如果定义了有参构造，系统不会提供默认构造，调用默认构造会报错
//    // 如果提供了拷贝构造，系统不会提供默认构造，不写默认构造会报错
//    // 
//    // 即关系如下：
//    // 默认构造  --->  有参构造  --->  拷贝构造
//    // 写了有参就不会提供默认
//    // 写了拷贝就不会提供默认和有参
//    // 
//}
//
//class Person {
//public:
//    // 默认构造
//    Person()
//    {
//        this->name = NULL;
//        this->num = 0;
//    }
//    // 有参构造
//    Person(const char* name, int num)
//    {
//        this->name = (char*)calloc(1, strlen(name) + 1);
//        assert(this->name);
//        strcpy(this->name, name);
//        this->num = num;
//    }
//    // 拷贝构造
//    Person(const Person& p)
//    {
//        cout << "拷贝构造" << endl;
//        this->name = (char*)calloc(1, strlen(p.name) + 1);
//        assert(this->name);
//        strcpy(this->name, p.name);
//    }
//    // 析构
//    ~Person()
//    {
//        assert(this->name);
//        free(this->name);
//        cout << "析构" << endl;
//    }
//private:
//    // 姓名
//    char* name;
//    // 学号
//    int num;
//};
///// <summary>
///// 深浅拷贝
///// </summary>
//void test6()
//{
//    Person licy("lucy", 2022);
//    // 对licy进行拷贝构造的时候，c的name得到的是licy的name
//    // 在析构释放内存的时候，c会把licy的name释放掉
//    // 然后licy再次对name释放，双重释放，报错
//    // 
//    Person c = licy;
//}
//
//
//class Init {
//public:
//    Init(int a, int b, int c) :a(a), b(b), c(c)
//    {
//
//    }
//    ~Init()
//    {
//
//    }
//    void showData()
//    {
//        cout << a << " " << b << " " << c << endl;
//    }
//private:
//    int a;
//    int b;
//    int c;
//};
///// <summary>
///// 初始化列表
///// </summary>
//void test7()
//{
//    Init i(10, 20, 30);
//    i.showData();
//
//}
//
//// 
//// 构造函数：执行类的初始化
//// 构造函数名和类名相同，没返回值，可以有参数，可以重载
//// 
//// 析构函数：执行类的销毁
//// 析构函数名是~类名，没有返回值，没有参数，不可以重载
//// 
//// 构造函数的分类：参数方面   ----  无参/有参
////                类型分类   ----  普通构造/拷贝构造
//// 
//int main() 
//{
//    //cout << "-------1------" << endl;
//    //test1();
//    //cout << "-------2------" << endl;
//    
//    //cout << "-------1------" << endl;
//    //test2();
//    //cout << "-------2------" << endl;
//    
//    //cout << "-------1------" << endl;
//    //test3();
//    //cout << "-------2------" << endl;
//
//    //cout << "-------1------" << endl;
//    //test4();
//    //cout << "-------2------" << endl;
//
//    //cout << "-------1------" << endl;
//    //test5();
//    //cout << "-------2------" << endl;
//
//    //cout << "-------1------" << endl;
//    //test6();
//    //cout << "-------2------" << endl;
//
//    cout << "-------1------" << endl;
//    test7();
//    cout << "-------2------" << endl;
//
//    return 0;
//}
