#define _CRT_SECURE_NO_WARNINGS 1
#include"hash.h"

int main()
{
	int arr[] = { 5, 12, 15, 22, 45, 26, 31, 20 };
	int n = sizeof(arr) / sizeof(int);
	HashTable ht;
	HashInit(ht);
	for (int i = 0; i < P; ++i)
	{
		HashInsert(ht,arr[i]);
	}
	HashShow(ht);
	HashRemove(ht, 45);
	HashShow(ht);
	system("pause");
	return 0;
}