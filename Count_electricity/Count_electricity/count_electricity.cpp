#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>//����
#include<stdbool.h>
#include<string.h>


int main()
{
	int num;
	printf("��ѡ��-> ����1 ��ʼʹ��\n");
	while (scanf("%d", &num), num == 1)
	{
		system("color 4");
		printf("     ***********************************************************************     \n");
		printf("  ***********************************��ӭʹ��************************************   \n");
		printf("     ***********************************************************************     \n");
		//Ϊ�˱��ⳬ��Χ���������ַ�����
		char account_Number[50];//�˻�
		double account_Quantity;
		printf("�����������˺�\n");
		scanf("%s", account_Number);
		printf("�����������õ���\n");
		scanf("%lf", &account_Quantity);
		printf("�����˺���:%s\n", account_Number);
		if (account_Quantity <= 180)
		{
			printf("���ĵ���ǣ�%lf\n", 0.56*account_Quantity);
		}
		else if (account_Quantity > 180 && account_Quantity < 260)
		{
			printf("���ĵ���ǣ�%lf\n", 0.61*account_Quantity);
		}
		else if (account_Quantity > 260)
		{
			printf("���ĵ���ǣ�%lf\n", 0.86*account_Quantity);
		}
		printf("��ѡ��-> ����1����ʹ�ã������˳�\n");
	}
	
	system("pause");
	return 0;
}