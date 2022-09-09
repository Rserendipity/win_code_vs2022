#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class P {
private:
    int a;
public:
    P(int x)
    {
        cout << "有参构造" << endl;
        a = x;
    }
    ~P()
    {
        cout << "析构" << endl;
    }
};
/// <summary>
/// new和delete 以及区别 malloc
/// </summary>
void test1()
{
    // malloc出来的空间需要初始化
    // 返回值是void*的指针，需要强转
    // 
    // malloc不会调用构造函数！！！
    // free不会调用析构函数！！！
    // 这是最主要的原因！！！
    // 所以不能完成类的初始化
    // 

    // 不能构造，不能析构，无法初始化
    P* p = (P*)malloc(sizeof(P));
    free(p);
}

/// <summary>
/// new申请基本数据类型以及数组
/// </summary>
void test2()
{
    int* p = NULL;
    // p = (int*)malloc(sizeof(int));
    
    p = new int(10); // 申请普通类型
    cout << *p << endl;
    
    int* arr1 = new int[10]; //申请数组
    int* arr2 = new int[100](); // 申请数组并初始化为0
    int* arr3 = new int[10] {1, 2, 3}; // 申请数组并初始化为1 2 3 0 0 0 0 0 0 0 0 0
    int* arr4 = new int[10] {0}; // 只初始化了一个，其余被初始化了0

    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }

    // 在msvc下可以通过编译，linux下的g++编译报错
    // char* ch = new char[32] {"hehe"}; // 在g++编译器下是错的
    char* ch = new char[32] {'h', 'e', 'h', 'e'};
    cout << ch << endl;

    delete p;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] ch;
    
}

int main() 
{
    // test1();
    test2();
    return 0;
}
