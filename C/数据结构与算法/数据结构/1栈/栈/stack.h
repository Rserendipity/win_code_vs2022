#pragma once
#include <stdio.h>
#include <string.h>

#define STACK_MAX_SIZE 100

typedef int stack_type;

int top = 0;
stack_type arr[STACK_MAX_SIZE];


void StackPush(stack_type data);
stack_type StackPop();
int IsEmpty();

