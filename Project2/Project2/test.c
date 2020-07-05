#define _CRT_SECURE_NO_WARNINGS 

/*
#include<stdio.h>
#include<Windows.h>
#include<math.h>

/*int main()
{
	int i, j;
	int arr[] = { 4,5,6,8,2,5,6,52,6,8,96};
	int temp;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; ++i)
	{
		for (j = 0; j < sz - 1 - i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}*/
//阶梯电价
/*
int main()
{
	int ele;
	float cost;
	printf("请输入用电量");
	scanf("%d", &ele);
	if (ele < 0)
	{
		printf("Invalid Value!");
	}
	else if (ele <= 50)
	{
		cost = 0.53*ele;
		printf("cost = %.2f", cost);
	}
	else if (ele > 50)
	{
		cost = 50 * 0.53 + (ele - 50)*(0.53 + 0.05);
		printf("cost = %.2f", cost);
	}
	system("pause");
	return 0;
}
*/

//幂级数展开和
/*
int JC(int c)
{
	int sum = 1;
	int i = 1;
	for (i = 1; i <= c; ++i)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int a = 5;
	double x;
	int i = 1;
	double j = 0.0;
	printf("请输入一个实数");
	double res = 0;
	scanf("%lf", &x);
	while (fabs(pow(x, j) / JC(i)) < 0.00001)
	{
		res += pow(x, j) / JC(i);
		i++;
		j++;
	}
	printf("%.4lf", res);
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double fun(double x, double n)//求数列每一项的值
{
	double ret = 0;
	double  i = 0;
	double num = 1;
	//求分母：即阶乘
	for (i = 1; i <= n; i++)
	{
		num = num * i;
	}
	ret = pow(x, n) / num;//数列每一项的值
	return ret;
}
int main()
{
	double x = 0;
	double sum = 0;
	double n = 0;
	scanf("%lf", &x);
	do
	{
		sum = sum + fun(x, n);
		n++;

	} while (fabs(fun(x, n)) >= 0.00001);
	sum = sum + fun(x, n);
	printf("%.4f\n", sum);
	return 0;

}

#include <stdio.h>
#include<malloc.h>
int main()
{
	int N, M;
	int *Array;
	scanf("%d %d", &N, &M);
	Array = (int *)malloc(sizeof(int)*(N + 1));
	for (int i = 1; i <= N; ++i)
		scanf("%d", &Array[i]);
	M = M % N;
	for (int i = M + 1; i <= N; i++) {
		if (i == M + 1)
			printf("%d", Array[i]);
		else
			printf(" %d", Array[i]);
	}
	for (int i = 1; i <= M; i++)
		printf(" %d", Array[i]);
	return 0;
}
#include <stdio.h> 
struct student 
{ 
	char name[10];
	int birth;
	char phone[17];
}stu[10], stu1; 
int main()
{
	int i, j, n; 
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
		scanf("%s %d %s", stu[i].name, &stu[i].birth, stu[i].phone);
	for (i = 0; i < n - 1; i++)
	{ for (j = 0; j < n - i - 1; j++)
	{ if (stu[j].birth > stu[j+1].birth)
	{ stu1 = stu[j]; stu[j] = stu[j+1]; 
	stu[j+1] = stu1;} } }
	for (i = 0; i < n; i++)
		printf("%s %d %s\n", stu[i].name, stu[i].birth, stu[i].phone);
	return 0; 
}
*/
#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *fp;
	int i;
	char c, str1[100];

	printf("input string endwith enter:\n");
	gets(str1);

	fp = fopen("letter.txt", "w");
	if (fp == NULL) { printf("File open faild!"); exit(0); }
	for (i = 0; str1[i] != '\0'; i++)
	{
		fputc(str1[i], fp);
	}
	fclose(fp);

	fp = fopen("letter.txt", "r");
	if (fp == NULL)
	{ printf("File open faild!"); exit(0); }

	fclose(fp);
	getchar();
}