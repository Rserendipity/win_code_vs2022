//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//class People
//{
//public:
//	//��̬��Ա����
//	//����������,��������и���,��̬��Աʱ���е��๲���,����ֻ��һ��
//	//�˱�����ȫ����,����ǰ�ͻ�����ڴ�
//	static int m_age; 
//	string name;
//	//��̬��Ա����
//	//�������Ǿ�̬�ĺ���,ÿ�����������Ķ��󶼿��Է���
//	//���Բ����Է���ĳһ������ı���,���ǾͲ����ھ�̬�������ó�Ա����,ֻ���þ�̬��Ա����
//	static void func()
//	{
//		m_age = 100; //m_age�Ǿ�̬����,���Կ���ʹ��
//		//name = "����"; //������ʹ��
//		//ÿһ��������name��Ա,���Ծ�̬������֪��ʹ��˭�ĳ�Ա,����������ھ�̬������ʹ�ó�Ա����
//		cout << "static void func()�ĵ���" << endl;
//	}
//
//
//};
////People��ľ�̬������ʼ��, "People::" �����˳�ʼ������People���µ�m_age
//int People::m_age = 100;
//
//void test1()
//{
//	//����1:�����������
//	People p1;
//	cout << p1.m_age << endl;
//	//����2:����������
//	cout << People::m_age << endl;
//}
//void test2()
//{
//	//����1:�����������
//	People p1;
//	p1.func();
//	//����2:����������
//	People::func();
//}
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}
