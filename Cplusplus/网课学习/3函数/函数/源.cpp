#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int func1(int a, int b = 20, int c = 30)
{
	return a + b + c;
}
int func2(int a, int, int = 20)
{
	return 1;
}
int func3()
{
	cout << "this is () func" << endl;
	return 0;
}
int func3(int)
{
	cout << "this is (int) func" << endl;
	return 0;
}
int func3(int, char)
{
	cout << "this is (int, char) func" << endl;
	return 0;
}
// ����,����ֵ������Ϊ����ʶ��ı�־,���Բ�������
//void func3(int, char)
//{
//
//}
void func4(int& a)
{
	cout << "this is func4(int& a)" << endl;
}
void func4(const int& a)
{
	cout << "this is func4(const int& a)" << endl;
}
void func5(int a, int b = 10)
{
	cout << "this is func5(int a, int b = 10)" << endl;
}
void func5(int a)
{
	cout << "this is func5(int a)" << endl;

}

int main(void)
{
	// 1.������ʼֵ
	/* 
		�ӵ�һ������Ĭ��ֵ�ĵط���ʼ,����Ĳ���������Ĭ��ֵ
		����ʹ���β�ֵ,û���β�ֵ�Ż�ʹ��Ĭ��ֵ
		����������ʵ��ֻ����һ���ط�����Ĭ��ֵ
	*/
	cout << func1(100) << endl;

	// 2.������������
	/*
		�ڶ�,����������������
		��������ֻ��Ҫһ�����ͼ���,Ҳ����Ϊ�����Ĭ��ֵ
	*/
	cout << func2(10,20) << endl;

	// 3.��������
	/*
		ͨ�������������������غ���,ֻҪ������ͬ(λ��,����,˳��)�Ϳ���
		����ֵ�Ĳ�ͬ���������������غ���
	*/
	cout << func3(10) << endl;

	// 4.��������
	/*
		& ���ú�const &�����ǲ�ͬ��
		&�ǿ��Զ�д������
		const &��ֻ��������
		���Կ���ʹ����������Ϊ�������ص�����
	*/
	int a = 10;
	func4(a);   //���Զ�д������
	func4(10);  //ֻ��������

	// 5.��ʼ��������ĺ������ش���
	/*
		func5(int a, int b = 10);
		func5(int a);
		����func5(10);
		���������������Ա�����,�Ӷ�����������,���Իᱨ��
	*/
	//func5(10); ����!!
	func5(10, 10);  //����
}


