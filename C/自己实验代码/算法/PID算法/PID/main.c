#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct PID
{
	double p;
	double i;
	double d;

	double in;
	double out;

	double err;
	double errLast;
	double errALl;

	double set;
}pid;

void PidInit()
{
	pid.p = 0.9;
	pid.i = 0.09;
	pid.d = 0.01;

	pid.errLast = 0;
	pid.set = 450;
}

double PidMain()
{
	pid.err = pid.set - pid.in;
	pid.errALl += pid.err;

	pid.out = pid.p * pid.err +
		pid.i * pid.errALl +
		pid.d * (pid.err - pid.errLast);

	pid.errLast = pid.err;
	return pid.out;
}

int main()
{
	double a;
	PidInit();
	scanf("%lf", &a);
	for (int i = 0; i < 100; i++)
	{
		pid.in = a;
		a = PidMain();
		printf("%lf \n", a);
	}

	return 0;
}



