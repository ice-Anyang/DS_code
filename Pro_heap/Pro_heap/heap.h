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

void HeapInit(Heap* pth,int sz);//初始化
void HeapDestroy(Heap* pth);//摧毁堆
bool HeapPush(Heap* pth, DataType x);//放入数据
void AdjustUp(Heap* pth, int start);//向上调整小堆
void HeapShow(Heap* pth);//显示小堆
bool HeapTop(Heap* pth, DataType *ret);//取堆顶
bool HeapPop(Heap* pth);//删除堆顶
void AdjustDown(Heap* pth, int end);//向下调整小堆
void HeapSort(Heap* pth);//堆排序


#endif/*_HEAP_H_*/