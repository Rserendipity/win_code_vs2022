//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//    int data;
//};
//
/////// <summary>
/////// ��ͨ���μ̳�
/////// </summary>
////class Yang:public Animal {
////public:
////
////};
////
////class Tuo :public Animal {
////public:
////
////};
////
////class YangTuo :public Yang, public Tuo {
////public:
////
////};
//
///// <summary>
///// ��̳�
///// </summary>
//class Yang:virtual public Animal {
//public:
//
//};
//
//class Tuo :virtual public Animal {
//public:
//
//};
//
//class YangTuo :public Yang, public Tuo {
//public:
//
//};
//
///// <summary>
///// ���μ̳�
/////         Animal
/////         /    \
/////       Yang   Tuo
/////         \   /
/////        YangTuo
///// </summary>
//void test1()
//{
//    //YangTuo y;
//    //// y.data = 100; // err ����̳й�����data
//    //y.Yang::data = 100; // �ж����Ե�ʱ����������򣬼��ɽ������
//}
//
///// <summary>
///// ��̳У�������μ̳еĶ������Լ��ظ��̳�����
///// </summary>
//void test2()
//{
//    YangTuo y;
//    // ��̳���ϵ��ֻ����һ��data
//    // ���е�������ʹ�������ָ�����������ͬһ������
//    // ����˶����ԣ�Ҳ������ڴ��ռ������
//    y.data = 100; 
//    cout << y.data << endl;
//}
//
//int main() 
//{
//    // test1();
//    test2();
//    return 0;
//}
