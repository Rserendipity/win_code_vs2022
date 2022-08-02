#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class People
{
	//属于类创建的对象
	int m_age;

	//以下都不属于类创建的对象
	static int m_math;
	void func1() {}
	static void func2() {}
};
class Person
{
public:
	// this指针的第一种用处,防止名字冲突,加上 this-> 表示调用的时本对象的成员
	Person(int age)
	{
		this->age = age;
	}
	//链式访问:
	/*  不能进行链式访问!
	void AddAgeByPerson(Person & p)
	{
		this->age += p.age;
	}
	*/
	/*  返回的是一个值,会调用拷贝构造函数,返回以后是一个匿名对象,所以只能对原值修改一次
	Person AddAgeByPerson(Person& p)
	{
		this->age += p.age;
		return *this;
	}
	*/
	Person &AddAgeByPerson(Person &p) //返回的是自身引用,所以以后修改的值都是对自身的修改
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

void test1()
{
	People p1;

	//类内什么都没有时,字节大小为1
	/****    这个很重要   *****/
	cout << sizeof(People) << endl;

	//类内只有 非静态成员变量 属于创建的对象
	//只需要计算 非静态成员变量 的空间大小就可以了
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