#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"


void CheckCapacity(Contact* pcon)
{
	if (pcon->sz == pcon->capacity)
	{
		//����
		PeoInfo* ptr = (PeoInfo*)realloc(pcon->data, (pcon->capacity + 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pcon->data = ptr;
			pcon->capacity += 2;
			printf("���ݳɹ�\n");
		}
	}
}

void LoadContact(Contact* pcon)
{
	FILE* pfRead = fopen("contact.dat", "r");
	int i = 0;
	PeoInfo tmp = { 0 };
	if (pfRead == NULL)
	{
		printf("�����ļ�ʧ��\n");
		return;
	}
	//���ļ�
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(pcon);
		pcon->data[pcon->sz] = tmp;
		pcon->sz++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(Contact* pcon)
{
	assert(pcon);
	pcon->sz = 0;
	pcon->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (pcon->data == NULL)
	{
		return;
	}
	//memset
	memset(pcon->data, 0, DEFAULT_SZ*sizeof(PeoInfo));
	pcon->capacity = DEFAULT_SZ;
	//�����ļ�������
	LoadContact(pcon);
}

void AddContact(Contact* pcon)
{
	assert(pcon);
	CheckCapacity(pcon);

	printf("����������:>");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("����������:>");
	scanf("%d", &(pcon->data[pcon->sz].age));
	printf("�������Ա�:>");
	scanf("%s", (pcon->data[pcon->sz].sex));
	printf("������绰:>");
	scanf("%s", (pcon->data[pcon->sz].tele));
	printf("�������ַ:>");
	scanf("%s", (pcon->data[pcon->sz].addr));
	pcon->sz++;
	printf("��ӳɹ�\n");

}

void ShowContact(const Contact* pcon)
{
	int i = 0;
	//����  �Ա�   ����   �绰    ��ַ
	printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i<pcon->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%12s\t%20s\n",
			pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}

static int FindEntry(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i<pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	//û�ҵ�
	return -1;
}

void DelContact(Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	int ret = 0;
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	ret = FindEntry(pcon, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ��
		int i = 0;
		for (i = ret; i<pcon->sz - 1; i++)
		{
			pcon->data[i] = pcon->data[i + 1];
		}
		pcon->sz--;
		printf("ɾ���ɹ�\n");
	}
}

void SaveContact(Contact* pcon)
{
	FILE* pfWrite = fopen("contact.dat", "w");
	int i = 0;
	if (pfWrite == NULL)
	{
		printf("�����ļ�ʧ��\n");
		return;
	}
	//д�ļ�
	for (i = 0; i<pcon->sz; i++)
	{
		fwrite(pcon->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}
void DestoryContact(Contact* pcon)
{
	assert(pcon);
	if (pcon->data != NULL)
	{
		//�����ļ�
		SaveContact(pcon);
		free(pcon->data);
		pcon->data = NULL;
	}
}