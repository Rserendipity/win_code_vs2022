//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class People
//{
//public:
//	string getname()
//	{
//		return m_name;
//	}
//	int getage()
//	{
//		return m_age;
//	}
//	//构造函数
//	People() //无参
//	{
//		m_name = "abc";
//		m_age = 10;
//		m_car = "宝马";
//		cout << "普通构造函数" << endl;
//	}
//	//构造函数重载
//	People(int a) //有参
//	{
//		m_name = "abc";
//		m_age = a;
//		m_car = "宝马";
//		cout << "重载构造函数" << endl;
//	}
//	//拷贝构造
//	People(const People& p) //拷贝构造形式
//	{
//		m_age = p.m_age;
//		m_name = p.m_name;
//		m_car = p.m_car;
//	}
//
//
//	//析构函数
//	~People()
//	{
//		cout << "析构函数调用" << endl;
//	}
//
//private:
//	string m_name;
//	int m_age;
//	string m_car;
//};
//
//void test()
//{
//	People p1{};
//	cout << p1.getname() << endl;
//
//}
//int main5(void)
//{
//	/* 
//		构造函数:
//		在创建对象时对类内成员进行初始化,因此只会被调用一次
//		和普通函数相似,函数名为类名,但是没有返回值,可以有参数,所以可以发生重载
//		没有写构造时,编译器会自动调用空的构造函数
//		
//		析构函数:
//		用于销毁对象,故也只会被调用一次
//		函数名为"~类名",没有返回值,没有参数,不可以重载
//		没写构造,系统也会自动调用一次空析构
//		
//	*/
//	/*  
//		构造函数分类
//		有无参数 -->  有参,无参 
//		调用方式 -->  括号,显式,隐式
//		
//		People p1; 无参
//		People p2(10); 有参
//		****   People p3();  *****   这个是函数声明!! p3为函数名,参数无,People为返回值
//		
//		//调用方式
//		1.括号调用
//		People p4; //调用默认构造
//		People p5(10); //有参调用
//		2.显式调用
//		People p6
//		People p7 = People(10); //等号右侧是一次匿名对象的创建,然后给到p6,这条语句完毕以后就会析构匿名对象
//		People p8 = People(p7); //拷贝构造一个匿名对象,然后创建p8对象
//		***  不要用拷贝构造单独创建一个匿名对象    ***
//		3.隐式调用
//		People p9 = 10;   // 会隐式转化成--->   People p9 = People(10);
//
//	*/
//
//
//	test();
//	
//
//	return 0;
//}
