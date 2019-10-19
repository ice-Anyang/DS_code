#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
int main()
{
	SeqList myList;
	SeqListInit(&myList, DEFAULT_SIZE);//初始化顺序表
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
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据：>");
			while (scanf("%d", &tem), tem != -1)
			{
				SeqListPushBack(&myList, tem);
			}
			break;
		case 2:
			printf("请输入要插入的数据：>");
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
			printf("请输入要查询的位置:>");
			scanf("%d", &pos);
			printf("要查询的数据:%d\n", SeqListFindByPos(&myList, pos));
			break;
		case 7:
			printf("请输入要查询的数据:>");
			scanf("%d", &tem);
			index = SeqListFindByVal(&myList, tem);
			if (index == -1)
				printf("要查询的数据%d不存在.\n", tem);
			else
				printf("要查询数据的下标为:>%d\n", index);
			break;
		case 8:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &tem);
			flag = SeqListInsertByPos(&myList, pos, tem);
			if (flag)
				printf("插入成功.\n");
			else
				printf("插入失败.\n");
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &tem);
			flag = SeqListEraseByVal(&myList, tem);
			if (flag)
				printf("删除%d成功.\n", tem);
			else
				printf("删除%d失败.\n", tem);
			break;
		case 10:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			flag = SeqListEraseByPos(&myList, pos);
			if (flag)
				printf("删除成功.\n");
			else
				printf("删除失败.\n");
			break;
		case 11:
			printf("SeqList Length = %d\n", SeqListLength(&myList));
			break;
		case 12:
			printf("请输入要删除的数据:>");
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