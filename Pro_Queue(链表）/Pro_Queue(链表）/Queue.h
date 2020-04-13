#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int

typedef struct ListQueueNode
{
	DataType data;
	struct ListQueueNode *next;
}ListQueueNode;

typedef struct ListQueue
{
	ListQueueNode *front;
	ListQueueNode *tail;
}ListQueue;

void ListQueueInit(ListQueue *q);
void ListQueuePush(ListQueue *q, DataType x);
void ListQueuePop(ListQueue *q);
DataType ListQueueFront(ListQueue *q);
void ListQueueShow(ListQueue *q);



#endif/*_QUEUE_H_*/