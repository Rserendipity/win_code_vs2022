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
// 错误,返回值不能作为函数识别的标志,所以不能重载
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
	// 1.函数初始值
	/* 
		从第一个出现默认值的地方开始,往后的参数必须有默认值
		优先使用形参值,没有形参值才会使用默认值
		函数声明和实现只能有一处地方加上默认值
	*/
	cout << func1(100) << endl;

	// 2.函数匿名参数
	/*
		第二,三个就是匿名参数
		匿名参数只需要一个类型即可,也可以为其添加默认值
	*/
	cout << func2(10,20) << endl;

	// 3.函数重载
	/*
		通过函数参数来区分重载函数,只要参数不同(位置,个数,顺序)就可以
		返回值的不同不能用来区分重载函数
	*/
	cout << func3(10) << endl;

	// 4.引用重载
	/*
		& 引用和const &引用是不同的
		&是可以读写的引用
		const &是只读的引用
		所以可以使用这两者作为函数重载的区分
	*/
	int a = 10;
	func4(a);   //可以读写的引用
	func4(10);  //只读的引用

	// 5.初始参数引起的函数重载错误
	/*
		func5(int a, int b = 10);
		func5(int a);
		调用func5(10);
		这两个函数都可以被调用,从而引起了歧义,所以会报错
	*/
	//func5(10); 错误!!
	func5(10, 10);  //可行
}


