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
        cout << "����" << endl;
    }
};

void test1()
{
    Fun f; 
    // �������󣬵��ö���ķ�������ɼ���
    cout << f.Add(10, 20) << endl;

    // ֱ���ã����������������ɼ���
    cout << f(100, 200) << endl;

    // Fun()   �����������ţ�������һ����������,Ȼ�����������������������������������㣬Ȼ���Զ�����
    cout << Fun()(1000, 2000) << endl;
}

int main() 
{
    test1();
    return 0;
}
