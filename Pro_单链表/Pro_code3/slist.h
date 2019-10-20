#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType int

typedef struct SListNode
{
	DataType data;
	struct SListNode *next; //link
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t     size;
}SList;

void SListInit(SList* plist);//初始化
void SListPushBack(SList *plist, DataType x);//尾插
void SListPushFront(SList *plist, DataType x);//头插
void SListShow(SList *plist);//显示链表
void SListPopBack(SList *plist);//尾删

SListNode* SListFindByVal(SList *plist, DataType key);//按值查找
bool SListEraseByVal(SList *plist, DataType key);//删除
size_t SListLength(SList *plist);//长度
bool SListInsertByVal(SList *plist, DataType x);//插入

void SListClear(SList *plist);//清除
void SListReverse(SList *plist);//转置
void SListDestroy(SList *plist);//摧毁

#endif /* _SLIST_H_ */