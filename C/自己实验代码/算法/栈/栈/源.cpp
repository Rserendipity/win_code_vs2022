#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

constexpr auto STACK_SIZE = 15;

class Stack
{
public:
	void StackPush(int num);
	int StackPop();
	int GetTop();
	Stack():top(0){}
private:
	int top;
	int arr[STACK_SIZE];
};
void Stack::StackPush(int num)
{
	this->arr[this->top++] = num;
}
int Stack::StackPop()
{
	return this->arr[--this->top];
}
int Stack::GetTop()
{
	return this->top;
}

int main()
{
	Stack s1;
	for (int i = 0; i < 10; i++) s1.StackPush(i);
	for (int i = 0; i < 10; i++) cout << s1.StackPop() << " ";

	return 0;
}