#include "Stack.h"

/// <summary>
/// 普通构造
/// </summary>
Stack::Stack():l()
{
}

/// <summary>
/// 数组顺序初始化有参构造
/// </summary>
/// <param name="arr"> 传入数组 </param>
/// <param name="size"> 数组大小 </param>
Stack::Stack(int arr[], int size):l()
{
	for (int i = 0; i < size; i++)
	{
		l.Add(arr[i]);
	}
}

/// <summary>
/// 拷贝构造
/// </summary>
/// <param name="s"></param>
Stack::Stack(const Stack& s):l()
{
	Stack temp = s;
	for (int i = temp.GetValSize(); i >= 0; i--)
	{
		this->l.Add(temp.GetTop());
		temp.Pop();
	}
	this->l.Reverse();
}

/// <summary>
/// 析构
/// </summary>
Stack::~Stack()
{

}

/// <summary>
/// 入栈
/// </summary>
/// <param name="val"> 将val入栈 </param>
void Stack::Push(int val)
{
	this->l.Add(val);
}

/// <summary>
/// 弹出栈顶元素
/// </summary>
void Stack::Pop()
{
	this->l.Pop();
}

/// <summary>
/// 获取栈顶元素
/// </summary>
/// <returns> 返回得到栈顶元素 </returns>
int Stack::GetTop()
{
	return this->l.GetHeadVal();
}

/// <summary>
/// 获取栈元素个数
/// </summary>
/// <returns></returns>
int Stack::GetValSize()
{
	return this->l.GetSize();
}
