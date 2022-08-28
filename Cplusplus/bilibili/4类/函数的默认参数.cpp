#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;



// 指定a为10，b为30，当给a和b传值的时候，默认值无效
void print(int a = 10, int b = 30)
{
    cout << a + b << endl;
}
// 给c了默认参数，所以从c开始，往后的参数必须给参数
void sum(int a, int b, int c = 10, int d = 20)
{
    cout << a + b + c + d << endl;
}


// 占位参数
// 只写了类型，没有形参名称
// 函数内部不可以使用
// 占位参数可以有默认值
// 为了服务于运算符重载
// 
void func1(int a, int)
{
    
}
void func2(int a, int = 10)
{

}
// 函数声明的时候可以给默认参数，调用函数没有给这个参数传参的时候
// 会自动使用默认参数
// 从第一个默认参数开始，往后的参数必须设置默认参数
// 如果函数的声明和实现在不一样的地方实现，不能在声明和实现同时设置默认参数
// 建议在声明的地方写默认参数
// 分开写时，定义处的默认参数无效
// 所以建议 在声明 时给默认参数
// 同一份定义，在不同的地方使用的时候就可以指定不同的默认参数
// 
void test1()
{
    print();     // 使用a和b的默认值   40
    print(1,2);  // 指定了a和b的值     3
    print(100);  // 指定了a的，没有b   130

    func1(10, 10); // 正确
    // func1(10); // err必须传入参数
    func2(10); // 正确，占位参数具有默认值
    func2(10, 20); //正确，占位参数被改为20，但没有意义
}
int main() 
{
    test1();
    return 0;
}
