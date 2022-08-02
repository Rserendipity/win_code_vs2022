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

	temp1 = NULL; // 不允许 const修饰的指针本身,指针本身不能被修改,但是可以该里面的值
	temp2 = NULL;

	*temp1 = 10;
	*temp2 = 10;  // 不允许 const修饰指针,指针本身可以改,里面的值不可以改
*/
int main(void)
{
	//引用 : 一个东西的别名,本质上就是一个const指针,所以引用不可以更改,但可以更改引用对象的值
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;

	int num1 = 10, num2 = 20;
	//利用引用交换数值
	MySwap(num1, num2);
	cout << num1 << " " << num2 << endl;

	return 0;
}