#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>
using namespace std;
/*
	模拟实现：1代表蓝色，2代表黑色，3代表黄色
	每根柱子上不超过5个  顺序随机
	要求最短使得数据每根柱子上相同
	1,2,3,  row 1
	2,1,3,  row 2
	1,3,2   row 3
	规定 第一行全是1 第二行全是 2  第三行全是 3 移动计算步数
	     .........2  ............1  ..........3 计算步数
	把1 2 3 全排列一下 找出步数最短的
	递归思想： 排列出第一层 
	           第一层不一致排列出第二层
			   排列出第三层
			   每一列不超过5
			   列来表示塔的容量
			   每次看一列
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
//记录层数 level
void Judge(int arr[3][3],int level,char A,char B,char C)
{
	if (level == 0)
		return;
	if (level == 3 && JudgeNotEqual(arr[level - 1][0], arr[level - 1][1], arr[level - 1][2]))//底层不等作为基底
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

	scanf("%d", &m); //输入几层汉诺塔
	hanoit(m, 'A', 'B', 'C');
	printf("count :%d", count);

	system("pause");
	return 0;
}
*/