#define _CRT_SECURE_NO_WARNINGS 1
#include"bstree.h"

void BSTreeInit(BSTree* ps)
{
	ps->root = NULL;
}

bool BSTreeInser(BSTree* ps,BSTDataType x)
{
	return BSTreeInser_1(&ps->root, x);
}
bool BSTreeInser_1(BSTNode** p,BSTDataType x)
{
	if (*p == NULL)
	{
		*p = (BSTNode*)malloc(sizeof(BSTNode));
		(*p)->data = x;
		(*p)->leftChild = NULL;
		(*p)->rightChild = NULL;
		return true;
	}
	else if (x < (*p)->data)
	{
		BSTreeInser_1(&(*p)->leftChild, x);
	}
	else if (x >(*p)->data)
	{
		BSTreeInser_1(&(*p)->rightChild, x);
	}
	else
		return false;
}

BSTNode* BSTreeMin(BSTree* ps)
{
	return BSTreeMin_1(ps->root);
}

BSTNode* BSTreeMin_1(BSTNode* p)
{
	if (p == NULL)
		return p;
	
	while (p->leftChild == NULL)
	{
		p = p->leftChild;
	}
	return p;
}

BSTNode* BSTreeMax(BSTree* ps)
{
	return BSTreeMax_1(ps->root);
}

BSTNode* BSTreeMax_1(BSTNode* p)
{
	if (p == NULL)
		return p;
	while (p->rightChild == NULL)
	{
		p = p->rightChild;
	}
	return p;
}

BSTNode* BSTreeFind(BSTree* ps, BSTDataType key)
{
	return BSTreeFind_1(ps->root, key);
}

BSTNode* BSTreeFind_1(BSTNode* p, BSTDataType key)
{
	if (p == NULL)
		return NULL;
	if (p->data == key)
		return p;
	else if (p->data < key)
		return BSTreeFind_1(p->rightChild, key);
	else
		return BSTreeFind_1(p->leftChild, key);
}

BSTNode* BSTreeErase(BSTree* ps, BSTDataType key)
{
	return BSTreeErase(&ps->root, key);
}

BSTNode* BSTreeErase_1(BSTNode** p, BSTDataType key)
{
	if (*p == NULL)
		return false;
	if (key < (*p)->data)
		BSTerrErase_1(&(*p)->leftChild, key);
	else if (key >(*p)->data)
		BSTreeErase_1(&(*p)->rightChild, key);
	else
	{
		if ((*p)->leftChild == NULL && (*p)->rightChild == NULL)
		{
			free(*p);
			*p = NULL;
		}
		else
		{

		}
	}
	return true;
}