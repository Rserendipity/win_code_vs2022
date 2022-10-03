//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//class Animal {
//public:
//    Animal()
//    {
//        cout << "Animal构造" << endl;
//    }
//    // ~Animal()
//    virtual ~Animal() // 父类的析构设置成析构以后就可以直接通过父类的指针调用子类的析构
//    {
//        cout << "Animal析构" << endl;
//    }
//};
//
//class Cat:public Animal {
//public:
//    Cat()
//    {
//        cout << "Cat构造" << endl;
//    }
//    ~Cat()
//    {
//        cout << "Cat析构" << endl;
//    }
//};
//
//int main() 
//{
//    Animal* p = new Cat;
//    delete p; //目前只能释放父类的部分，原因：父类指针只能访问父类的部分
//
//    Animal& p1 = *new Cat;
//    delete& p1;
//
//    return 0;
//}
