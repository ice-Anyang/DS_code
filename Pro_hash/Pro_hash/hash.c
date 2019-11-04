#define _CRT_SECURE_NO_WARNINGS 1
#include"hash.h"

int Hash(DataType x)
{
	return x%P;
}

void HashInit(HashTable pt)
{
	memset(pt, 0, sizeof(HashNode*)*P);
}

bool HashInsert(HashTable pt, DataType x)
{
	int index = Hash(x);
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	if (node == NULL)
		return false;
	node->data = x;
	node->next = pt[index];
	pt[index] = node;
	return true;
}

void HashShow(HashTable pt)
{
	for (int i = 0; i < P; ++i)
	{
		HashNode* p = pt[i];
		printf("%d :", i);
		while (p != NULL)
		{
			printf("%d-->", p->data);
			p = p->next;
		}
		printf("Nul.\n");
	}
}

void HashRemove(HashTable pt, DataType x)
{
	int index = Hash(x);
	HashNode *p, *q;
	p = pt[index];
	q = NULL;
	while (p != NULL && p->data != x)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return false;
	if (q == NULL)
		pt[index] = p->next;
	else
		q->next = p->next;
	free(p);
	return true;
}


