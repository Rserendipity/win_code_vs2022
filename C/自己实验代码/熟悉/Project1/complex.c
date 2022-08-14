#define _CRT_SECURE_NO_WARNINGS 1
#include "complex.h"

Complex* ComplexCreate(int real, int img)
{
	Complex* newComplex = (Complex*)malloc(sizeof(Complex));
	newComplex->img = img;
	newComplex->real = real;
	return newComplex;
}
Complex* ComplexAdd(Complex* num1, Complex* num2)
{
	Complex* newComplex = (Complex*)malloc(sizeof(Complex));
	newComplex->real = num1->real + num2->real;
	newComplex->img = num1->img + num2->img;
	return newComplex;
}
Complex* ComplexSub(Complex* num1, Complex* num2)
{
	Complex* newComplex = (Complex*)malloc(sizeof(Complex));
	newComplex->real = num1->real - num2->real;
	newComplex->img = num1->img - num2->img;
	return newComplex;
}
Complex* ComplexMul(Complex* num1, Complex* num2)
{
	Complex* newComplex = (Complex*)malloc(sizeof(Complex));
	newComplex->real = num1->real * num2->real - num1->img * num2->img;
	newComplex->img = num1->real * num2->img + num2->real * num1->img;
	return newComplex;
}
Complex* ComplexDiv(Complex* num1, Complex* num2)
{
	Complex* newComplex = (Complex*)malloc(sizeof(Complex));
	newComplex->real = num1->real * num2->real - num1->img * num2->img;
	newComplex->img = num1->real * num2->img + num2->real * num1->img;
	return newComplex;
}
void ComlexPrint(Complex* num)
{
	char sign = num->img > 0 ? '+' : '-';
	printf("%-3.2lf %c %-3.2lfi\n", num->real, sign, num->img);
}