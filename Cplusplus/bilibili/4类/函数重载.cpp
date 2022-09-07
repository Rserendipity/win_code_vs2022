//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//// 同一个函数在不同的使用场景下有不同的含义
//// 类似于汉语的多音字
//// 函数重载是c++多态的体现
//// 
//// 函数重载的条件：同一个作用域下
//// 参数个数不同 or
//// 参数类型不同 or
//// 参数顺序不同
//// 满足一个就可以重载
//// 注意：函数的返回值不能作为函数重载的区分
//// 原因：编译器在编译期间是用参数类型来修饰不同的函数名
//// 比如func(int)       -->  "func@int"  (这只是一种假设)
////     func(int, int)  -->  "func@intint"
//// 
//// 注意：函数的重载和默认参数同时在一起，容易产生二义性
//// 
//void myFunc(int a)
//{
//    cout << "int 函数" << endl;
//}
//void myFunc(int a, int b) // 个数不同
//{
//    cout << "int,int 函数" << endl;
//}
//void myFunc(double a, int b) // 参数类型不同
//{
//    cout << "double,int函数" << endl;
//}
//void myFunc(int a, double b) // 参数顺序不同
//{
//    cout << "int,double函数" << endl;
//}
//void test1()
//{
//    myFunc(10);
//    myFunc(10, 20);
//    myFunc(10, 20.2);
//    myFunc(10.5, 10);
//}
//
//void myFunc2(int a)
//{
//
//}
//void myFunc2(int a, int b = 20) // warning：容易产生二义性
//{
//    
//}
//void test2()
//{
//    // myFunc2(10); //err
//    // 产生二义性，
//    // 原因：传一个参数的时候，两个函数都可以匹配成功
//    // 第二个函数有默认值了，所以也可以只传一个参数
//}
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
