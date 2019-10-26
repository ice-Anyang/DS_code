#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

int main()
{
	Queue Q;
	QueueInit(&Q,10);
	QueuePush(&Q,1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueueShow(&Q);
	QueuePop(&Q);
	QueueShow(&Q);
	QueueFront(&Q);
	QueueShow(&Q);
	system("pause");
	return 0;
}