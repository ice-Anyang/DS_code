#ifndef _DCLIST_H_
#define _DCLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define DataType int

typedef struct DCListNode
{
	DataType data;
	struct  DCListNode* prev;
	struct  DCListNode* next;
}DCListNode;

typedef struct DCList
{
	DCListNode* first;
	DCListNode* last;
	size_t      size;
}DCList;


void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist,DataType x);
void DCListPushFront(DCList* plist, DataType x);
void DCListShow(DCList* plist);

void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);




#endif /*_DCLIST_H_*/
