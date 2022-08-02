//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//class People
//{
//public:
//	//静态成员变量
//	//在类内声明,在类外进行复制,静态成员时所有的类共享的,所以只有一份
//	//此变量在全局区,运行前就会分配内存
//	static int m_age; 
//	string name;
//	//静态成员函数
//	//由于这是静态的函数,每个创建出来的对象都可以访问
//	//所以不可以访问某一个对象的变量,于是就不能在静态函数中用成员变量,只能用静态成员变量
//	static void func()
//	{
//		m_age = 100; //m_age是静态变量,所以可以使用
//		//name = "张三"; //不可以使用
//		//每一个对象都有name成员,所以静态函数不知道使用谁的成员,因而不可以在静态函数中使用成员变量
//		cout << "static void func()的调用" << endl;
//	}
//
//
//};
////People类的静态变量初始化, "People::" 表明了初始化的是People类下的m_age
//int People::m_age = 100;
//
//void test1()
//{
//	//访问1:创建对象访问
//	People p1;
//	cout << p1.m_age << endl;
//	//访问2:用类名访问
//	cout << People::m_age << endl;
//}
//void test2()
//{
//	//访问1:创建对象访问
//	People p1;
//	p1.func();
//	//访问2:用类名访问
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
