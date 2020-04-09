#pragma once
#include"common.h"

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 双向带头循环
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

// 在pos之前进行插入
void ListInsert(ListNode* pos, LTDataType x); 
// 删除pos位置的节点
void ListErase(ListNode* pos);
ListNode* ListFind(List* plist, LTDataType x);

void ListPrint(List* plist);
void ListTest();


