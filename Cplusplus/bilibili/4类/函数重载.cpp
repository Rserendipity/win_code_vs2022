//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//// ͬһ�������ڲ�ͬ��ʹ�ó������в�ͬ�ĺ���
//// �����ں���Ķ�����
//// ����������c++��̬������
//// 
//// �������ص�������ͬһ����������
//// ����������ͬ or
//// �������Ͳ�ͬ or
//// ����˳��ͬ
//// ����һ���Ϳ�������
//// ע�⣺�����ķ���ֵ������Ϊ�������ص�����
//// ԭ�򣺱������ڱ����ڼ����ò������������β�ͬ�ĺ�����
//// ����func(int)       -->  "func@int"  (��ֻ��һ�ּ���)
////     func(int, int)  -->  "func@intint"
//// 
//// ע�⣺���������غ�Ĭ�ϲ���ͬʱ��һ�����ײ���������
//// 
//void myFunc(int a)
//{
//    cout << "int ����" << endl;
//}
//void myFunc(int a, int b) // ������ͬ
//{
//    cout << "int,int ����" << endl;
//}
//void myFunc(double a, int b) // �������Ͳ�ͬ
//{
//    cout << "double,int����" << endl;
//}
//void myFunc(int a, double b) // ����˳��ͬ
//{
//    cout << "int,double����" << endl;
//}
//void test1()
//{
//    myFunc(10);
//    myFunc(10, 20);
//    myFunc(10, 20.2);
//    myFunc(10.5, 10);
//}
//
//void myFunc2(int a)
//{
//
//}
//void myFunc2(int a, int b = 20) // warning�����ײ���������
//{
//    
//}
//void test2()
//{
//    // myFunc2(10); //err
//    // ���������ԣ�
//    // ԭ�򣺴�һ��������ʱ����������������ƥ��ɹ�
//    // �ڶ���������Ĭ��ֵ�ˣ�����Ҳ����ֻ��һ������
//}
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
