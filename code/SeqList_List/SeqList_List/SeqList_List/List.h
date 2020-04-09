#pragma once
#include"common.h"

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// ˫���ͷѭ��
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

// ��pos֮ǰ���в���
void ListInsert(ListNode* pos, LTDataType x); 
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
ListNode* ListFind(List* plist, LTDataType x);

void ListPrint(List* plist);
void ListTest();


