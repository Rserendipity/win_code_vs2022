#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// ��ͨ����
int func1(int a, int b) 
{
    return a + b;
}
double func2(double a, double b) 
{
    return a + b;
}

// template<class T>
template<typename T>
T funcT(T a, T b) 
{
    return a + b;
}

/// <summary>
/// ����ģ�嶨��
/// </summary>
void test1()
{
    // ��ν����ģ�壬ʵ�ʾ���дһ��ͨ�ú���������ֵ�Ͳ��������Ͷ��ǿɱ�ģ���һ���ض���ʽ�ı�����ָ��
    // Ȼ����ô˺�����ʱ�򣬱���������ݲ������������ͣ��Զ��Ƶ����ͣ��Ӷ��ﵽ�����ڲ�ͬ�����Ͳ����¿ɸ��õ�Ŀ��
    // ���ͨ�ú��������Ǻ���ģ��
    // 
    // template<class T>  T��һ�������������ǹ̶���Ҫ��T��дT��һ�����ϰ�ߣ�������class �ؽ���֮�⣬�������� typename
    // ����Ҳ�����ж��, T1, T2��
    int a = 1;
    int b = 2;

    double c = 1.1;
    double d = 2.2;

    int x = func1(a, b);
    double y = func2(c, d);
    cout << x << "--" << y << endl;

    int X = funcT(a, b);
    double Y = funcT(c, d);
    cout << X << "--" << Y << endl;
}

int main() 
{
    test1();



    return 0;
}
