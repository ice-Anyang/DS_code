#define _CRT_SECURE_NO_WARNINGS 1
#include"bstree.h"

int main()
{
	int arr[] = { 54, 23, 76, 25, 34, 5, 7, 11, 9, 5, 2, 70 };
	int k = sizeof(arr) / sizeof(arr[0]);
	BSTree BST;
	BSTreeInit(&BST);
	for (int i = 0; i < k; ++i)
	{
		BSTreeInser(&BST,arr[i]);
	}
	BSTreeMin(&BST);
	BSTreeMax(&BST);
	BSTreeFind(&BST, 70);
	system("pause");
	return 0;
}