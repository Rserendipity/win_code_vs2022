#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int my_atoi(const char* s)
{
	if (s == NULL)
		return 0;
	int flag = 0;
	int count = 0;
	while (isdigit(*s) == 0)
		//һֱѭ��ֱ��������һ������
	{
		if (*s == '\0')
			//һֱѭ����ֱ�����û�ҵ�һ������
		{
			return 0;
		}
		s++;
	}

	//�жϴ�ʱ��һ������֮ǰ��û��+-��
	s--;
	if (*s == '-')
		//�����һ������֮ǰ��-��
	{
		flag = -1;
		s++;
	}
	else
		//���ǰ����+�Ż����������߰����Ķ�����Ĭ��ת����������
	{
		flag = 1;
		s++;
	}
	//��ʱsָ�����Ȼ�ǵ�һ��Ҫת��������
	while (isdigit(*s) != 0)
		//��Ϊ��ת����ʱ����ܻ������������ֵ�����
		//���Ǿ�ֹͣ
	{
		count = count * 10 + (*s - '0');
		if (count < INT_MIN || count > INT_MAX)
			return 0;
		s++;
	}
	return count * flag;
}
int main() 
{
	int a = my_atoi("123222222222222");
	printf("%d", a);
	return 0;
}
