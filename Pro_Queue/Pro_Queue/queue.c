#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

static QueueIsFull(Queue* ps)//�ж��Ƿ���
{
	return ps->tail >= ps->capacity;
}
static QueueIsEampty(Queue* ps)//�ж��Ƿ��
{
	return ps->front == ps->tail;
}

void QueueInit(Queue* ps,size_t sz)//��ʼ������
{
	ps->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	ps->base = (DataType *)malloc(sizeof(DataType)*(ps->capacity));
	assert(ps->base != NULL);
	ps->front = ps->tail = 0;
}

void QueuePush(Queue* ps, DataType x)//���
{
	if (QueueIsFull(ps))
	{
		printf("�������������ܲ���%d�ˡ�\n", x);
		return;
	}
	ps->base[ps->tail] = x;
	ps->tail++;
}

void QueueShow(Queue* ps)//��ӡ����
{
	size_t i = ps->front;
	for(i = ps->front; i < ps->tail; ++i)
	{
		printf("%d  ", ps->base[i]);
	}
	printf("\n");
}

void QueuePop(Queue* ps)//����
{
	if (QueueIsEampty(ps))
	{
		printf("�����ѿգ����ܳ��ӡ�\n");
		return;
	}
	ps->front++;
}

void QueueFront(Queue* ps)//ȡ��ͷ
{
	if (QueueIsEampty(ps))
	{
		printf("�����ѿգ�����ȡ��ͷԪ�ء�\n");
		return;
	}
	return ps->base[ps->front];
}


