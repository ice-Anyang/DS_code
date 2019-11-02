#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void Swap(DataType* a, DataType* b)
{
	DataType tem = *a;
	*a = *b;
	*b = tem;
}

//打印数组
void PrintArray(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i <= right; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//直接插入排序
void InsertSort_1(int *arr,int left,int right)
{
	int i = 0;
	for (i = left + 1; i <= right; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= left && key < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end+1] = key;
	}
}

// 直接插入，调用Swap函数
void InsertSort_2(int *arr, int left, int right)
{
	int i = left + 1;
	for (i = left + 1; i <= right; ++i)
	{
		int end = i - 1;
		while (end >= left && arr[end + 1] < arr[end])
		{
			Swap(&arr[end + 1], &arr[end]);
			end--;
		}
	}
}

//直接插入排序 哨兵位
void InsertSort_3(int *arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		//哨兵位
		arr[0] = arr[i];
		int end = i - 1;
		while (arr[0] < arr[end]) //
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = arr[0];
	}
}

//二分查找插入
void BinInsertSort(int *arr, int left, int right)
{
	int low, high, mid;
	int tem, j;
	for (int i = left+1; i <= right; i++)
	{
		low = left;
		high = i - 1;
		tem = arr[i];
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (tem < arr[mid])
				high =mid - 1;
			if (tem >= arr[mid])
				low = mid + 1;
		}
		for (j = i; j > low; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[low] = tem;
	}
}

//二路插入排序
void TwoWayInsertSort(int *arr, int left, int right)
{
	int n = right - left + 1;
	int *tem = (int*)malloc(sizeof(int)*n);

	tem[0] = arr[left];
	int start, final;
	start = final = 0;
	int key = 0;
	for (int i = left + 1; i <= right; ++i)
	{
		key = arr[i];
		if (key < tem[start])
		{
			start = (start - 1 + n) % n;
			tem[start] = key;
		}
		else if (key > tem[final])
		{
			final++;
			tem[final] = key;
		}
		else
		{
			int end = final;
			final++;
			while (key < tem[end])
			{
				tem[(end + 1) % n] = tem[end];
				end = (end - 1 + n) % n;
			}
			tem[(end + 1) % n] = key;
		}
	}
	for (int i = 0; i<n; ++i)
	{
		arr[i] = tem[start];
		start = (start + 1) % n;
	}
	free(tem);
}

//希尔排序
void ShellSort(int *arr, int left, int right)
{
	int gap = right - left + 1;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = left; i <= right-gap; ++i)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= left && tem<arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tem;
		}
	}
}

//直接选择排序
static int GetMinIndex(int *arr, int left, int right)
{
	int index = left;
	int min = arr[left];
	for (int i = left + 1; i <= right; ++i)
	{
		if (min > arr[i])
		{
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void SelectSort(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i < right; i++)
	{
		int index = GetMinIndex(arr, i, right);
		if (index != i)
		{
			Swap(&arr[index], &arr[i]);
		}
	}
}

//堆排序
static void AdjustDown(int *arr, int n, int start)//形成大堆
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j+1 < n && arr[j] <arr[j + 1])
			j++;
		if (arr[i] < arr[j])
		{
			Swap(&arr[i], &arr[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

void HeapSort(int *arr, int left, int right)
{
	int n = right - left + 1;
	int cur = (n - 1) / 2;
	while (cur > left)
	{
		AdjustDown(arr, n, cur);
		cur--;
	}
	//PrintArray(ar, left, right);
	//Sort
	int end = right;
	while (end >= left)
	{
		Swap(&arr[left], &arr[end]);
		AdjustDown(arr, end - left, 0);
		end--;
	}
}

void BubbleSort(int *arr, int left, int right)//冒泡排序
{
	
	for (int i = left; i < right; ++i)
	{
		bool inser = false;
		for (int j = left; j < right - i; ++j)
		{
			if (arr[j]>arr[j+1])
				Swap(&arr[j], &arr[j+1]);
				inser = true;
		}
		if (!inser)
			break;
	}
}

int Partition(int* arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left<right && arr[right] >= key)
			right--;
		Swap(&arr[left], &arr[right]);
		while (left<right && arr[left]<key)
			left++;
		Swap(&arr[left], &arr[right]);
	}
	return left;
}

void QuickSort(int *arr, int left, int right) //快速排序
{
	if (left >= right)
		return;
	if (right - left + 1 <= M)
		InsertSort_1(arr, left, right);
	else
	{
		int pos = Partition(arr, left, right);
		QuickSort(arr, left, pos - 1);
		QuickSort(arr, pos + 1, right);
	}
}

//归并排序
void _MergeSort(int *ar, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);

	int begin1 = left; //左区间 [left,mid]
	int end1 = mid;
	int begin2 = mid + 1;//右区间[mid+1, right]
	int end2 = right;

	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}

	while (begin1 <= end1)
		tmp[i++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[i++] = ar[begin2++];

	memcpy(ar + left, tmp + left, sizeof(int)*(right - left + 1));
}

void MergeSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(ar, left, right, tmp);

	free(tmp);
}

////基数排序
//#include"slist.h"
//#define K 4
//SList list[10];
//
//int GetKeyOfValue(int value, int k)
//{
//	int key;
//	while (k >= 0) //232  k=1
//	{
//		key = value % 10;
//		value /= 10;
//		k--;
//	}
//	return key;
//}
//
//void Distribute(int *ar, int left, int right, int k)
//{
//	int key;
//	for (int i = 0; i<10; ++i)
//	{
//		SListClear(&list[i]);
//	}
//	for (int i = left; i <= right; ++i)
//	{
//		key = GetKeyOfValue(ar[i], k);
//		SListPushBack(&list[key], ar[i]);
//	}
//}
//void Collect(int *ar, int left, int right)
//{
//	int k = left;
//	SListNode *p;
//	for (int i = 0; i<10; ++i)
//	{
//		p = list[i].first->next;
//		while (p != NULL)
//		{
//			ar[k++] = p->data;
//			p = p->next;
//		}
//	}
//}
//void RadixSort(int *ar, int left, int right)
//{
//	for (int i = 0; i<10; ++i)
//	{
//		SListInit(&list[i]);
//	}
//	for (int i = 0; i<K; ++i)
//	{
//		Distribute(ar, left, right, i);
//		Collect(ar, left, right);
//	}
//}



void TestSort(int *arr, int left, int right)
{
	//InsertSort_1(arr, left, right);
	//InsertSort_2(arr, left, right);
	//InsertSort_3(arr, left, right);
	//BinInsertSort(arr, left, right);
	//TwoWayInsertSort(arr, left, right);
	//ShellSort(arr, left, right);
	//SelectSort(arr, left, right);
	//HeapSort(arr, left, right);
	//BubbleSort(arr, left, right);
	//QuickSort(arr, left, right);
	MergeSort(arr, left, right);
	PrintArray(arr, left, right);
}
