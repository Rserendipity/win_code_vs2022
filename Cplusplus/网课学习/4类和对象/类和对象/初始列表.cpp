//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//class People
//{
//public:
//	string GetName()
//	{
//		return m_name;
//	}
//	int GetAge()
//	{
//		return m_age;
//	}
//	int GetMath()
//	{
//		return *m_math;
//	}
//	//普通构造
//	People():m_age(20),m_name("张三"), m_math(new int(99))
//	{
//		cout << "普通构造调用" << endl;
//	}
//	//有参构造
//	People(int a,string name,int math):m_age(a),m_name(name), m_math(new int(math))
//	{
//		cout << "有参构造调用" << endl;
//	}
//	//拷贝构造
//	
//	/*People(People&p)
//	{
//		m_age = p.GetAge();
//		m_name = p.GetName();
//		cout << "拷贝构造调用" << endl;
//	}*/
//	/*
//		不写拷贝构造的时候,系统会自动写一个拷贝构造,系统提供的是浅层拷贝,只是值复制而已
//		当用到动态开辟空间的时候就会出问题,重复释放,所以代码会崩溃,所以用到堆区空间的时候要自己写拷贝构造
//	*/
//	People(const People& p)
//	{
//		m_age = p.m_age;
//		m_name = p.m_name;
//		m_math = new int(*p.m_math);
//		cout << "拷贝构造调用" << endl;
//	}
//
//	//析构
//	~People()
//	{
//		delete(m_math);
//		cout << "析构调用" << endl;
//	}
//private:
//	int m_age;
//	string m_name;
//	int* m_math;
//};
//
//
//void test1()
//{
//	People p1;
//	cout << p1.GetName() << p1.GetAge() << p1.GetMath() << endl;
//	People p2(10,"李四",100);
//	cout << p2.GetName() << p2.GetAge() << p2.GetMath() << endl;
//	People p3(p2);
//	cout << p3.GetName() << p3.GetAge() << p3.GetMath() << endl;
//}
//void test2()
//{
//	People p1 = People(); //显式调用
//	People p2 = People(p1); //隐式转换,会调用拷贝构造
//
//}
//
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}
