#include"IMS.h"

// 
int main()
{
	Stu* res = NULL;
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("退出学生管理系统\n");
			break;
		case 1:
			system("cls");
			res = build();
			_flushall();
			break;
		case 2:
			change(res);
			_flushall();
			system("cls");
			break;
		case 3:
			myinsert(res);
			_flushall();
			system("cls");
			break;
		case 4:
			system("cls");//清屏命令
			mydelete(res);
			_flushall();//清理内存缓冲区   scanf   回车
			break;
		case 5:
			system("cls");
			Recover_mis_delete(res);
			_flushall();
			break;
		case 6:
			system("cls");
			out(res);
			break;
		case 7:
			system("cls");
			save(res);
			_flushall();
			break;
		case 8:
			system("cls");
			buildbyfile();
			_flushall();
			break;
		case 9:
			system("cls");
			mysearch(res);
			_flushall();
			break;
		default:
			system("cls");
			printf("输入有误请重新输入：\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
