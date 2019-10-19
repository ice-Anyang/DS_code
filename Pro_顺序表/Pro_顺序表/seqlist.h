#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType int
#define DEFAULT_SIZE 8
#define INC_SIZE   3

typedef struct	SeqList
{
	DataType *base;
	size_t  capacity;
	size_t  size;//³¤¶È
}SeqList;

bool SeqListIsFull(SeqList *ps);
bool SeqListIsEmpty(SeqList *ps);
void SeqListInit(SeqList* ps, size_t capacity);
void SeqListPushBack(SeqList* ps, DataType x);
void SeqListPushFront(SeqList* ps, DataType x);
void SeqListShow(SeqList *ps);

void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);
size_t SeqListLength(SeqList *ps);
void SeqListClear(SeqList *ps);
DataType SeqListFindByPos(SeqList *ps, int pos);
int SeqListFindByVal(SeqList *ps, DataType key);

bool SeqListEraseByVal(SeqList *ps, DataType key);
bool SeqListEraseByPos(SeqList *ps, int pos);
bool SeqListInsertByPos(SeqList *ps, int pos, DataType x);
void SeqListReverse(SeqList *ps);

void SeqListRemoveAll(SeqList* ps, DataType x);
void SeqListSort(SeqList *ps);
void SeqListDestroy(SeqList *ps);

void Swap(DataType *a, DataType *b);


#endif /* _COMMON_H_ */