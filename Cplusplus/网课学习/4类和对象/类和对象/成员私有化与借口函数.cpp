//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
///*
//	class和struct的区别:
//	默认访问权限不同,class默认权限是私有的,struct默认权限是公共的
//*/
//
//class People
//{
//	//公用的接口函数,通过接口函数来修改或者读取成员的值
//public:
//	void SetName(string name)
//	{
//		m_name = name;
//	}
//	string GetName()
//	{
//		return m_name;
//	}
//	void SetAge(int age)
//	{
//		if (age <= 120 && age >= 0)
//		{
//			m_age = age;
//		}
//		else
//		{
//			cout << "输入非法" << endl;
//		}
//	}
//	int GetAge()
//	{
//		return m_age;
//	}
//	
//	//私有成员,通过提供的接口函数来修改或者访问
//private:
//	string m_name;
//	int m_age;
//	string m_lover;
//};
//
//
//
//int main3(void)
//{
//	People p1{};
//	p1.SetName("zhang san");
//	p1.SetAge(18);
//	cout << p1.GetName() << "\t" << p1.GetAge() << endl;
//
//	return 0;
//}
