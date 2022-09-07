#include <stdio.h>

int main()
{
	int max(int x, int y);
	int a, b, c, d, e;
	scanf_s("%d %d %d %d", &a, &b, &d, &e);
	c = max(a, max(b, max(d, e)));
	printf("%d", c);
	return 0;
}
int max(int x, int y)
{
	if (x > y)
		return(x);
	else 
		return(y);
}
