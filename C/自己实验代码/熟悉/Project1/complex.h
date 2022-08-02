#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	double real;
	double img;
} Complex;

Complex* ComplexCreate(int real, int img);
Complex* ComplexAdd(Complex* num1, Complex* num2);
Complex* ComplexSub(Complex* num1, Complex* num2);
Complex* ComplexMul(Complex* num1, Complex* num2);
Complex* ComplexDiv(Complex* num1, Complex* num2);
void ComlexPrint(Complex* num);


#endif // !_COMPLEX_H
