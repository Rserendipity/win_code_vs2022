//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
///// <summary>
///// ��������� << ����
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
//        cout << "�޲ι���" << endl;
//    }
//    Person(string name, int grade) : name(name), grade(grade) 
//    {
//        cout << "�вι���" << endl;
//    }
//    Person(const Person& p)
//    {
//        this->name = p.name;
//        this->grade = p.grade;
//        cout << "��������" << endl;
//    }
//    ~Person() 
//    {
//        cout << "����" << endl;
//    }
//};
//
///// <summary>
///// ����� << ���� 
///// </summary>
//void test1() 
//{
//    Person p1("cjj", 10);
//    Person p2("wangwu", 20);
//    // cout << p1 << endl; // errû�ж�Ӧ�Ĳ��������أ��޷����
//    cout << p1 << p2 << endl;
//}
//
///// <summary>
///// ����������������
///// </summary>
///// <param name="out"> ��������� </param>
///// <param name="p1"> Person������ã������������p��ȫ������ </param>
///// <returns> ����ostream�õ����ã����Խ��е���  </returns>
//ostream& operator<<(ostream& out, Person& p1) 
//{
//    out << p1.name << "," << p1.grade << endl;
//    return out;
//}
//
///// <summary>
///// ȫ�ֺ������ؼӷ������
///// </summary>
///// <param name="p1"> ��ӵ���������֮һ </param>
///// <param name="p2"> ��һ����ӵĶ��� </param>
///// <returns> ������ʱ�Ķ��󣬽���ʱ������ⲿ����Ŀ������� </returns>
////Person operator+(Person& p1, Person& p2)
////{
////    Person temp(p1.name + " " + p2.name, p1.grade + p2.grade);
////    return temp;
////}
//
///// <summary>
///// ȫ�ֺ������ؼӷ������
///// </summary>
//void test2()
//{
//    Person p1("cjj", 100);
//    Person p2("wang", 200);
//
//    // ���ص�����ʱ������p3����ÿ�������
//    // ���һ��ȵ���p3�Ŀ��������Ժ����������ؼӷ������ʱ����
//    Person p3 = p1 + p2; 
//    cout << p3 << endl;
//}
//
///// <summary>
///// ��Ա�����������������
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
