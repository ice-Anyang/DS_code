#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType char

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* rool;

}BinTree;


void BinTreeInit(BinTree* pbt);
void CreatBinTree(BinTree* pbt);
void CreatBinTree_1(BinTreeNode** p);
//BinTreeNode* CreatBinTree_2();
//void CreatBinTree(BinTree* pbt, char* str);
//void CreatBinTree_3(BinTreeNode **p, char *str);

void PreOrder(BinTree *pbt);
void PreOrder_1(BinTreeNode *p);
void InOrder(BinTree *pbt);
void InOrder_1(BinTreeNode *p);
void PosOrder(BinTree *pbt);
void PosOrder_1(BinTreeNode *p);
//void LevelOrder(BinTree *pbt);
//void LevelOrder_1(BinTreeNode *p);

size_t Size(BinTree* pbt);
size_t Size_1(BinTreeNode* p);
size_t Height(BinTree* pbt);
size_t Height_1(BinTreeNode* p);
BinTreeNode* BinTreeFind(BinTree* pbt, DataType key);
BinTreeNode* BinTreeFind_1(BinTreeNode* p, DataType key);
BinTreeNode* Parent(BinTree* pbt, DataType key);
BinTreeNode* Parent_1(BinTreeNode* p, DataType key);

void Copy(BinTree* pbt, BinTree* pbt1);
void Copy_1(BinTreeNode* p1, BinTreeNode** p2);

bool Equal(BinTree* pbt, BinTree* pt1);
bool Equal_1(BinTreeNode* p1, BinTreeNode* p2);




#endif/*_BINTREE_H_*/