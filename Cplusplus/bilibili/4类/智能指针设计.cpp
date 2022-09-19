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
//        cout << "Person无参" << endl << endl;
//    }
//    Person(string name, int num) : name(name), num(num) 
//    {
//        cout << "Person有参" << endl<<endl;
//    }
//    ~Person() 
//    {
//        cout << "Person析构" << endl;
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
///// 给 Person类 进行自动释放
///// </summary>
//class Auto_Ptr {
//private:
//    Person* p;
//public:
//    Auto_Ptr(Person* p) :p(p) 
//    {
//        cout << "Auto_Ptr有参" << endl << endl;
//    }
//    Person& GetPtr()
//    {
//        return *p;
//    }
//    ~Auto_Ptr()
//    {
//        cout << "Auto_Ptr析构" << endl << endl;
//        if (p != NULL)
//        {
//            delete p;
//            p = NULL;
//        }
//    }
//
//    // 重载->运算符，以实现对象当成指针使用
//    Person* operator->()
//    {
//        return this->p;
//    }
//    // 重载*运算符，和上面相似
//    Person& operator*()
//    {
//        return *(this->p);
//    }
//};
//
///// <summary>
///// 设计智能指针
///// </summary>
//void test1()
//{
//    //// 临时变量，在程序离开这个函数的时候就会自动调用析构函数
//    //Person p("chang", 98);
//    //p.ShowInfo();
//    
//    // 堆区开辟的变量，不会自动释放，没有析构
//    Person* p = new Person("lili", 100);
//    p->ShowInfo();
//    
//    // 手动调用析构 或者 delete帮你析构
//    // p->~Person();
//    // delete p;
//
//    // ptr是一个临时变量，会在销毁的时候自动释放p的空间
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
