#define _CRT_SECURE_NO_WARNINGS 1
#include"sclist.h"


static SCListNode* _Buynode(DataType x)
{
	SCListNode *s = (SCListNode *)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SCListInit(SCList *plist)
{
	SCListNode* s = _Buynode(0);
	plist->first = plist->last=s;
	s->next = plist->first;
	plist->size = 0;
}

void SCListPushBack(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode* s = _Buynode(x);
	plist->last->next = s;
	plist->last = s;
	s->next = plist->first;
	plist->size++;
}

void SCListPushFront(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode* s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void SCListShow(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

SCListNode* SCListFindByVal(SCList* plist, DataType key)
{
	assert(plist != NULL);
	SCListNode* p = plist->first->next;
	while (p->next != plist->first && p->data != key)
		p = p->next;
	return p;
}

bool SCListEraseByVal(SCList *plist, DataType key)
{
	assert(plist != NULL);
	SCListNode* p = NULL;
	SCListNode* q = NULL;
	p = SCListFindByVal(plist, key);
	if (p = NULL)
		return false;
	q = plist->first;
	while (q->next != plist->first)
	{
		q = q->next;
		q->next = p->next;
	}
	if (p = plist->last)
	{
		plist->last = q;
		q->next = p->next;
	}
	free(p);
	plist->size--;
}

size_t SListLength(SCList *plist)
{
	return plist->size;
}
//链表要求有序
bool SCListInsertByVal(SCList *plist, DataType x)
{
	assert(plist);
	SCListNode *s = _Buynode(x);

	SCListNode *p = plist->first;
	while (p->next != plist->first && p->next->data < x)
		p = p->next;

	if (p->next =plist->first) //尾部插入
	{
		plist->last = s;
		s->next = plist->first;
	}
	else
		s->next = p->next;
	p->next = s;

	plist->size++;
	return true;
}

void SCListReverse(SCList* plist)
{
	SCListNode *p, *q;
	p = plist->first->next;
	q = p->next;

	plist->last = p;
	plist->last->next = plist->first;

	while (q != plist->first)
	{
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
	}

}


void SCListClear(SCList *plist)
{
	SCListNode* p = plist->first->next;
	if (plist->size == 0)
		return;
	while (p != plist->first)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void SCListDestroy(SCList *plist)
{
	SCListClear(plist);
	free(plist->first);
	plist->first = NULL;
	plist->last = NULL;
	plist->size = 0;
}










