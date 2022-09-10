//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class P {
//private:
//    string name;
//    int a;
//public:
//    P()
//    {
//        cout << "无参构造" << endl;
//    }
//    P(string name, int x)
//    {
//        cout << "有参构造" << endl;
//        this->name = name;
//        a = x;
//    }
//    void showNum()
//    {
//        cout << this->a << endl;
//        cout << this->name << endl;
//    }
//    ~P()
//    {
//        cout << "析构" << endl;
//    }
//};
///// <summary>
///// new和delete 以及区别 malloc
///// </summary>
//void test1()
//{
//    // malloc出来的空间需要初始化
//    // 返回值是void*的指针，需要强转
//    // 
//    // malloc不会调用构造函数！！！
//    // free不会调用析构函数！！！
//    // 这是最主要的原因！！！
//    // 所以不能完成类的初始化
//    // 
//
//    // 不能构造，不能析构，无法初始化
//    P* p = (P*)malloc(sizeof(P));
//    free(p);
//}
//
///// <summary>
///// new申请基本数据类型以及数组
///// </summary>
//void test2()
//{
//    int* p = NULL;
//    // p = (int*)malloc(sizeof(int));
//    
//    p = new int(10); // 申请普通类型
//    cout << *p << endl;
//    
//    int* arr1 = new int[10]; //申请数组
//    int* arr2 = new int[100](); // 申请数组并初始化为0
//    int* arr3 = new int[10] {1, 2, 3}; // 申请数组并初始化为1 2 3 0 0 0 0 0 0 0 0 0
//    int* arr4 = new int[10] {0}; // 只初始化了一个，其余被初始化了0
//
//    for (int i = 0; i < 10; i++) {
//        cout << arr2[i] << " ";
//    }
//
//    // 在msvc下可以通过编译，linux下的g++编译报错
//    // char* ch = new char[32] {"hehe"}; // 在g++编译器下是错的
//    char* ch = new char[32] {'h', 'e', 'h', 'e'};
//    cout << ch << endl;
//
//    delete p;
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//    delete[] arr4;
//    delete[] ch;
//    
//}
//
///// <summary>
///// new给类分配空间
///// </summary>
//void test3()
//{
//    P* p = new P("a123", 10);
//    delete p;
//    auto a = 10;
//    auto p2 = new P("a123", 100);
//    p2->showNum();
//    delete p2;
//}
//
///// <summary>
///// new一个对象数组
///// </summary>
//void test4()
//{
//    // new 和 delete是一对，malloc和free是一对
//    // 二者不可以混搭
//    // 有参构造第1，3，5个    
//    // 2，4是无参构造
//    P arr[5]{            // 栈区开辟的5个空间
//        {"a123", 123},   // 有参构造
//        P() ,            // 无参构造
//        {"aaabbb", 345}, // 有参构造
//        {},              // 无参构造
//        P("dffg", 100) };// 有参构造
//
//    P* arr1 = new P[5]; // 堆区开辟的5个空间,无参构造
//    P* arr2 = new P[5]{P("a123", 10)}; // 堆区开辟的5个空间,指定调用有参构造
//    arr2[0].showNum();
//
//    P* p = new P("a123", 123);
//    void* p1 = p;
//
//    // 不会调用析构函数
//    // 因为传入的是void* 类型的指针
//    // 所以delete会把p1指向的空间当作一个普通类型，单纯的释放空间
//    // 不会调用本来的析构函数
//    delete p1;  
//
//    // 释放数组类型一定要加上 [] 表明是一个数组类型 
//    delete[] arr1;
//    delete[] arr2;
//}
//
//int main() 
//{
//    // test1();
//    // test2();
//    // test3();
//    test4();
//    return 0;
//}
