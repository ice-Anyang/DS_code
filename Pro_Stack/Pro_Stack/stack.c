
#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
static bool StackIsFull(stack *pst)
{
	return pst->top >= pst->capacity;
}
static bool StackIsEmpty(stack *pst)
{
	return pst->top == 0;
}

void StackInit(stack* ps, size_t sz)
{
	ps->capacity = sz > DEFAULT_STACK_SIZE ? sz : DEFAULT_STACK_SIZE;
	ps->base = (DataType*)malloc(sizeof(DataType)*(ps->capacity));
	assert(ps->base != NULL);
	ps->top = 0;
}

void StackPush(stack* ps, DataType x)
{
	if (StackIsFull(ps))
	{
		printf("栈已满，不能入栈。\n");
		return;
	}
	ps->base[ps->top] = x;
	ps->top++;
}

void StackShow(stack* ps)
{
	int i = ps->top-1;
	for (i = ps->top - 1; i >= 0; --i)
	{
		printf("%d\n", ps->base[i]);
	}
	printf("\n");
}

void StackPop(stack* ps)
{
	if (StackIsEmpty(ps))
	{
		printf("栈已空，不能出栈。\n");
		return;
	}
	ps->top--;
}

DataType StackTop(stack* ps)
{
	if (StackIsEmpty(ps))
	{
		printf("栈已空，不能取栈顶。\n");
		return 0;
	}
	return ps->base[ps->top - 1];
}

void StackClear(stack* ps)
{
	ps->top = 0;
}

void StackDestroy(stack* ps)
{
	free(ps->base);
	ps->base = NULL;
	ps->capacity = ps->top = 0;
}
