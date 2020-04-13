#include"Queue.h"

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
void ListQueueInit(ListQueue *q)//初始化
{
	q->front = q->tail = NULL;
}
void ListQueuePush(ListQueue *q, DataType x)//入队
{
	ListQueueNode *s = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	if (q->front == NULL)
	{
		q->front = q->tail = s;
		return;
	}
	q->tail->next = s;
	q->tail = s;
}

void ListQueuePop(ListQueue *q)//出队
{
	if (q->front != NULL)
	{
		ListQueueNode *p = q->front;
		q->front = q->front->next;
		free(p);
	}
}

DataType ListQueueFront(ListQueue *q)//取队头
{
	assert(q->front != NULL);
	return q->front->data;
}

void ListQueueShow(ListQueue *q)//打印队列
{
	ListQueueNode *p = q->front;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
