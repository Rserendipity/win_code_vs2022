#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// 引用以及初始化
void fun1()
{
    // 开辟了一段连续的4个字节的空间
    // 引用就可以给这个变量取一个别名
    int a = 0;
    // 左值为引用，右值是取地址
    // 引用必须初始化
    // 引用名不可被修改
    // 引用不会开辟空间
    // b完全等价于a
    int& b = a; // 这个b就是a的引用

    int temp = 10;

    // 这里的含义是把temp赋值给b
    // 不是把b改成对temp的引用
    b = temp;

    cout << a << endl;
    cout << b << endl;

    // a和b的地址完全一致
    cout << "*a = " << &a << endl;
    cout << "*b = " << &b << endl;
}

// 数组的引用
void fun2()
{
    int arr[] = { 1, 2, 3, 4, 5 };

    // 给arr取别名
    // 必须指定数组的元素个数
    // 需要用（）来确定parr的优先级
    // []的优先级高于&
    // 否则就是一个引用数组
    int(&parr)[5] = arr;

    // 用typedef给类型取别名
    // 再用新的名字取代原类型定义引用
    typedef int Arr_t[5];
    // Arr_t类型的引用
    Arr_t& my_arr_t = arr;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << parr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << my_arr_t[i] << " ";
    }
    cout << endl;
}

// 辅助交换函数
void my_swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void my_swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void my_swap3(int& a, int& b)
{
    // 调用时就是对原变量的使用
    int temp = a;
    a = b;
    b = temp;
}
// 引用作为函数的参数
void fun3()
{
    int a = 10;
    int b = 20;
    cout << a << " " << b << endl;

    // 没有被改变
    my_swap1(a, b);
    cout << a << " " << b << endl;
    // 成功交换  --->  指针
    my_swap2(&a, &b);
    cout << a << " " << b << endl;
    // 成功交换  --->  引用
    my_swap3(a, b);
    cout << a << " " << b << endl;
}

int& myFunc1()
{
    int num = 10;
    static int num1 = 20;
    // 语法正确但是
    // 返回的是一个已经被销毁的局部变量
    // 和野指针相似
    // return num; // warning

    return num1;
}
// 引用作为函数的返回值
void fun4()
{
    // 返回值是引用的时候
    // 需要直接定义一个引用来直接初始化
    // 原因：引用必须要初始化
    int& ret = myFunc1();
    cout << ret << endl;
}

int& myFunc2()
{
    static int num = 10;
    return num;
}
// 函数作为左值时，其返回值一定要是引用
void fun5()
{
    cout << myFunc2() << endl;
    // 返回的是一个引用
    // 所以实际上这里是对num赋值
    myFunc2() = 2000;

    // 所以这里打印的是num当前的值，2000
    cout << myFunc2() << endl;
}

// 引用的本质：常量指针
void fun6()
{
    int data = 10;
    int& a = data;
    a = 100; // 相当于 data = 100;
    // 内部的定义：int*const b = &data;
    // 内部的使用：*b = 100;
    // 这里的const修饰了b，所以b不可被修改
}

// C语言，取地址
void myStr1(char** str)
{
    *str = (char*)calloc(sizeof(char) * 10, 1);
    strcpy(*str, "hello");
}
// C++，引用
void myStr2(char*& str)
{
    str = (char*)calloc(sizeof(char) * 10, 1);
    strcpy(str, "hello");
}
// 指针引用
void fun7()
{
    // 给指针变量取别名
    int a = 10;
    int b = 20;
    int* pa = &a;
    int*& ra = pa;
    // type    &  name  =   value;
    // int*    &  ra    =   &pa  ;

    // C风格，取二级地址
    char* str = NULL;
    myStr1(&str);
    cout << str << endl;
    free(str);

    // C++风格，引用，相当于函数内部使用的就是str本身
    myStr2(str);
    cout << str << endl;
    free(str);
}

typedef struct stu {
    int age;
    char name[20];
} Stu;
void printStu1(Stu s)
{
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
void printStu2(Stu& s)
{
    // s.age = 100 //普通引用可以被修改
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
void printStu3(const Stu& s)
{
    // s.age = 100; //err 常引用不允许被修改
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
// 常量引用
void fun8()
{
    Stu s = { 10, "c" };
    printStu1(s); // 值传递，开销大
    printStu2(s); // 直接引用，不会为形参开辟空间
    printStu3(s); // 常引用，在函数内不会被修改
}

// 常量值引用
void fun9()
{
    // int &num = 10; //10 是一个常量，必须用const修饰
    const int& num = 10; //正确
    cout << "num = " << num << endl;
}
int main()
{
    // fun1();
    // fun2();
    // fun3();
    // fun4();
    // fun5();
    // fun6();
    // fun7();
    // fun8();
    fun9();
    return 0;
}
