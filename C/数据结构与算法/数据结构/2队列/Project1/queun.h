#ifndef __QUEUN_H__
#define __QUEUN_H__
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define SIZE 100
typedef char QueunType;

QueunType queun[SIZE];

void enqueun(QueunType data);
QueunType dequeun(void);
int is_empty();




#endif // !

