#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class People
{
public:
	string GetName(void)
	{
		return m_name;
	}
	int GetAge(void)
	{
		return m_age;
	}
	void SetName(string name)
	{
		m_name = name;
	}
	void SetAge(int age)
	{
		if (age >= 0 && age <= 120)
		{
			m_age = age;
		}
		else cout << "非法年龄输入!" << endl;
	}
private:
	string m_name;
	int m_age;
};

class List
{
public:
	void SetInfo()
	{
		int age = 0;
		cin >> age; 
		m_data.SetAge(age);
		string name;
		cin >> name;
		m_data.SetName(name);
	}
	void PrintAllInfo()
	{
		List* p1 = m_node;
		while (p1 != NULL)
		{
			cout << p1->m_data.GetAge() << " " << p1->m_data.GetName() << endl;
			p1 = p1->m_node;
		}
	}

private:
	//普通构造,把链表指针初始化
	List():m_node(NULL){}
	List* m_node;
	People m_data;
};



class Car
{
public:
	void left()
	{
		leftMotor = 1230;
		rightMotor = 123124;
	}
	void right()
	{
		leftMotor = 1230;
		rightMotor = 123124;
	}



private:
	int leftMotor;
	int rightMotor;
};


int main1(void)
{




	return 0;
}
