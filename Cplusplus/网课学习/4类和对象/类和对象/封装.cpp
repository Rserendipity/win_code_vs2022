//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//class StudentInfo
//{
//	// 访问权限 - 公用
//public:
//
//	/*
//		类中的属性和行为 ---> 成员
//		属性            ---> 成员属性/成员变量
//		行为            ---> 成员函数/成员方法
//	*/
//
//	// 属性
//	string m_id;
//	string m_name;
//
//	// 行为
//	void InputInfo()
//	{
//		cout << "输入学号:>";
//		cin >> m_id;
//		cout << "输入姓名:>";
//		cin >> m_name;
//	}
//	void DisplayInfo()
//	{
//		cout << "学号为:" << m_id;
//		cout << "姓名为:" << m_name << endl;
//	}
//	void SetName(string name)
//	{
//		m_name = name;
//	}
//	void SetID(string id)
//	{
//		m_id = id;
//	}
//};
//
//
//
//int main1(void)
//{
//	StudentInfo people1{}; // 实例化,用学生信息创建一个people对象
//
//	/* 输入,然后显示 */
//	people1.InputInfo();   // people的行为
//	people1.DisplayInfo(); //
//
//	StudentInfo people2{}; // 实例化,用学生信息创建一个people对象
//	/* 调用方法 */
//	people2.SetName("昌晶晶");
//	people2.SetID("2060710039");
//	people2.DisplayInfo();
//
//	return 0;
//}
