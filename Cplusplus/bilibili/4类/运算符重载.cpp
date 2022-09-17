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

// ���������
void test1() 
{
    Person p1("cjj", 10);
    Person p2("wangwu", 20);
    // cout << p1 << endl; // errû�ж�Ӧ�Ĳ��������أ��޷����
    cout << p1 << p2 << endl;
}

/// <summary>
/// ����<<�����
/// </summary>
/// <param name="out"> ��������ã����صĹؼ� </param>
/// <param name="p1"> Person�����ã������������p������ </param>
/// <returns> ����ostream�õ����ã����Խ��Ž�������  </returns>
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
