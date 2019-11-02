#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

int main()
{
	int arr[] = { 5, 7, 2, 3, 8, 4, 6, 5, 10, 9 };
	int sz = sizeof(arr) / sizeof(int);
	TestSort(arr, 0, sz - 1);
	system("pause");
	return 0;
}