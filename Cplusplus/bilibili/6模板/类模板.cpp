#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template <class T1, class T2> 
class Info {
public:
    Info(T1 t1, T2 t2):info1(t1), info2(t2) {}
    void showInfo()
    {
        cout << info1 << " " << info2 << endl;
    }

private:
    T1 info1;
    T2 info2;
};

void test1() 
{
    // Info info("string", 10); //err 类模板不允许自动推导类型
    Info<string, int> info("string", 10);
    info.showInfo();
}

int main() 
{
    test1();
    return 0;
}
