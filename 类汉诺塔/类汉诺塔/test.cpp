#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>
using namespace std;
/*
	ģ��ʵ�֣�1������ɫ��2�����ɫ��3�����ɫ
	ÿ�������ϲ�����5��  ˳�����
	Ҫ�����ʹ������ÿ����������ͬ
	1,2,3,  row 1
	2,1,3,  row 2
	1,3,2   row 3
	�涨 ��һ��ȫ��1 �ڶ���ȫ�� 2  ������ȫ�� 3 �ƶ����㲽��
	     .........2  ............1  ..........3 ���㲽��
	��1 2 3 ȫ����һ�� �ҳ�������̵�
	�ݹ�˼�룺 ���г���һ�� 
	           ��һ�㲻һ�����г��ڶ���
			   ���г�������
			   ÿһ�в�����5
			   ������ʾ��������
			   ÿ�ο�һ��
*/

bool JudgeNotEqual(int a, int b, int c)
{
	if (a != b && b != c && a != c)
	{
		return true;
	}
}
static int count = 0;
void move(char a, char b)
{
	cout << a << "-->" << b;
}
//��¼���� level
void Judge(int arr[3][3],int level,char A,char B,char C)
{
	if (level == 0)
		return;
	if (level == 3 && JudgeNotEqual(arr[level - 1][0], arr[level - 1][1], arr[level - 1][2]))//�ײ㲻����Ϊ����
	{
		Judge(arr[3][3], level - 1, A, B, C);
	}
	else
	{

	}

}

int main()
{
	int arr[3][3] = { 1,2,3,2,1,3,1,3,2 };

	system("pause");
	return 0;
}







/*
#include<stdio.h>
#include<stdlib.h>
static int count = 0;
void move(char getone, char putone) {

	count++;
	printf("%c-->%c\n", getone, putone);
}

void hanoit(int n, char a, char b, char c) {
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoit(n - 1, a, c, b);
		printf("count :%d\n", count);
		move(a, c);
		hanoit(n - 1, b, a, c);
	}

}

int main() {
	int m;

	scanf("%d", &m); //���뼸�㺺ŵ��
	hanoit(m, 'A', 'B', 'C');
	printf("count :%d", count);

	system("pause");
	return 0;
}
*/