#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

static bool HeapIsFull(Heap* pth)
{
	return pth->size >= pth->capacity;
}
static bool HeapIsEmpty(Heap* pth)
{
	return pth->size == 0;
}

static Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

void HeapInit(Heap* pth, int sz)//��ʼ��
{
	pth->capacity = sz > DEFAULT_HEAP_SIZE ? sz : DEFAULT_HEAP_SIZE;
	pth->base = (DataType*)malloc(sizeof(DataType)*(pth->capacity));
	pth->size = 0;
}


void HeapDestroy(Heap* pth)//�ݻٶ�
{
	free(pth->base);
	pth->base = NULL;
	pth->capacity = pth->size = 0;
}

//void AdjustUp(Heap* pth, int start)//���ϵ�����С��
//{
//	int j = start;//����ڵ�
//	int i = (j - 1) / 2;//���ڵ��±�
//
//	while (i >= 0)
//	{
//		if (pth->base[j] < pth->base[i])
//		{
//			Swap(&pth->base[j], &pth->base[i]);
//			j = i;
//			i = (j - 1) / 2;
//		}
//		else
//			break;
//	}
//}
void AdjustUp(Heap* pth, int start)//���ϵ�����С��
{
	int j = start;//����ڵ�
	int i = (j - 1) / 2;//���ڵ��±�
	DataType tem = pth->base[j];
	while (j > 0)
	{
		if (tem <pth->base[i])
		{
			//Swap(&pth->base[j], &pth->base[i]);
			pth->base[j] = pth->base[i];
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	pth->base[j] = tem;
}

bool HeapPush(Heap* pth, DataType x)//��������
{
	if (HeapIsFull(pth))
		return false;
	pth->base[pth->size] = x;
	//����
	AdjustUp(pth, pth->size);
	pth->size++;
	return true;
}

void HeapShow(Heap* pth)//��ʾ
{
	for(int i = 0; i < pth->size; ++i)
	{
		printf("%d ", pth->base[i]);
	}
	printf("\n");
}

bool HeapTop(Heap* pth, DataType *ret)//ȡ��Ԫ��
{
	if (HeapIsEmpty(pth))
		return false;
	*ret = pth->base[0];
	return true;
}
void AdjustDown(Heap* pth, int end)//���µ���С��
{
	int i = 0;
	int j = 2 * i + 1;
	while (j <= end)
	{
		if (j <=end - 1 && pth->base[j]>pth->base[j + 1])
			j = j + 1;
		if (pth->base[i] > pth->base[j])
		{
			Swap(&(pth->base[i]), &(pth->base[j]));
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
bool HeapPop(Heap* pth)
{
	if (HeapIsEmpty(pth))
		return false;

	pth->size--;
	pth->base[0] = pth->base[pth->size];

	AdjustDown(pth, pth->size-1);

	return true;
}
void HeapSort(Heap* pth)//����
{
	int ret = 0;
	while (!HeapIsEmpty(pth))
	{
		HeapTop(pth, &ret);
		printf("%d ", ret);
		HeapPop(pth);
	}
}


