#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>


#define DataType int
#define DEFAULT_HEAP_SIZE 15


typedef struct Heap
{
	DataType *base;
	size_t    capacity;
	size_t    size;
}Heap;

void HeapInit(Heap* pth,int sz);//��ʼ��
void HeapDestroy(Heap* pth);//�ݻٶ�
bool HeapPush(Heap* pth, DataType x);//��������
void AdjustUp(Heap* pth, int start);//���ϵ���С��
void HeapShow(Heap* pth);//��ʾС��
bool HeapTop(Heap* pth, DataType *ret);//ȡ�Ѷ�
bool HeapPop(Heap* pth);//ɾ���Ѷ�
void AdjustDown(Heap* pth, int end);//���µ���С��
void HeapSort(Heap* pth);//������


#endif/*_HEAP_H_*/