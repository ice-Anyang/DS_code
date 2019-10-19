#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
int main()
{
	SeqList myList;
	SeqListInit(&myList, DEFAULT_SIZE);//��ʼ��˳���
	int select = 1;
	DataType tem;
	int pos, index;
	bool flag;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_pos    [9] delete_val *\n");
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
			printf("������Ҫ��������ݣ�>");
			while (scanf("%d", &tem), tem != -1)
			{
				SeqListPushBack(&myList, tem);
			}
			break;
		case 2:
			printf("������Ҫ��������ݣ�>");
			while (scanf("%d", &tem), tem != -1)
			{
				SeqListPushFront(&myList, tem);
			}
			break;
		case 3:
			SeqListShow(&myList);
			break;
		case 4:
			SeqListPopBack(&myList);
			break;
		case 5:
			SeqListPopFront(&myList);
			break;
		case 6:
			printf("������Ҫ��ѯ��λ��:>");
			scanf("%d", &pos);
			printf("Ҫ��ѯ������:%d\n", SeqListFindByPos(&myList, pos));
			break;
		case 7:
			printf("������Ҫ��ѯ������:>");
			scanf("%d", &tem);
			index = SeqListFindByVal(&myList, tem);
			if (index == -1)
				printf("Ҫ��ѯ������%d������.\n", tem);
			else
				printf("Ҫ��ѯ���ݵ��±�Ϊ:>%d\n", index);
			break;
		case 8:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &tem);
			flag = SeqListInsertByPos(&myList, pos, tem);
			if (flag)
				printf("����ɹ�.\n");
			else
				printf("����ʧ��.\n");
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &tem);
			flag = SeqListEraseByVal(&myList, tem);
			if (flag)
				printf("ɾ��%d�ɹ�.\n", tem);
			else
				printf("ɾ��%dʧ��.\n", tem);
			break;
		case 10:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			flag = SeqListEraseByPos(&myList, pos);
			if (flag)
				printf("ɾ���ɹ�.\n");
			else
				printf("ɾ��ʧ��.\n");
			break;
		case 11:
			printf("SeqList Length = %d\n", SeqListLength(&myList));
			break;
		case 12:
			printf("������Ҫɾ��������:>");
			scanf("%d", &tem);
			SeqListRemoveAll(&myList, tem);
			break;
		case 13:
			SeqListReverse(&myList);
			break;
		case 14:
			SeqListSort(&myList);
			break;
		case 15:
			SeqListClear(&myList);
			break;
		default:
			break;
		}
	}

	SeqListDestroy(&myList);
	return 0;
}