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

//²åÈëÅÅĞò
void InsertSort_1(int *arr, int left, int right);//Ö±½Ó²åÈëÅÅĞò
void InsertSort_2(int *arr, int left, int right);//
void InsertSort_3(int *arr, int left, int right);//ÉÚ±ø²åÈëÅÅĞò
void BinInsertSort(int *arr, int left, int right);//¶ş²æ²éÕÒÅÅĞò
void TwoWayInsertSort(int *arr, int left, int right);//Á½Â·²åÈëÅÅĞò
void ShellSort(int *arr, int left, int right);//Ï£¶ûÅÅĞò 

 //Ñ¡ÔñÅÅĞò
void SelectSort(int *arr, int left, int right);//Ö±½ÓÑ¡ÔñÅÅĞò
void HeapSort(int *ar, int left, int right);// ¶ÑÅÅĞò

//½»»»ÅÅĞò
void BubbleSort(int *arr, int left, int right);//Ã°ÅİÅÅĞò
void QuickSort(int *arr, int left, int right); //¿ìËÙÅÅĞò












#endif/*_SORT_H_*/