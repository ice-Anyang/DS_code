#ifndef _SORT_H_
#define _SORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define DataType int 
#define M 3

void Swap(int* a, int* b);
void TestSort(int *arr,int left,int right);

//��������
void InsertSort_1(int *arr, int left, int right);//ֱ�Ӳ�������
void InsertSort_2(int *arr, int left, int right);//
void InsertSort_3(int *arr, int left, int right);//�ڱ���������
void BinInsertSort(int *arr, int left, int right);//�����������
void TwoWayInsertSort(int *arr, int left, int right);//��·��������
void ShellSort(int *arr, int left, int right);//ϣ������ 

 //ѡ������
void SelectSort(int *arr, int left, int right);//ֱ��ѡ������
void HeapSort(int *ar, int left, int right);// ������

//��������
void BubbleSort(int *arr, int left, int right);//ð������
void QuickSort(int *arr, int left, int right); //��������












#endif/*_SORT_H_*/