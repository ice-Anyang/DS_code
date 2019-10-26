#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

static QueueIsFull(Queue* ps)
{
	return ps->tail >= ps->capacity;
}
static QueueIsEampty(Queue* ps)
{
	return ps->front == ps->tail;
}

void QueueInit(Queue* ps,size_t sz)
{
	ps->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	ps->base = (DataType *)malloc(sizeof(DataType)*(ps->capacity));
	assert(ps->base != NULL);
	ps->front = ps->tail = 0;
}

void QueuePush(Queue* ps, DataType x)
{
	if (QueueIsFull(ps))
	{
		printf("队列已满，不能插入%d了。\n", x);
		return;
	}
	ps->base[ps->tail] = x;
	ps->tail++;
}

void QueueShow(Queue* ps)
{
	size_t i = ps->front;
	for(i = ps->front; i < ps->tail; ++i)
	{
		printf("%d  ", ps->base[i]);
	}
	printf("\n");
}

void QueuePop(Queue* ps)
{
	if (QueueIsEampty(ps))
	{
		printf("队列已空，不能出队。\n");
		return;
	}
	ps->front++;
}

void QueueFront(Queue* ps)
{
	if (QueueIsEampty(ps))
	{
		printf("队列已空，不能取对头元素。\n");
		return;
	}
	return ps->base[ps->front];
}


