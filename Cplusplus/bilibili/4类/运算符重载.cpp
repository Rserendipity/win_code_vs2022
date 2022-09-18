//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
///// <summary>
///// 测试运算符 << 重载
///// </summary>
//class Person {
//    friend ostream& operator<<(ostream& out, Person& p1);
//    // friend Person operator+(Person& p1, Person& p2);
//private:
//    string name;
//    int grade;
//public:
//    Person operator+(Person& p)
//    {
//        Person temp(this->name + " " + p.name, this->grade + p.grade);
//        return temp;
//    }
//    Person() : name(""), grade(0) 
//    {
//        cout << "无参构造" << endl;
//    }
//    Person(string name, int grade) : name(name), grade(grade) 
//    {
//        cout << "有参构造" << endl;
//    }
//    Person(const Person& p)
//    {
//        this->name = p.name;
//        this->grade = p.grade;
//        cout << "拷贝构造" << endl;
//    }
//    ~Person() 
//    {
//        cout << "析构" << endl;
//    }
//};
//
///// <summary>
///// 运算符 << 重载 
///// </summary>
//void test1() 
//{
//    Person p1("cjj", 10);
//    Person p2("wangwu", 20);
//    // cout << p1 << endl; // err没有对应的操作符重载，无法输出
//    cout << p1 << p2 << endl;
//}
//
///// <summary>
///// 重载左尖括号运算符
///// </summary>
///// <param name="out"> 输出流引用 </param>
///// <param name="p1"> Person类的引用，进行重载输出p的全部数据 </param>
///// <returns> 返回ostream得到引用，可以进行迭代  </returns>
//ostream& operator<<(ostream& out, Person& p1) 
//{
//    out << p1.name << "," << p1.grade << endl;
//    return out;
//}
//
///// <summary>
///// 全局函数重载加法运算符
///// </summary>
///// <param name="p1"> 相加的两个对象之一 </param>
///// <param name="p2"> 另一个相加的对象 </param>
///// <returns> 返回临时的对象，接收时会调用外部对象的拷贝构造 </returns>
////Person operator+(Person& p1, Person& p2)
////{
////    Person temp(p1.name + " " + p2.name, p1.grade + p2.grade);
////    return temp;
////}
//
///// <summary>
///// 全局函数重载加法运算符
///// </summary>
//void test2()
//{
//    Person p1("cjj", 100);
//    Person p2("wang", 200);
//
//    // 返回的是临时变量，p3会调用拷贝构造
//    // 并且会先调用p3的拷贝构造以后，再销毁重载加法里的临时变量
//    Person p3 = p1 + p2; 
//    cout << p3 << endl;
//}
//
///// <summary>
///// 成员函数进行运算符重载
///// </summary>
//void test3()
//{
//    Person p1("cjj", 100);
//    Person p2("wang", 200);
//    Person p3 = p1 + p2;
//    cout << p3 << endl;
//}
//
//
//int main() 
//{
//    // test1();
//    // test2();
//    test3();
//    return 0;
//}
