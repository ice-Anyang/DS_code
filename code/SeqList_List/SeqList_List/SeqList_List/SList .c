#include"SList.h"

void SListPrint(SList* plist)
{
	SListNode* cur;
	assert(plist);
	
	cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}

	printf("NULL\n");
}

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;

	return node;
}


void SListPushBack(SList* plist, SLTDataType x)
{
	SListNode* tail;
	assert(plist);

	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		tail = plist->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}

		tail->_next = BuySListNode(x);
	}
}

void SListPopBack(SList* plist)
{
	SListNode* prev, *tail;
	assert(plist);

	prev = NULL;
	tail = plist->_head;

	if (tail->_next == NULL)
	{
		free(tail);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}

		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode* newnode;
	assert(plist);

	newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPopFront(SList* plist)
{
	SListNode* next;
	assert(plist);

	next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}


SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
			return cur;

		cur = cur->_next;
	}

	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* next, *newnode;
	assert(pos);

	next = pos->_next;
	newnode = BuySListNode(x);
	// pos newnode next
	pos->_next = newnode;
	newnode->_next = next;
}

void SListEraseAfter(SListNode* pos)
{	
	SListNode* next;
	assert(pos);
	if (pos->_next == NULL)
		return;

	next = pos->_next;
	pos->_next = next->_next;
	free(next);
	next = NULL;
}

void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}

	SListNode* prev;
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

//void TestSList()
//{
//	SList sl;
//	SListInit(&sl);
//	SListPushFront(&sl, -1);
//	SListPushBack(&sl, 1);
//	SListPushBack(&sl, 2);
//	SListPushBack(&sl, 3);
//	SListPushFront(&sl, 0);
//	SListPrint(&sl);
//
//	SListPopBack(&sl);
//	SListPopBack(&sl);
//	SListPopBack(&sl);
//	SListPopFront(&sl);
//	SListPrint(&sl);
//
//	SListNode* pos = SListFind(&s1, )
//	SListInsertAfter();
//
//	//SListDestory(&sl);
//}

void TestSList()
{
	SList sl;
	SListInit(&sl);
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPrint(&sl);

	SListNode* pos = SListFind(&sl, 2);
	SListInsertAfter(pos, 20);
	SListPrint(&sl);
	SListEraseAfter(pos);
	SListPrint(&sl);

	SListRemove(&sl, 3);
	SListRemove(&sl, 2);
	SListRemove(&sl, 1);
	SListPrint(&sl);

	SListDestory(&sl);
}