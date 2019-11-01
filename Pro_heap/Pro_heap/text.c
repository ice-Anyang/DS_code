#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

int main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(int);
	Heap hp;
	DataType ret;
	HeapInit(&hp,DEFAULT_HEAP_SIZE);

	for (int i = 0; i < n; ++i)
	{
		HeapPush(&hp, arr[i]);  
	}
	HeapShow(&hp);
	HeapTop(&hp, &ret);
	printf("Heap Top = %d\n", ret);

	//HeapPop(&hp);
	HeapShow(&hp);
	HeapTop(&hp, &ret);
	printf("Heap Top = %d\n", ret);
	HeapSort(&hp);

	//HeapDestroy(&hp);
	system("pause");
	return 0;
}