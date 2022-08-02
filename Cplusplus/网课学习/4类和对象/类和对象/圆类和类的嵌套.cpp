//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Point
//{
//public:
//	void SetX(int x)
//	{
//		m_x = x;
//	}
//	int GetX()
//	{
//		return m_x;
//	}
//	void SetY(int y)
//	{
//		m_y = y;
//	}
//	int GetY()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//
//class Circle
//{
//public:
//	void SetR(int r)
//	{
//		m_R = r;
//	}
//	int GetR(void)
//	{
//		return m_R;
//	}
//	void SetPoint(Point& point)
//	{
//		m_point = point;
//	}
//	Point GetPoint()
//	{
//		return m_point;
//	}
//	void CaculateDistance(Point& p)
//	{
//		int temp = (p.GetX() - m_point.GetX()) * (p.GetX() - m_point.GetX()) +
//				   (p.GetY() - m_point.GetY()) * (p.GetY() - m_point.GetY());
//		if (temp == m_R * m_R)
//		{
//			cout << "点在圆上" << endl;
//		}
//		else if (temp > m_R * m_R)
//		{
//			cout << "点在圆外" << endl;
//		}
//		else cout << "点在圆内" << endl;
//	}
//	//圆的两个成员,半径和圆心
//private:
//	int m_R;
//	Point m_point; // 类内嵌套一个类
//};
//
//
//
//int main4(void)
//{
//	Circle c1{};
//	Point center{};
//	center.SetX(10);
//	center.SetY(0);
//	c1.SetR(10);
//	c1.SetPoint(center);
//	 
//	Point p2{};
//	p2.SetX(10);
//	p2.SetY(10);
//
//	c1.CaculateDistance(p2);
//	return 0;
//}