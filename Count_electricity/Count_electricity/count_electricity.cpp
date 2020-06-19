#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>//断言
#include<stdbool.h>
#include<string.h>


int main()
{
	int num;
	printf("请选择-> 输入1 开始使用\n");
	while (scanf("%d", &num), num == 1)
	{
		system("color 4");
		printf("     ***********************************************************************     \n");
		printf("  ***********************************欢迎使用************************************   \n");
		printf("     ***********************************************************************     \n");
		//为了避免超范围，我们用字符数组
		char account_Number[50];//账户
		double account_Quantity;
		printf("请输入您的账号\n");
		scanf("%s", account_Number);
		printf("请输入您的用电量\n");
		scanf("%lf", &account_Quantity);
		printf("您的账号是:%s\n", account_Number);
		if (account_Quantity <= 180)
		{
			printf("您的电费是：%lf\n", 0.56*account_Quantity);
		}
		else if (account_Quantity > 180 && account_Quantity < 260)
		{
			printf("您的电费是：%lf\n", 0.61*account_Quantity);
		}
		else if (account_Quantity > 260)
		{
			printf("您的电费是：%lf\n", 0.86*account_Quantity);
		}
		printf("请选择-> 输入1继续使用，其他退出\n");
	}
	
	system("pause");
	return 0;
}