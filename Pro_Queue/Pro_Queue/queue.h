#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType int
#define DEFAULT_QUEUE_SIZE 80

typedef struct Queue
{
	DataType *base;
	size_t   front;
	size_t   tail;
	size_t   capacity;
}Queue;

void QueueInit(Queue* ps, size_t sz);
void QueuePush(Queue* ps,DataType x);
void QueueShow(Queue* ps);
void QueuePop(Queue* ps);
void QueueFront(Queue* ps);



#endif/*_QUEUE_H_*/