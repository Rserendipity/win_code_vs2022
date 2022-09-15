#include "Stack.h"

/// <summary>
/// ��ͨ����
/// </summary>
Stack::Stack():l()
{
}

/// <summary>
/// ����˳���ʼ���вι���
/// </summary>
/// <param name="arr"> �������� </param>
/// <param name="size"> �����С </param>
Stack::Stack(int arr[], int size):l()
{
	for (int i = 0; i < size; i++)
	{
		l.Add(arr[i]);
	}
}

/// <summary>
/// ��������
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
/// ����
/// </summary>
Stack::~Stack()
{

}

/// <summary>
/// ��ջ
/// </summary>
/// <param name="val"> ��val��ջ </param>
void Stack::Push(int val)
{
	this->l.Add(val);
}

/// <summary>
/// ����ջ��Ԫ��
/// </summary>
void Stack::Pop()
{
	this->l.Pop();
}

/// <summary>
/// ��ȡջ��Ԫ��
/// </summary>
/// <returns> ���صõ�ջ��Ԫ�� </returns>
int Stack::GetTop()
{
	return this->l.GetHeadVal();
}

/// <summary>
/// ��ȡջԪ�ظ���
/// </summary>
/// <returns></returns>
int Stack::GetValSize()
{
	return this->l.GetSize();
}
