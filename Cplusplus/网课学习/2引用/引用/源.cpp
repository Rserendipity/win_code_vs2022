#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int* Func()
{
	return new int;
}

void MySwap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

/*
	int* const temp1 = &num1;
	const int* temp2 = &num2;

	temp1 = NULL; // ������ const���ε�ָ�뱾��,ָ�뱾���ܱ��޸�,���ǿ��Ը������ֵ
	temp2 = NULL;

	*temp1 = 10;
	*temp2 = 10;  // ������ const����ָ��,ָ�뱾����Ը�,�����ֵ�����Ը�
*/
int main(void)
{
	//���� : һ�������ı���,�����Ͼ���һ��constָ��,�������ò����Ը���,�����Ը������ö����ֵ
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;

	int num1 = 10, num2 = 20;
	//�������ý�����ֵ
	MySwap(num1, num2);
	cout << num1 << " " << num2 << endl;

	return 0;
}