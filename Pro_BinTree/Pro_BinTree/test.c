#define _CRT_SECURE_NO_WARNINGS 1
#include"bintree.h"

int main()
{
	BinTree bt;
	BinTree bt1;
	size_t p = 0;
	//char *VLR = "ABCDEFGH";
	//char *LVR = "CBEDFAGH";
	//char *LRV = "CEFDBHGA";
	char *str = "ABC##DE##F##G#H##";
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	CreatBinTree(&bt);
	/*CreatBinTree(&bt, str);*/
	PreOrder(&bt);
	printf("\n");
	InOrder(&bt);
	printf("\n");
	PosOrder(&bt);
	printf("\n");
	/*LevelOrder(&bt);*/
	p = Size(&bt);
	printf("%d\n", p);
	p = Height(&bt);
	printf("%d\n", p);

	BinTreeFind(&bt, 'H');
	Parent(&bt, 'C');
	Copy(&bt, &bt1);
	bool flag = Equal(&bt, &bt1);

	system("pause");
	return 0;
}