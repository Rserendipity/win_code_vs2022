#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class People {
private:
    char m_name[32];
    int m_age;
public:
    // 类的初始化
    void initPeoson(const char* name, int age)
    {
        strcpy(m_name, name);
        m_age = age;
    }
    // 设置名称
    void setName(char* name)
    {
        strcpy(m_name, name);
    }
    // 获取名称
    char* getName()
    {
        return m_name;
    }
    // 设置年龄
    void setAge(int age)
    {
        m_age = age;
    }
    // 获取年龄
    int getAge()
    {
        return m_age;
    }
    // 显示全部信息
    void showPeoson()
    {
        cout << "name is: " << m_name << endl;
        cout << "age is: " << m_age << endl;
    }
};
// 人这个类
void test1()
{
    People lucy;
    lucy.initPeoson("lucy", 20);
    cout << "name is " << lucy.getName() << endl;
    cout << "age is " << lucy.getAge() << endl;
    lucy.setAge(100);

    lucy.showPeoson();
}


class Cul {
public:
    int getC()
    {
        return 2 * (w + l);
    }
    int getS()
    {
        return w * l;
    }
    void init(int w, int l)
    {
        this->w = w;
        this->l = l;
    }
    bool compare(Cul& cmp)
    {
        if (this->l == cmp.l && this->w == cmp.w)
            return true;
        else
            return false;
    }
private:
    int w;
    int l;
};
// 长方行类
void test2()
{
    Cul c1;
    c1.init(10, 20);
    cout << "c1的面积是" << c1.getS() << endl;
    cout << "c1的周长是" << c1.getC() << endl;

    Cul c2;
    c2.init(10, 20);
    if (c1.compare(c2) == true)
        cout << "c1和c2相等" << endl;
    else
        cout << "c1和c2不相等" << endl;

}


class Cyc {
    
};
//圆类
void test3()
{

}

int main() 
{
    // test1();
    test2();
    return 0;
}
