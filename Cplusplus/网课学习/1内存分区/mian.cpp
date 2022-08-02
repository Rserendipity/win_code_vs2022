#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	/* 内存四区 : 代码区 静态区 栈 堆 */
	//代码区 : 存放代码,不可修改
	//静态区 : 存放静态变量,例如常量字符串,const修饰的值
	//栈 : 程序运行时的变量
	//堆 : 动态内存开辟出来的空间在这里

	//c++的动态开辟 : new
	/*
		类型* 名字 = new 类型(初始值)
		类型* 名字 = new 类型[数组大小]
	*/
	int* p1 = new int[10]; //开辟10个元素大小的数组
	int* p2 = new int(10); //开辟一个元素大小空间,并且赋值为10
	p1[1] = 1;
	//memset(p1, 'a', sizeof(int) * 10);
	for (int i = 0; i < 10; i++)cout << p1[i] << endl;
	//ceshi

	return 0;
}



