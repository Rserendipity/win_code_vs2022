#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	/* �ڴ����� : ������ ��̬�� ջ �� */
	//������ : ��Ŵ���,�����޸�
	//��̬�� : ��ž�̬����,���糣���ַ���,const���ε�ֵ
	//ջ : ��������ʱ�ı���
	//�� : ��̬�ڴ濪�ٳ����Ŀռ�������

	//c++�Ķ�̬���� : new
	/*
		����* ���� = new ����(��ʼֵ)
		����* ���� = new ����[�����С]
	*/
	int* p1 = new int[10]; //����10��Ԫ�ش�С������
	int* p2 = new int(10); //����һ��Ԫ�ش�С�ռ�,���Ҹ�ֵΪ10
	p1[1] = 1;
	//memset(p1, 'a', sizeof(int) * 10);
	for (int i = 0; i < 10; i++)cout << p1[i] << endl;
	//ceshi

	return 0;
}



