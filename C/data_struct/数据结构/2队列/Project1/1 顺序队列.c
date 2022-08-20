#include "queun.h"



int main()
{
	char data = 'A';
	for (int i = 0; i < 10; i++)
	{
		enqueun(data);
		data++;
	}

	while (!is_empty())
	{
		printf("%c ", dequeun());
	}

	return 0;
}