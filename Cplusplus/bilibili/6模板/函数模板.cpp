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

template<class T>
T funcT1(T a, T b) 
{
    return a + b;
}

template<class T>
void funcT2() 
{
    cout << "funcT2" << endl;
}

template<class T1, class T2, class T3>
T3 funcT3(T1 a, T2 b) 
{
    return a + b;
}

template<class T3, class T1, class T2>
T3 funcT4(T1 a, T2 b) 
{
    return a + b;
}

/// <summary>
/// �����Ƶ�
/// </summary>
void test2()
{
    // ��������ͨ������Ĳ����Ƶ�ģ������
    cout << funcT(10, 20) << endl; // �������int�������Ƶ�Ҳ��int
    cout << funcT(10.13, 20.43) << endl; // �������double�������Ƶ�Ҳ��double

    // Ҳ����ǿ��ָ�����ͣ�����ǿ��ָ�������ͽ�����Ӧ�ĺ�������
    cout << funcT<double>(10, 20) << endl; // �������double��ǿ�Ƶ���double


    cout << funcT1(10, 20) << endl; // Ĭ�������Լ��Ƶ�
    cout << funcT1<>(10, 20) << endl; // ���Բ�ָ�����ͣ��Զ��Ƶ�
    // cout << funcT1(10, 20.567) << endl; //����д��������������ͬ���͵Ĳ������������޷��Ƶ����������ͣ��ں���ģ�����棬�޷�������ʽ����ת��
    cout << funcT1<int>(10, 20.567) << endl;//���ǿ�����ʽָ������
    cout << funcT1<double>(10, 20.567) << endl;//Ҫô���߱�������ʲô���ͣ�Ҫô�����Զ��Ƶ�������Ҫ��֤ͬһ�����Ͳ������������ͱ���һ��


    //funcT2(); // ��Ȼ�ں�����û��ʹ�õ����Ͳ���������Ҳ����ø��߱�����������Ҫ���õ��Ǻ���ģ��
    funcT2<int>(); // ��Ϊû�в��������Ա�������û�취���ݲ����Ƶ������ͣ����Ա����ǿ��ָ��


    //cout<<funcT3(a,b)<<endl;//����д�������������Ͳ���������ֻ��������ֵ�����Ա������޷��Ƶ������һ������
    cout << funcT3<int, int, int>(10, 20) << endl;
    cout << funcT4<int>(10, 20) << endl;//�˴�����һ�����Ͳ���Ҫָ�����ڶ������������������ɱ������Զ��Ƶ�
}

/// <summary>
/// ����ģ��ĵ���ʱ��
/// </summary>
void test3()
{
    // ����ģ���ڱ����ڼ�ȷ���������ڱ��뵽������������Ż�ȷ������ģ��ľ�������
    funcT<int>(10, 20);       // ������һ��int�͵ĺ���
    funcT<double>(10, 20.2);  // ������һ��doubel�͵ĺ���
}

template <typename T>
T add(T x, T y)
{
    cout << "����ģ��" << endl;
    return x + y;
}
int add(int x, int y)
{
    cout << "��ͨ����" << endl;
    return x + y;
}
/// <summary>
/// ����ģ������ͨ����֮�������
/// </summary>
void test4()
{
    cout << add(10, 20) << endl; // Ĭ�ϵ��õ�����ͨ�ĺ���
    cout << add<int>(10, 20) << endl; // ��ʽ��ָ���˵��ú���ģ��

}




//ָ�����ͺ�ֵ
template<class T1, class T2 = int> // �����ʾ�������Ͳ�����Ĭ��ֵ
void funcT1(T1 a, T2 b = 123) 
{
    // �����ʾ���Ǻ�����T2���͵Ĳ�����Ĭ��ֵ
    cout << a << endl;
    cout << b << endl;
}
//ָ������
template<class T1 = int, class T2>
void funcT2(T2 b) 
{
    T1 a = b;
    cout << b << "--" << a << endl;
}

/// <summary>
/// ģ���Ĭ�������Լ�����
/// </summary>
void test5()
{
    funcT1<char>('a'); // t1 Ϊchar�ͣ� t2û��ָ��������Ĭ�ϸ���int��
    funcT2<>('a');

}

int main() 
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}
