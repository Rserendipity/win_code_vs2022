//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class A {
//private:
//    int a;
//public:
//    A()
//    {
//        cout << "A�޲ι���" << endl;
//    }
//    A(int a)
//    {
//        this->a = a;
//        cout << "A�вι���" << endl;
//    }
//    ~A()
//    {
//        cout << "A������" << endl;
//    }
//};
//class B {
//private:
//    int b;
//public:
//    B()
//    {
//        cout << "B�޲ι���" << endl;
//    }
//    B(int b)
//    {
//        this->b = b;
//        cout << "B�вι���" << endl;
//    }
//    ~B()
//    {
//        cout << "B������" << endl;
//    }
//};
//class Data {
//private:
//    A a;
//    B b;
//    int data;
//public:
//    Data()
//    {
//        cout << "Data�޲ι���" << endl;
//    }
//    Data(int a, int b, int c):a(a),b(b),data(c)
//    {
//        cout << "Data�вι���" << endl;
//    }
//    ~Data()
//    {
//        cout << "Data����" << endl;
//
//    }
//};
///// <summary>
///// �����Ա�ĳ�ʼ������ʼ���б�
///// </summary>
//void test1()
//{
//    // �ȵ��ó�Ա�Ĺ��캯��
//    // �ڵ����Լ��Ĺ��캯��
//    // ���������������������Ա
//    // 
//    // ϵͳĬ�ϵ��õ��ǳ�Ա���޲ι���
//    // �ó�ʼ���б���ó�Ա���������캯��
//    // 
//    // Data temp; // ���ڵ�����Ĭ��ʹ�õ����޲ι���
//    Data temp2(10, 20, 30); // ʹ���˳�ʼ���б�����������вι���
//}
//
//class Temp {
//private:
//    int a;
//public:
//    explicit Temp(int num) // explicit���κ��ֹ��ʽת��
//    {
//        cout << num << endl;
//    }
//};
///// <summary>
///// explicit�ؼ��֣���ֹ��ʽת��
///// </summary>
//void test2()
//{
//    // ��ʽת��ֻ���һ����Ա���࣬��������Ϊ�Ǹ�ֵ
//    // ʹ��explicit�ؼ��ֶ��вι��캯�����Σ���ֹ��ʽת��
//    // 
//    //Temp t = 10; // ��ʽת�� err
//    Temp t(10);         // ��ʽ����
//    Temp t2 = Temp(20); // ��ʽ����
//
//}
//
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
