#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define BSTDataType int 

typedef struct BSTNode
{
	BSTDataType data;
	struct BSTNode*  leftChild;
	struct BSTNode*  rightChild;
}BSTNode;

typedef struct BSTree
{
	BSTNode* root;
}BSTree;

void BSTreeInit(BSTree* ps);
bool BSTreeInser(BSTree* ps,BSTDataType x);
bool BSTreeInser_1(BSTNode** p,BSTDataType x);
BSTNode* BSTreeMin(BSTree* ps);
BSTNode* BSTreeMin_1(BSTNode* p);
BSTNode* BSTreeMax(BSTree* ps);
BSTNode* BSTreeMax_1(BSTNode* p);
BSTNode* BSTreeFind(BSTree* ps, BSTDataType key);
BSTNode* BSTreeFind_1(BSTNode** p, BSTDataType key);





#endif /*_BSTREE_H_*/