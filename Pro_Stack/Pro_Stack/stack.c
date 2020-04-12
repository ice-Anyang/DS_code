
#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
static bool StackIsFull(stack *pst)//�ж�ջ�Ƿ���
{
	return pst->top >= pst->capacity;
}
static bool StackIsEmpty(stack *pst)//�ж�ջ��
{
	return pst->top == 0;
}

void StackInit(stack* ps, size_t sz)//ջ�ĳ�ʼ��
{
	ps->capacity = sz > DEFAULT_STACK_SIZE ? sz : DEFAULT_STACK_SIZE;
	ps->base = (DataType*)malloc(sizeof(DataType)*(ps->capacity));
	assert(ps->base != NULL);
	ps->top = 0;
}

void StackPush(stack* ps, DataType x)//ѹջ����
{
	if (StackIsFull(ps))
	{
		printf("ջ������������ջ��\n");
		return;
	}
	ps->base[ps->top] = x;
	ps->top++;
}

void StackShow(stack* ps)//��ӡջ
{
	int i = ps->top-1;
	for (i = ps->top - 1; i >= 0; --i)
	{
		printf("%d\n", ps->base[i]);
	}
	printf("\n");
}

void StackPop(stack* ps)//��ջ����
{
	if (StackIsEmpty(ps))
	{
		printf("ջ�ѿգ����ܳ�ջ��\n");
		return;
	}
	ps->top--;
}

DataType StackTop(stack* ps)//ȡջ��
{
	if (StackIsEmpty(ps))
	{
		printf("ջ�ѿգ�����ȡջ����\n");
		return 0;
	}
	return ps->base[ps->top - 1];
}

void StackClear(stack* ps)//���ջ
{
	ps->top = 0;
}

void StackDestroy(stack* ps)//����ջ
{
	free(ps->base);
	ps->base = NULL;
	ps->capacity = ps->top = 0;
}
