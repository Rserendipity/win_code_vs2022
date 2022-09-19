#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Fun {
public:
    int Add(int x, int y)
    {
        return x + y;
    }
    int operator()(int x, int y)
    {
        return x + y;
    }
    ~Fun()
    {
        cout << "析构" << endl;
    }
};

void test1()
{
    Fun f; 
    // 创建对象，调用对象的方法，完成计算
    cout << f.Add(10, 20) << endl;

    // 直接用（）运算符的重载完成计算
    cout << f(100, 200) << endl;

    // Fun()   类名加上括号，创建了一个匿名对象,然后用这个匿名对象调用了运算符重载完成运算，然后自动销毁
    cout << Fun()(1000, 2000) << endl;
}

int main() 
{
    test1();
    return 0;
}
