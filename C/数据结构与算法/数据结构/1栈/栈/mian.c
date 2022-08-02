#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

/* 第一节 : 基本实现
int main()
{
	StackPush(1);
	StackPush(2);
	StackPush(3);

	while (IsEmpty())
	{
		printf("%d ", StackPop());
	}

	return 0;
}

void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}
*/

/* 第二节: 逆波兰表达

int main()
{
	char buf[STACK_MAX_SIZE] = { 0 };
	gets(buf);
	for (int i = 0; i < strlen(buf); i++)
	{
		if ((buf[i] >= '0') && (buf[i] <= '9'))
			StackPush(buf[i] - '0');
		else
		{
			stack_type temp2 = StackPop();
			stack_type temp1 = StackPop();

			switch (buf[i])
			{
			case '+': 
				StackPush(temp1 + temp2); 
				break;
			case '-': 
				StackPush(temp1 - temp2); 
				break;
			case '*': 
				StackPush(temp1 * temp2); 
				break;
			}
		}
	}
	printf("%d\n", StackPop());

	return 0;
}
void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}
*/

/* 普通表达式转换为逆波兰表达式
int main()
{
	char buf[STACK_MAX_SIZE] = { 0 };
	gets(buf);
	
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == '(')
			continue;
		else if (buf[i] >= '0' && buf[i] <= '9')
			printf("%c", buf[i]);
		else if (buf[i] == '-' || buf[i] == '+' || buf[i] == '*')
			StackPush(buf[i]);
		else if (buf[i] == ')')
			printf("%c", StackPop());
	}
	printf("%c\n", StackPop());
	return 0;
}
void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}
*/

/* 括号配对 
int main()
{
	char buf[STACK_MAX_SIZE] = { 0 };
	gets(buf);
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == '(')
			StackPush(i);
		else if (buf[i] == ')')
			printf("%d %d\n", StackPop(), i);
		else continue;
	}
	return 0;
}
void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}
*/

/* 十进制转二进制 
int main()
{
	int input = 0;
	scanf("%d", &input);

	while (input)
	{
		StackPush(input % 2);
		input /= 2;
	}
	while (IsEmpty())
	{
		printf("%d", StackPop());
	}
	return 0;
}
void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}
*/

/* 回文判定 
int main()
{
	char buf[STACK_MAX_SIZE] = { 0 };
	gets(buf);
	int i = 0;
	for (i; i < strlen(buf) / 2; i++)
	{
		StackPush(buf[i]);
	}
	if (strlen(buf) / 2)
		i++;
	for (i; i < strlen(buf); i++)
	{
		if (StackPop() == buf[i])
			continue;
		else
		{
			printf("bushi\n");
			return 0;
		}
	}
	printf("是回文\n");

	return 0;
}
void StackPush(stack_type data)
{
	arr[top++] = data;
}

stack_type StackPop()
{
	return arr[--top];
}

int IsEmpty()
{
	return top != 0;
}*/
int main()
{
	int a = 0;
	scanf("%d", &a);
	return 0;
}