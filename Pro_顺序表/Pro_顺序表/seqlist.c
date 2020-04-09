#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

bool _Inc(SeqList *ps)//内部函数
{
	DataType *new_base =
		(DataType *)malloc(sizeof(DataType)*(ps->capacity + INC_SIZE));
	if (new_base == NULL)
		return false;

	memcpy(new_base, ps->base, sizeof(DataType)*ps->capacity);
	free(ps->base);

	ps->base = new_base;
	ps->capacity += INC_SIZE;
	return true;
}

void Swap(DataType *a, DataType *b)//交换函数
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

bool SeqListIsFull(SeqList *ps)//判断顺序表是否满了
{
	if (ps->size >= ps->capacity)
		return true;
	return true;
}

bool SeqListIsEmpty(SeqList *ps)//判断顺序表是不是为空
{
	if (ps->size == 0)
		return true;
	return false;
}

void SeqListInit(SeqList* ps, size_t capacity)//初始化
{
	ps->base = (DataType*)malloc(sizeof(DataType)*capacity);
	assert(ps->base != NULL);
	ps->capacity = capacity;
	ps->size = 0;
}

void SeqListPushBack(SeqList* ps, DataType x)//尾插入
{
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满,无法插入\n");
		return;
	}
	ps->base[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, DataType x)//头插入
{
	int i = 0;
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满,无法插入\n");
		return 0;
	}
	for (i = ps->size - 1; i > 0; --i)
	{
		ps->base[i] = ps->base[i - 1];
	}
	ps->base[0] = x;
	ps->size++;
}

void SeqListShow(SeqList *ps)//打印顺序表。
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d", ps->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList *ps)//从后边删除
{
	if (SeqListIsEmpty(ps));
	{
		printf("顺序表已空，无法删除\n");
		return;
	}
	ps->size--;
}

void SeqListPopFront(SeqList *ps)//从前边删除
{
	if (SeqListIsEmpty(ps))
	{
		printf("顺序表已满，无法删除\n");
		return;
	}
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->base[i] = ps->base[i + 1];
	}
	ps->size--;
}

DataType SeqListFindByPos(SeqList* ps, int pos)//通过位置查找
{
	if (pos < 0 || pos >= ps->size)
	{
		printf("查找的位置无效\n");
		return -1;
	}
	return ps->base[pos];
}

int SeqListFindByVal(SeqList *ps, DataType key)//通过数据查找
{
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		if (ps->base[i] == key)
		{
			return i;
		}
	}
	return -1;
}

bool SeqListInsertByPos(SeqList *ps, int pos, DataType x)//指定位置插入
{
	int i = 0;
	if (pos<0 || pos > ps->size)
	{
		printf("位置有误\n");
		return false;
	}
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return false;
	}
	for (int i = ps->size; i >pos; --i)
	{
		ps->base[i] = ps->base[i - 1];
	}
	ps->base[pos] = x;
	ps->size++;
	return true;
}

bool SeqListEraseByPos(SeqList *ps, int pos)//指定位置删除
{
	int i = 0;
	if (SeqListIsEmpty(ps))
		return false;
	for (i = pos; i < ps->size; i++)
		ps->base[pos] = ps->base[pos + 1];
	ps->size--;
	return true;
}

bool SeqListEraseByVal(SeqList *ps, DataType key)//删除指定数字
{
	int index = SeqListFindByVal(ps, key);//找到位置
	if (index == -1)
		return false;
	return SeqListEraseByPos(ps, index);//删除

}

size_t SeqListLength(SeqList *ps)//求顺序表长度
{
	return ps->size;
}

void SeqListRemoveAll(SeqList* ps, DataType x)//删除所有数据
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (x == ps->base[i])
		for (int j = i; j < ps->size - 1; ++j)
			ps->base[j] = ps->base[j + 1];
		ps->size--;
		i--;
	}
}

void SeqListReverse(SeqList *ps)//逆序排列
{
	{
		if (ps->size >= 2)
		{
			int begin = 0;
			int end = ps->size - 1;
			while (begin < end)
			{
				Swap(&(ps->base[begin]), &(ps->base[end]));
				begin++;
				end--;
			}
		}
	}
}

void SeqListSort(SeqList *ps)//冒泡排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size; ++i)
	{
		for (j = 0; j < ps->size - 1; j++)
		{
			if (ps->base[i]>ps->base[j])
				Swap(ps->base[i], ps->base[j]);
		}
	}
}

void SeqListClear(SeqList *ps)
{
	ps->size = 0;
}

void SeqListDestroy(SeqList *ps)
{
	free(ps->base);
	ps->base = NULL;
	ps->capacity = ps->size = 0;
}