#include "common.h"

typedef int STDataType;
typedef struct Satck
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
// �� 0 �ǿ�1
int StackEmpty(Stack* ps);

void StackTest();
