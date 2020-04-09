#include "BinaryTree.h"

#include "Queue.h"
#include "Stack.h"


BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_data = x;

	return node;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);

		++(*pi);
		root->_left = BinaryTreeCreate(a, n, pi);

		++(*pi);
		root->_right = BinaryTreeCreate(a, n, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** pptree)
{
	BTNode* root = *pptree;

	if (root == NULL)
		return;

	BinaryTreeDestory(&root->_left);
	BinaryTreeDestory(&root->_right);
	free(root);
	*pptree = NULL;
}

//int size = 0;
//void BinaryTreeSize(BTNode* root)
//{
//	if(root == NULL)
//		return;
//
//	++size;
//	BinaryTreeSize(root->_left);
//	BinaryTreeSize(root->_right);
//}

int BinaryTreeSize(BTNode* root)
{
	if(root == NULL)
		return 0;

	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right)+ 1;
}

int BinaryTreeHeight(BTNode* root)
{
	int leftHeight, rightHeight;
	if (root == NULL)
	{
		return 0;
	}

	leftHeight = BinaryTreeHeight(root->_left);
	rightHeight = BinaryTreeHeight(root->_right);

	return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL
		&& root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k-1)
		+ BinaryTreeLevelKSize(root->_right, k-1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
		return NULL;

	if (root->_data == x)
		return root;

	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;

	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;

	return NULL;
}

// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (QueueEmpty(&q) != 0)
	{
		QUDataType front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);

		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}

		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}

	printf("\n");
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
	}

	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}

	return 0;
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack s;
	BTNode* top;

	StackInit(&s);

	while(cur || StackEmpty(&s) != 0)
	{
		// 访问左路节点，左路节点进栈
		while(cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);

			cur = cur->_left;
		}

		// 栈里面出来节点，表示左树已经访问过了
		top = StackTop(&s);
		StackPop(&s);

		// 子问题访问所有右子树
		cur = top->_right;
	}

	printf("\n");
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack s;
	BTNode* top;
	BTNode* cur = root;
	StackInit(&s);

	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		// 左树已经访问过了
		// 还剩根及右树
		top = StackTop(&s);
		StackPop(&s);
		printf("%c ", top->_data);

		cur = top->_right;
	}

	printf("\n");
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack s;
	BTNode* top, *prev;
	BTNode* cur = root;
	StackInit(&s);

	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}

		top = StackTop(&s);

		// 右为空 || 上一个访问的节点就是我右子树的根
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}

	printf("\n");

}

void TestBinaryTree()
{
	BTNode* ret;
	char array[] = {'A', 'B', 'D', '#', '#', 'X', '#', '#', 'C',
		'E', '#', '#', 'F', '#', '#'};
	size_t i = 0;
	BTNode* tree = BinaryTreeCreate(array, sizeof(array)/sizeof(BTDataType), &i);

	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreePrevOrderNonR(tree);

	BinaryTreeInOrder(tree);
	printf("\n");

	BinaryTreeInOrderNonR(tree);

	BinaryTreePostOrder(tree);
	printf("\n");

	BinaryTreePostOrderNonR(tree);

	BinaryTreeLevelOrder(tree);
	printf("\n");
	
	ret = BinaryTreeFind(tree, 'E');
	printf("%c\n", ret->_data);

	ret = BinaryTreeFind(tree, 'X');
	printf("%p\n", ret);

	printf("Height?%d\n", BinaryTreeHeight(tree));
	printf("Size?%d\n", BinaryTreeSize(tree));

	printf("Complete?:%d\n", BinaryTreeComplete(tree));

	BinaryTreeDestory(&tree);
}
