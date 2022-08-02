#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class People
{
	//�����ഴ���Ķ���
	int m_age;

	//���¶��������ഴ���Ķ���
	static int m_math;
	void func1() {}
	static void func2() {}
};
class Person
{
public:
	// thisָ��ĵ�һ���ô�,��ֹ���ֳ�ͻ,���� this-> ��ʾ���õ�ʱ������ĳ�Ա
	Person(int age)
	{
		this->age = age;
	}
	//��ʽ����:
	/*  ���ܽ�����ʽ����!
	void AddAgeByPerson(Person & p)
	{
		this->age += p.age;
	}
	*/
	/*  ���ص���һ��ֵ,����ÿ������캯��,�����Ժ���һ����������,����ֻ�ܶ�ԭֵ�޸�һ��
	Person AddAgeByPerson(Person& p)
	{
		this->age += p.age;
		return *this;
	}
	*/
	Person &AddAgeByPerson(Person &p) //���ص�����������,�����Ժ��޸ĵ�ֵ���Ƕ�������޸�
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

void test1()
{
	People p1;

	//����ʲô��û��ʱ,�ֽڴ�СΪ1
	/****    �������Ҫ   *****/
	cout << sizeof(People) << endl;

	//����ֻ�� �Ǿ�̬��Ա���� ���ڴ����Ķ���
	//ֻ��Ҫ���� �Ǿ�̬��Ա���� �Ŀռ��С�Ϳ�����
	cout << sizeof(People) << endl;
}

void test2()
{
	Person p1(10);
	Person p2(10);
	p2.AddAgeByPerson(p1).AddAgeByPerson(p1);
	cout << p2.age << endl;
}

int main()
{
	// test1();
	test2();

	return 0;
}