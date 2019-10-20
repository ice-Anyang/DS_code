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

void SListInit(SList* plist);//��ʼ��
void SListPushBack(SList *plist, DataType x);//β��
void SListPushFront(SList *plist, DataType x);//ͷ��
void SListShow(SList *plist);//��ʾ����
void SListPopBack(SList *plist);//βɾ

SListNode* SListFindByVal(SList *plist, DataType key);//��ֵ����
bool SListEraseByVal(SList *plist, DataType key);//ɾ��
size_t SListLength(SList *plist);//����
bool SListInsertByVal(SList *plist, DataType x);//����

void SListClear(SList *plist);//���
void SListReverse(SList *plist);//ת��
void SListDestroy(SList *plist);//�ݻ�

#endif /* _SLIST_H_ */