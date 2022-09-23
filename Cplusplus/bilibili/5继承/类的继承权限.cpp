#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Other {
public:
    Other()
    {
        cout << "其他对象构造" << endl;
    }
    ~Other()
    {
        cout << "其他对象析构" << endl;
    }
};

class Base {
public:
    Base()
    {
        cout << "基类无参构造" << endl;
    }
    ~Base()
    {
        cout << "基类析构" << endl;
    }
    int A;
protected:
    int B;
private:
    int C;
};

class Son1 :public Base {
public:
    Son1()
    {
        cout << "派生类无参构造" << endl;
    }
    ~Son1()
    {
        cout << "派生类析构" << endl;
    }
    void Show()
    {
        cout << A << endl; // A对外是公开的（不改变基类状态）
        cout << B << endl; // B对外是保护的（不改变基类状态）
        // cout << C << endl; // 私有数据不可访问
    }
    Other o1;
};

class Son2 :protected Base {
public:
    void Show()
    {
        cout << A << endl; // A对外是保护的（保护继承将公开数据改为保护数据）
        cout << B << endl; // B对外是保护的（不改变基类状态）
        // cout << C << endl; // 私有数据不可访问
    }
};

class Son3 :private Base {
public:
    void Show()
    {
        cout << A << endl; // A对外是私有的（私有继承是顶级权限，所有的数据都会被改为私有）
        cout << B << endl; // B对外是私有的（私有继承是顶级权限，所有的数据都会被改为私有）
        // cout << C << endl; // 私有数据不可访问
    }
};


void test1()
{
    Son1 s1;
    Son2 s2;
    Son3 s3;
    cout << s1.A << endl;    // 基类为public，   继承为public，数据为public，   可以外部访问
    // cout << s1.B << endl; // 基类为protected，继承为public，数据为protected，不可以外部访问
    // cout << s1.C << endl; // 基类为private，  继承为public，数据为private，  不可以外部访问

    // cout << s2.A << endl; // 基类为public，   继承为protected，数据为protected，不可以外部访问
    // cout << s3.B << endl; // 基类为protected，继承为protected，数据为protected，不可以外部访问
    // cout << s3.C << endl; // 基类为private，  继承为protected，数据为private，  不可以外部访问

    // cout << s3.A << endl; // 基类为public，   继承为private，数据为private，不可以外部访问
    // cout << s3.B << endl; // 基类为protected，继承为private，数据为private，不可以外部访问
    // cout << s3.C << endl; // 基类为private，  继承为private，数据为private，不可以外部访问
}

void test2()
{
    Son1 s1;
    cout << s1.A << endl;
    // 基类构造，然后派生类构造
    // 派生类析构，然后基类析构
    // 
}

void test3()
{
    Son1 s;
    // 基类构造   --->    成员构造   --->    自身构造  
    // 自身析构   --->    成员析构   --->    基类析构   
}

int main(int a) 
{
    auto a = [](int x, int y)
    {
        return x + y;
    };

    // test1();
    // test2();
    test3();
    return 0;
}
