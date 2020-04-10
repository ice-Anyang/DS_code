#define _CRT_SECURE_NO_WARNINGS 1

#include"dclist.h"

static DCListNode* _Buynode(DataType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode*));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}

void DCListInit(DCList* plist)
{
	DCListNode* s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList* plist,DataType x)
{
	DCListNode* s = _Buynode(x);
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size++;
}

void DCListPushFront(DCList* plist, DataType x)
{
	DCListNode* s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;
	s->prev = plist->first;
	s->next->prev = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void DCListShow(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over\n");
}

void DCListPopBack(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->last;
	plist->last = p->prev;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;
}

void DCListPopFront(DCList* plist)
{
	DCListNode* p = plist->first->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	if (p == plist->first)
		plist->last = plist->first;
	free(p);
	plist->size--;
}




