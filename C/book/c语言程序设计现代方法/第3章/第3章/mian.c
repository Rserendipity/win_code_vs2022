#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a, c;
	float b;
	scanf("%d", &a);
	//输入为 "12qw" 时
	//读入a的数据为12,qw会被保留,等待下一次scanf的调用
	
	scanf("%d/%f%d", &a, &b, &c);
	//输入为 "10.3 5 6" 时
	//scanf依次读取,首先是用%d的方式读取,读取到 "10." 发现'.'不属于%d,于是把'.'放回原处,等待下一次调用
	//然后以%f的方式调用,读取到".3 (这里有个空格)",空格不属于%f,所以把0.3放入b变量中,跳过空格
	//然后以%d的方式调用,读取到"5 (这里有个空格)",空格不属于%d,所以把5放入到c变量中,剩余的"6"会被保留至io流,等待下一次的scanf读取

	//scanf在读取时会跳过一开始的空白符号(\n,\t,空格),直到读取到第一个属于%(?)内容的值
	//然后读取到不属于这个%的值的时候停止,再看后面有没有%(?)的内容
	
	//当scanf里不止有%时,scanf会对输入一一比对,然后跳过相同的值
	//当出现不匹配时,scanf不会继续读取,直接异常退出,可以用assert异常函数来查看


	return 0;
}



