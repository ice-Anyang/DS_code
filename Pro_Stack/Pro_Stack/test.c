#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main()
{
	stack stc;
	StackInit(&stc, 10);
	StackPush(&stc, 1);
	StackPush(&stc, 2);
	StackPush(&stc, 3);
	StackPush(&stc, 4);
	StackShow(&stc);
	StackPop(&stc);
	StackShow(&stc);
	StackTop(&stc);
	StackShow(&stc);
	StackClear(&stc);
	StackDestroy(&stc);
	system("pause");
	return 0;
}


