#ifndef _STACK_H_
#define  _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType int
#define DEFAULT_STACK_SIZE 8

typedef struct stack
{
	DataType *base;
	size_t   capacity;
	size_t   top;
}stack;

void StackInit(stack* ps, size_t sz);
void StackPush(stack* ps, DataType x);
void StackPop(stack* ps);
DataType StackTop(stack* ps);

void StackShow(stack* ps);
void StackClear(stack* ps);
void StackDestroy(stack* ps);


#endif/*_STACK_H_*/