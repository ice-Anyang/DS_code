#ifndef _SCLIST_H_
#define _SCLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define	DataType int
typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next; //link
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t     size;
}SCList;

static SCListNode* _Buynode(DataType x);
void SCListInit(SCList *plist);
void SCListPushBack(SCList *plist, DataType x);
void SCListPushFront(SCList *plist, DataType x);
void SCListShow(SCList *plist);

SCListNode* SCListFindByVal(SCList *plist, DataType key);
bool SCListEraseByVal(SCList *plist, DataType key);
size_t SCListLength(SCList *plist);
bool SCListInsertByVal(SCList *plist, DataType x);

void SCListClear(SCList *plist);
void SCListReverse(SCList *plist);
void SCListDestroy(SCList *plist);


#endif/*_SCLIST_H_*/