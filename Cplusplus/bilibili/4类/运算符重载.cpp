#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& out, Person& p1);
private:
    string name;
    int grade;
public:
    Person() : name(""), grade(0) {}
    Person(string name, int grade) : name(name), grade(grade) {}
    ~Person() {}
};

// 运算符重载
void test1() 
{
    Person p1("cjj", 10);
    Person p2("wangwu", 20);
    // cout << p1 << endl; // err没有对应的操作符重载，无法输出
    cout << p1 << p2 << endl;
}

/// <summary>
/// 重载<<运算符
/// </summary>
/// <param name="out"> 输出流引用，重载的关键 </param>
/// <param name="p1"> Person的引用，进行重载输出p的数据 </param>
/// <returns> 返回ostream得到引用，可以接着进行输入  </returns>
ostream& operator<<(ostream& out, Person& p1) 
{
    out << p1.name << "," << p1.grade << endl;
    return out;
}

int main() 
{
    test1();
    return 0;
}
