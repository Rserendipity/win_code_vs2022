#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// ͬһ�������ڲ�ͬ��ʹ�ó������в�ͬ�ĺ���
// �����ں���Ķ�����
// ����������c++��̬������
// 
// �������ص�������ͬһ����������
// ����������ͬ 
// �������Ͳ�ͬ or
// ����˳��ͬ
// ����һ���Ϳ�������
// 

void myFunc(int a)
{
    cout << "int ����" << endl;
}
void myFunc(int a, int b)
{
    cout << "int,int ����" << endl;
}
void myFunc(double a, int b)
{
    cout << "double,int����" << endl;
}
void myFunc(int a, double b)
{
    cout << "int,double����" << endl;
}
void test1()
{
    myFunc(10);
    myFunc(10, 20);
    myFunc(10, 20.2);
    myFunc(10.5, 10);
}
int main() 
{
    test1();
    return 0;
}
