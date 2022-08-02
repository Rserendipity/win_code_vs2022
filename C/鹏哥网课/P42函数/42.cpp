#define _CRT_SECURE_NO_WARNINGS 1
#include <thread>
#include <iostream>
#include <stdio.h>

void* func(void* agrs) {
	printf("this is thread func\n");
	return NULL;
}

int main()
{
	std::thread th1(func);
	std::thread th2(func);

	th1.join();
	th2.join();

	return 0;
}