#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

bool _Inc(SeqList *ps)//�ڲ�����
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

void Swap(DataType *a, DataType *b)//��������
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

bool SeqListIsFull(SeqList *ps)//�ж�˳����Ƿ�����
{
	if (ps->size >= ps->capacity)
		return true;
	return true;
}

bool SeqListIsEmpty(SeqList *ps)//�ж�˳����ǲ���Ϊ��
{
	if (ps->size == 0)
		return true;
	return false;
}

void SeqListInit(SeqList* ps, size_t capacity)//��ʼ��
{
	ps->base = (DataType*)malloc(sizeof(DataType)*capacity);
	assert(ps->base != NULL);
	ps->capacity = capacity;
	ps->size = 0;
}

void SeqListPushBack(SeqList* ps, DataType x)//β����
{
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("˳�������,�޷�����\n");
		return;
	}
	ps->base[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, DataType x)//ͷ����
{
	int i = 0;
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("˳�������,�޷�����\n");
		return 0;
	}
	for (i = ps->size - 1; i > 0; --i)
	{
		ps->base[i] = ps->base[i - 1];
	}
	ps->base[0] = x;
	ps->size++;
}

void SeqListShow(SeqList *ps)//��ӡ˳���
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d", ps->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList *ps)//�Ӻ��ɾ��
{
	if (SeqListIsEmpty(ps));
	{
		printf("˳����ѿգ��޷�ɾ��\n");
		return;
	}
	ps->size--;
}

void SeqListPopFront(SeqList *ps)//��ǰ��ɾ��
{
	if (SeqListIsEmpty(ps))
	{
		printf("˳����������޷�ɾ��\n");
		return;
	}
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->base[i] = ps->base[i + 1];
	}
	ps->size--;
}

DataType SeqListFindByPos(SeqList* ps, int pos)//ͨ��λ�ò���
{
	if (pos < 0 || pos >= ps->size)
	{
		printf("���ҵ�λ����Ч\n");
		return -1;
	}
	return ps->base[pos];
}

int SeqListFindByVal(SeqList *ps, DataType key)//ͨ�����ݲ���
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

bool SeqListInsertByPos(SeqList *ps, int pos, DataType x)//ָ��λ�ò���
{
	int i = 0;
	if (pos<0 || pos > ps->size)
	{
		printf("λ������\n");
		return false;
	}
	if (SeqListIsFull(ps) && !_Inc(ps))
	{
		printf("˳���ռ�����,%d���ܲ���.\n", x);
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

bool SeqListEraseByPos(SeqList *ps, int pos)//ָ��λ��ɾ��
{
	int i = 0;
	if (SeqListIsEmpty(ps))
		return false;
	for (i = pos; i < ps->size; i++)
		ps->base[pos] = ps->base[pos + 1];
	ps->size--;
	return true;
}

bool SeqListEraseByVal(SeqList *ps, DataType key)//ɾ��ָ������
{
	int index = SeqListFindByVal(ps, key);//�ҵ�λ��
	if (index == -1)
		return false;
	return SeqListEraseByPos(ps, index);//ɾ��

}

size_t SeqListLength(SeqList *ps)//��˳�����
{
	return ps->size;
}

void SeqListRemoveAll(SeqList* ps, DataType x)//ɾ����������
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

void SeqListReverse(SeqList *ps)//��������
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

void SeqListSort(SeqList *ps)//ð������
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