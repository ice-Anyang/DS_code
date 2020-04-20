#define _CRT_SECURE_NO_WARNINGS 1
#include"bintree.h"


void BinTreeInit(BinTree* pbt)//初始化
{
	pbt->rool = NULL;
}

void CreatBinTree(BinTree* pbt)//创建
{
	CreatBinTree_1(&pbt->rool);
	/*CreatBinTree_2();*/
}

void CreatBinTree_1(BinTreeNode** p)//传地址
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
		*p = NULL;
	else
	{
		*p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*p != NULL);
		(*p)->data = item;
		CreatBinTree_1(&(*p)->leftChild);
		CreatBinTree_1(&(*p)->rightChild);
	}
}

//BinTreeNode* CreatBinTree_2()
//{
//	DataType item;
//	scanf("%c", &item);
//	if (item = '#')
//		return NULL;
//	else
//	{
//		BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(p != NULL);
//		p->data = item;
//		p->leftChild = CreatBinTree_2();
//		p->rightChild = CreatBinTree_2();
//		return p;
//	}
//}

//void CreatBinTree(BinTree *pbt, char *str)
//{
//	CreatBinTree_3(&pbt->rool, str);
//}
//void CreatBinTree_3(BinTreeNode **p, char *str)
//{
//	if (*str == '\0')
//		return;
//	if (*str == '#')
//		*p = NULL;
//	else
//	{
//		*p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(*p != NULL);
//		(*p)->data = *str;
//		CreatBinTree_3(&(*p)->leftChild, ++str);
//		CreatBinTree_3(&(*p)->rightChild, ++str);
//	}
//}


void PreOrder(BinTree *pbt)
{
	PreOrder_1(pbt->rool);
}
void PreOrder_1(BinTreeNode *p)
{
	if (p != NULL)
	{
		printf("%c ", p->data);
		PreOrder_1(p->leftChild);
		PreOrder_1(p->rightChild);
	}
}
void InOrder(BinTree *pbt)
{
	InOrder_1(pbt->rool);
}
void InOrder_1(BinTreeNode *p)
{
	if (p != NULL)
	{
		InOrder_1(p->leftChild);
		printf("%c ", p->data);
		InOrder_1(p->rightChild);
	}
}
void PosOrder(BinTree *pbt)
{
	PosOrder_1(pbt->rool);
}
void PosOrder_1(BinTreeNode *p)
{
	if (p != NULL)
	{
		PosOrder_1(p->leftChild);
		PosOrder_1(p->rightChild);
		printf("%c ", p->data);
	}
}
//void LevelOrder(BinTree *pbt)
//{
//   LevelOrder_1(LevelOrder_1);
//	
//}
//void LevelOrder_1(BinTreeNode *p)
//{
//
//
//}

size_t Size(BinTree* pbt)
{
	return Size_1(pbt->rool);
}
size_t Size_1(BinTreeNode* p)
{
	if (p == NULL)
		return 0;
	else
		return Size_1(p->leftChild) + Size_1(p->rightChild) + 1;
}

size_t Height(BinTree* pbt)
{
	return Height_1(pbt->rool);
}
size_t Height_1(BinTreeNode* p)
{
	if (p == NULL)
		return 0;
	else
	{
		size_t lift_H = Height_1(p->leftChild);
		size_t right_H = Height_1(p->rightChild);
		return (lift_H > right_H ? lift_H : right_H) + 1;
	}
}

BinTreeNode* BinTreeFind(BinTree* pbt, DataType key)
{
	BinTreeNode_1(pbt->rool, key);
}
BinTreeNode* BinTreeFind_1(BinTreeNode* p, DataType key)
{
	BinTreeNode* q;
	if (p == NULL)
		return NULL;	
	if (p->data == key)
		return p;
	q = BinTreeFind_1(p->leftChild, key);
	if (q == NULL)
		return q;
	return BinTreeFind_1(p->rightChild, key);
}

BinTreeNode* Parent(BinTree* pbt, DataType key)
{
	return Parent_1(pbt->rool, key);
}
BinTreeNode* Parent_1(BinTreeNode* p, DataType key)
{
	BinTreeNode* q;
	if (p == NULL && p->data == key)
		return NULL;
	if (p->leftChild == key || p->rightChild == key)
		return p;
	q = Parent_1(p->leftChild, key);
	if (q != NULL)
		return q;
	return Parent_1(p->rightChild, key);
}

void Copy(BinTree* pbt, BinTree* pbt1)
{
	Copy_1(pbt->rool, &pbt1->rool);
}

void Copy_1(BinTreeNode* p1, BinTreeNode** p2)
{
	if (p1 == NULL)
		*p2 == NULL;
	else
	{
		*p2 = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*p2 != NULL);
		(*p2)->data = p1->data;
		Copy_1(p1->leftChild, &(*p2)->leftChild);
		Copy_1(p1->rightChild, &(*p2)->rightChild);
	}
}

bool Equal(BinTree* pbt, BinTree* pt1)
{
	return Equal_1(pbt->rool, pbt->rool);
}

bool Equal_1(BinTreeNode* p1, BinTreeNode* p2)
{
	if (p1 == NULL && p2 == NULL)
		return true;
	if (p1 != NULL && p2 != NULL
		&& p1->data == p2->data
		&& Equal_1(p1->leftChild, p2->rightChild)
		&& Equal_1(p1->rightChild, p2->leftChild))
		return true;
	return false;
}
