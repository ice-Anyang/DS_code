#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(sizeof(STDataType)*3);
	assert(ps->_a);

	ps->_top = 0;
	ps->_capacity = 3;
}

void StackDestory(Stack* ps)
{
	assert(ps);

	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*(ps->_capacity*2));
		assert(ps->_a);

		ps->_capacity *= 2;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);

	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps->_a && ps->_top > 0);

	return ps->_a[ps->_top-1];

}

// ¿Õ 0
// ·Ç¿Õ 1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

//void TestStack()
//{
//	Stack s;
//	StackInit(&s);
//	
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//
//	while (StackEmpty(&s))
//	{
//		printf("%d ", StackTop(&s));
//		StackPop(&s);
//	}
//
//	printf("\n");
//
//	StackDestory(&s);
//}