//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
///// <summary>
///// 
///// </summary>
//class Person {
//public:
//    Person() :name(""), num(0) 
//    {
//        cout << "Person�޲�" << endl << endl;
//    }
//    Person(string name, int num) : name(name), num(num) 
//    {
//        cout << "Person�в�" << endl<<endl;
//    }
//    ~Person() 
//    {
//        cout << "Person����" << endl;
//    }
//    void ShowInfo()
//    {
//        cout << "name:" << this->name << endl;
//        cout << "num:" << this->num << endl << endl;
//    }
//private:
//    string name;
//    int num;
//};
//
///// <summary>
///// �� Person�� �����Զ��ͷ�
///// </summary>
//class Auto_Ptr {
//private:
//    Person* p;
//public:
//    Auto_Ptr(Person* p) :p(p) 
//    {
//        cout << "Auto_Ptr�в�" << endl << endl;
//    }
//    Person& GetPtr()
//    {
//        return *p;
//    }
//    ~Auto_Ptr()
//    {
//        cout << "Auto_Ptr����" << endl << endl;
//        if (p != NULL)
//        {
//            delete p;
//            p = NULL;
//        }
//    }
//
//    // ����->���������ʵ�ֶ��󵱳�ָ��ʹ��
//    Person* operator->()
//    {
//        return this->p;
//    }
//    // ����*�����������������
//    Person& operator*()
//    {
//        return *(this->p);
//    }
//};
//
///// <summary>
///// �������ָ��
///// </summary>
//void test1()
//{
//    //// ��ʱ�������ڳ����뿪���������ʱ��ͻ��Զ�������������
//    //Person p("chang", 98);
//    //p.ShowInfo();
//    
//    // �������ٵı����������Զ��ͷţ�û������
//    Person* p = new Person("lili", 100);
//    p->ShowInfo();
//    
//    // �ֶ��������� ���� delete��������
//    // p->~Person();
//    // delete p;
//
//    // ptr��һ����ʱ�������������ٵ�ʱ���Զ��ͷ�p�Ŀռ�
//    Auto_Ptr ptr(p);
//    // ptr.operator->()    ->   ShowInfo();
//    ptr.operator->()->ShowInfo();
//    ptr->ShowInfo();
//    (*ptr).ShowInfo();
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
