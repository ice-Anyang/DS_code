#pragma once

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_back = NULL;
}

void QueueDestory(Queue* pq)
{
	QueueNode* cur;
	assert(pq);

	cur = pq->_front;
	while (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		
		cur = next;
	}

	pq->_front = pq->_back = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
	assert(node);

	node->_next =NULL;
	node->_data = x;

	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->_back == NULL)
	{
		pq->_front = pq->_back = BuyQueueNode(x);
	}
	else
	{
		QueueNode* back = BuyQueueNode(x);
		pq->_back->_next = back;
		pq->_back = back;
	}
}

void QueuePop(Queue* pq)
{
	QueueNode* next;
	assert(pq);
	next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (next == NULL)
	{
		pq->_back = NULL;
	}
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}

// ¿Õ 0
// ·Ç¿Õ 1
int QueueEmpty(Queue* pq)
{
	assert(pq);	
	return pq->_front == NULL ? 0 : 1;
}

int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}

	return size;
}

QUDataType QueueBack(Queue* pq)
{
	return pq->_back->_data;
}


//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//
//	while (QueueEmpty(&q))
//	{
//		printf("%d ", QueueFront(&q));
//		QueuePop(&q);
//	}
//
//	printf("\n");
//
//	QueueDestory(&q);
//}