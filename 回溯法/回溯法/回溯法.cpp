#define _CRT_SECURE_NO_WARNINGS 
/*回溯法求解比例问题
#include<iostream>
using namespace std;

int result[9] = { 0 };
int used[9] = { 0 };
int a, b, c;
void dfs(int count);
int main()
{
	dfs(0);
	system("pause");
	return 0;
}
void dfs(int count)//回溯法专业名字
{

	if (count == 9)//出口
	{
		a = result[0] * 100 + result[1] * 10 + result[2];
		b = result[3] * 100 + result[4] * 10 + result[5];
		c = result[6] * 100 + result[7] * 10 + result[8];
		if (a * 2 == b && a * 3 == c)
		{
			cout << a << " " << b << " " << c << endl;
		}
	}
	else {
		for (int i = 0; i < 9; ++i)//入口参数
		{
			if (used[i] == 0)   //没有使用过                                            
			{
				used[i] = 1;//使用掉
				result[count] = i + 1;//记录结果数组
				int temp = count + 1;
				dfs(temp);
				used[i] = 0;
			}
		}
	}
}
*/
//求全排列问题
/*#include<stdio.h>
#include<Windows.h>
int n, i[5], r = 5;
bool mark(int x[], int y)
{
	for (int j = 0; j < y - 1; j++)
		for (int k = j + 1; k < y; k++)
			if (x[j] == x[k])
				return false;
	return true;
}
int main()
{
	scanf("%d", &n);
	for (i[0] = 1; i[0] <= n; i[0]++)
		for (i[1] = 1; i[1] <= n; i[1]++)
			for (i[2] = 1; i[2] <= n; i[2]++)
				for (i[3] = 1; i[3] <= n; i[3]++)
					for (i[4] = 1; i[4] <= n; i[4]++)
						if (mark(i, r))
						{
							for (int j = 0; j < r; j++)
								printf("%d ", i[j]);
							printf("\n");
						}
	system("pause");
	return 0;
}
#include<cstdio>
int n, r, num[10000];
bool mark[10000]; //判断该数是否使用过的数组
void print()
{
	for (int i = 1; i <= r; i++)
		printf("%d ", num[i]);
	printf("\n");
}
void search(int x)       //回溯过程
{
	for (int i = 1; i <= n; i++)
		if (!mark[i])   //判断该数是否使用过
		{
			num[x] = i;   //存储结果
			mark[i] = true; //标记该数
			if (x == r) print(); //判断是否已有r个数，输出
			search(x + 1);
			mark[i] = false; //回溯
		}
}
int main()
{
	scanf("%d%d", &n, &r);
	search(1);
}
*/
