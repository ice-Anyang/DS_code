#ifndef _HASH_H_
#define _HASH_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define P 7
#define DataType int 

typedef struct HashNode
{
	DataType data;
	struct bucket_node* next;
}HashNode;

typedef HashNode* HashTable[P];

void HashInit(HashTable pt);
bool HashInsert(HashTable pt, DataType x);
void HashShow(HashTable ht);
void HashRemove(HashTable pt, DataType x);





#endif/*_HASH_H*/