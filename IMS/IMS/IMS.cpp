#include"IMS.h"

// 
int main()
{
	Stu* res = NULL;
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("�˳�ѧ������ϵͳ\n");
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
			system("cls");//��������
			mydelete(res);
			_flushall();//�����ڴ滺����   scanf   �س�
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
			printf("�����������������룺\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
