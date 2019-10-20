#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include"slist.h"

static SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)//��ʼ������
{
	SListNode* s = _Buynode(0);
	plist->first = s;
	plist->last = s;
	plist->size = 0;
}

void SListPushBack(SList *plist, DataType x)//β��
{
	assert(plist != NULL);
	SListNode* s = _Buynode(x);
	s->next=plist->first->next;
	plist->first->next = s;
	plist->last = s;
	plist->size++;
}

void SListShow(SList *plist)//��ӡ
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
void SListPushFront(SList *plist, DataType x)//ͷ��
{
	assert(plist != NULL);
	SListNode* s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void SListPopBack(SList *plist)//βɾ
{
	assert(plist != NULL);
	SListNode* p = plist->first->next;
	while (p->next->next != NULL)
		p->next;
	free(p->next);
	p->next = NULL;
	plist->last = p;
	plist->size--;
}

SListNode* SListFindByVal(SList *plist, DataType key)//����
{
	assert(plist != NULL);
	SListNode* p = plist->first->next;
	while (p!=NULL && p->data != key)
		p->next;
	return p;
}

bool SListEraseByVal(SList *plist, DataType key)//ɾ��
{
	assert(plist != NULL);
	SListNode *p, *q;
	p = SListFindByVal(plist, key);
	if (p == NULL)
		return false;

	q = p->next;
	if (q == plist->last)
		plist->last = p;
	p->data = q->data;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}

size_t SListLength(SList *plist)//����
{
	return plist->size;
}

bool SListInsertByVal(SList *plist, DataType x)//����
{
	assert(plist);
	SListNode* s = _Buynode(x);

	SListNode* p = plist->first;
	while (p->next != NULL && p->next->data < x)
		p = p->next;
	if (p->next == 0)
	{
		plist->last = s;
		p->next = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
	return true;
}

void SListClear(SList *plist)//���
{
	SListNode *p = plist->first->next;
	if (plist->size == 0)
		return;

	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}

	plist->last = plist->first;
	plist->size = 0;
}

void SListReverse(SList *plist)
{
	SListNode *p, *q;
	p = plist->first->next;
	q = p->next;

	plist->last = p;
	plist->last->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
	}
}

void SListDestroy(SList *plist)//��յ�����
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}



