#pragma once
#include <string.h>

#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}


void TestShellSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
				max = i;

			if (a[i] < a[min])
				min = i;
		}

		Swap(&a[begin], &a[min]);
		if (begin == max)
			max = min;

		Swap(&a[end], &a[max]);
		++begin;
		--end;

		//PrintArray(a, n);
	}
}

void TestSelectSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		if (child+1 < n 
			&& a[child+1] > a[child]) {
			++child;
		}

		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	assert(a);

	// 建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void BubbleSort(int* a, int n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// []

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin > mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}

int PartSort1(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		// end 找小
		while (begin < end && a[end] >= key)
			--end;

		// begin找大
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[start]);
	return begin;
}

int PartSort2(int* a, int begin, int end)
{
	//begin是坑
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;

		// end给begin这个坑，end就变成了新的坑。
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
			++begin;

		// end给begin这个坑，begin就变成了新的坑。
		a[end] = a[begin];
	}

	a[begin] = key;

	return begin;
}

int PartSort3(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;

	while (cur <= end)
	{
		// cur找小，把小的往前翻，大的往后翻
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[begin], &a[prev]);

	return prev;
}

// []
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a+left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		//[left, div-1]
		//[div+1, right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

void QuickSortR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st, 10);
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}

	while (StackEmpty(&st) != 0)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);

		int div = PartSort1(a, left, right);
		// [left div-1]
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}

		// [div+1, right]
		if (div+1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}

}

void TestQuickSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSortR(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);

	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a+left, tmp+left, sizeof(int)*(right - left+1));
}


void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// O(Max(N, 范围))
// O(N+范围) 时间复杂度
// O(范围) 空间复杂度
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int* countArray = (int*)malloc(range*sizeof(int));
	memset(countArray, 0, sizeof(int)*range);

	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < range; ++i)
	{	
		while (countArray[i]--)
		{
			a[index++] = i+min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 3, 4, 6, 2, 8, 5, 2, 2, 9, 9, 1000000, 99999};
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSortOP()
{
	const int n = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	int* a5 = (int*)malloc(sizeof(int)*n);
	int* a6 = (int*)malloc(sizeof(int)*n);
	int* a7 = (int*)malloc(sizeof(int)*n);
	int* a8 = (int*)malloc(sizeof(int)*(n+1));

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	a8[n] = 100000000;

	size_t begin1 = clock();
	//InsertSort(a1, n);
	size_t end1 = clock();
	printf("%u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("%u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("%u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("%u\n", end4 - begin4);
	
	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("%u\n", end5 - begin5);

	size_t begin6 = clock();
	QuickSort(a6, 0, n-1);
	size_t end6 = clock();
	printf("%u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("%u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n+1);
	size_t end8 = clock();
	printf("%u\n", end8 - begin8);
}
