#ifndef  _CONTACT_H_
#define  _CONTACT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT
};
//ͨѶ¼�����Ϣ  ���� �Ա� ����  �绰 סַ

#define NAME_MAX  20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

#define DEFAULT_SZ 3
#define MAX 1000


typedef struct PeoInfo
{
	char name[NAME_MAX];
	short age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//ͨѶ¼�Ľṹ��
//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;//��Ч��Ϣ�ĸ���
//}Contact;

//��̬�����汾
typedef struct Contact
{
	PeoInfo *data;
	int sz;//��Ч��Ϣ�ĸ���
	int capacity;//��ǰ��������
}Contact;

void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
void DestoryContact(Contact* pcon);
void SaveContact(Contact* pcon);
void LoadContact(Contact* pcon);




#endif/*CONTACT_H_*/
