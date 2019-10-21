#define _CRT_SECURE_NO_WARNINGS 1
#include"sclist.h"
int main()
{
	//SeqList mylist;

	SCListNode *p = NULL;
	SCList mylist;
	SCListInit(&mylist);
	DataType item=0;
	int pos = 0;
	int index=0;
	bool flag=true;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_val    [9] delete_val *\n");
		printf("* [10] delete_pos   [11]length     *\n");
		printf("* [12] remove_all   [13] reverse   *\n");
		printf("* [14] sort         [15] clear     *\n");
		printf("************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushFront(&mylist, item);
			}
			break;
		case 3:
			SCListShow(&mylist);
			break;
		//case 4:
		//	//SeqListPopBack(&mylist);
		//	break;
		//case 5:
		//	//SeqListPopFront(&mylist);
		//	break;
		//case 6:
		//	printf("������Ҫ��ѯ��λ��:>");
		//	scanf("%d", &pos);
		//	printf("Ҫ��ѯ������:%d\n", SeqListFindByPos(&mylist, pos));
		//	break;
		case 7:
			printf("������Ҫ��ѯ������:>");
			scanf("%d", &item);
			//index = SeqListFindByVal(&mylist, item);
			p = SCListFindByVal(&mylist, item);
			if (p == NULL)
				printf("Ҫ��ѯ������%d������.\n", item);
			printf("�ڸ�������\n");
			break;
		//case 8:
		//	//printf("������Ҫ�����λ��:>");
		//	//scanf("%d", &pos);
		//	printf("������Ҫ���������:>");
		//	scanf("%d", &item);
		//	///flag = SListInsertByVal(&mylist, item);
		//	if (flag)
		//		printf("����ɹ�.\n");
		//	else
		//		printf("����ʧ��.\n");
		//	break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			/*flag = SeqListEraseByVal(&mylist, item);*/
			SCListEraseByVal(&mylist, item);
			break;
		//case 10:
		//	printf("������Ҫɾ����λ��:>");
		//	scanf("%d", &pos);
		//	//flag = SeqListEraseByPos(&mylist, pos);
		//	if (flag)
		//		printf("ɾ���ɹ�.\n");
		//	else
		//		printf("ɾ��ʧ��.\n");
		//	break;
		case 11:
			printf("SCList Length = %d\n", SCListLength(&mylist));
			break;
		//case 12:
		//	printf("������Ҫɾ��������:>");
		//	scanf("%d", &item);
		//	//SeqListRemoveAll(&mylist, item);
		//	break;
		case 13:
			SCListReverse(&mylist);
			break;
		case 14:
		//	SeqListSort(&mylist);
			break;
		case 15:
			SCListClear(&mylist);
			break;
		}
	}
	SCListDestroy(&mylist);
	return 0;
}