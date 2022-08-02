#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void left();
void right();

struct Car
{
	void (*pLeft)();
	void (*pRight)();
	int leftMotor;
	int rightMotor;
}car;

void left()
{
	car.leftMotor = 1230;
	car.rightMotor = 123124;
}
void right()
{
	car.leftMotor = 1230;
	car.rightMotor = 123124;
}

void CarInit()
{
	car.pLeft = left;
	car.pRight = right;
	car.leftMotor = 0;
	car.rightMotor = 0;
}
int main()
{
	CarInit();
	car.pLeft();
	car.pLeft();
	car.pRight();

	printf("%d %d", car.leftMotor, car.rightMotor);

	return 0;
}