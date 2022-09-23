#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Other {
public:
    Other()
    {
        cout << "����������" << endl;
    }
    ~Other()
    {
        cout << "������������" << endl;
    }
};

class Base {
public:
    Base()
    {
        cout << "�����޲ι���" << endl;
    }
    ~Base()
    {
        cout << "��������" << endl;
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
        cout << "�������޲ι���" << endl;
    }
    ~Son1()
    {
        cout << "����������" << endl;
    }
    void Show()
    {
        cout << A << endl; // A�����ǹ����ģ����ı����״̬��
        cout << B << endl; // B�����Ǳ����ģ����ı����״̬��
        // cout << C << endl; // ˽�����ݲ��ɷ���
    }
    Other o1;
};

class Son2 :protected Base {
public:
    void Show()
    {
        cout << A << endl; // A�����Ǳ����ģ������̳н��������ݸ�Ϊ�������ݣ�
        cout << B << endl; // B�����Ǳ����ģ����ı����״̬��
        // cout << C << endl; // ˽�����ݲ��ɷ���
    }
};

class Son3 :private Base {
public:
    void Show()
    {
        cout << A << endl; // A������˽�еģ�˽�м̳��Ƕ���Ȩ�ޣ����е����ݶ��ᱻ��Ϊ˽�У�
        cout << B << endl; // B������˽�еģ�˽�м̳��Ƕ���Ȩ�ޣ����е����ݶ��ᱻ��Ϊ˽�У�
        // cout << C << endl; // ˽�����ݲ��ɷ���
    }
};


void test1()
{
    Son1 s1;
    Son2 s2;
    Son3 s3;
    cout << s1.A << endl;    // ����Ϊpublic��   �̳�Ϊpublic������Ϊpublic��   �����ⲿ����
    // cout << s1.B << endl; // ����Ϊprotected���̳�Ϊpublic������Ϊprotected���������ⲿ����
    // cout << s1.C << endl; // ����Ϊprivate��  �̳�Ϊpublic������Ϊprivate��  �������ⲿ����

    // cout << s2.A << endl; // ����Ϊpublic��   �̳�Ϊprotected������Ϊprotected���������ⲿ����
    // cout << s3.B << endl; // ����Ϊprotected���̳�Ϊprotected������Ϊprotected���������ⲿ����
    // cout << s3.C << endl; // ����Ϊprivate��  �̳�Ϊprotected������Ϊprivate��  �������ⲿ����

    // cout << s3.A << endl; // ����Ϊpublic��   �̳�Ϊprivate������Ϊprivate���������ⲿ����
    // cout << s3.B << endl; // ����Ϊprotected���̳�Ϊprivate������Ϊprivate���������ⲿ����
    // cout << s3.C << endl; // ����Ϊprivate��  �̳�Ϊprivate������Ϊprivate���������ⲿ����
}

void test2()
{
    Son1 s1;
    cout << s1.A << endl;
    // ���๹�죬Ȼ�������๹��
    // ������������Ȼ���������
    // 
}

void test3()
{
    Son1 s;
    // ���๹��   --->    ��Ա����   --->    ������  
    // ��������   --->    ��Ա����   --->    ��������   
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
