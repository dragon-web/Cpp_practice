#define _CRT_SECURE_NO_WARNINGS 
/*
#include<iostream>
#include<time.h>
#include<cstdio>
using namespace std;

#include<iostream>
using namespace std;
const int MAX = 10000 + 5;
int fib[MAX];
int dfs(int n) {

	if (fib[n] != -1) 
		return fib[n];
	return fib[n] = dfs(n - 1) + dfs(n - 2);
}
int main()
{
	fib[1] = fib[2] = 1;
	for (int i = 2; i < MAX; i++) {
		fib[i] = -1;
	}
	dfs(MAX - 1);//别写成了MAX，那样输出的全是-1 
	for (int i = 1; i <= 50; i++) {
		printf("%d ", fib[i]);
		if (i % 5 == 0) {
			printf("\n");
		}//
	}
	system("pause");
	return 0;
}

int Fabi(int x)
{
	if (x == 1)
		return 0;
	if (x == 2)
	{
		return 1;
	}
	else
	{
		return Fabi(x - 1) + Fabi(x - 2);
	}
}

int main()
{
	clock_t begin, end;
	double durction;
	begin = clock();
	Fabi(30);
	end = clock();
	durction = (double)(end - begin)/ CLOCKS_PER_SEC;
	cout << durction << endl;
	system("pause");
	return 0;
}*/
/*
对于状态的存储，可用数组num[a][b][c][d]，
其中a为还剩几个，b为找到了哪几个，c为找到的最后一个数，
d表示是否已经出现1，4相连的两数
//记忆化搜索=搜索的形式+动态规划的思想
*/


//求出二维数组坐标(x,y)的最大值。 

/*int f(int x, int y) {
	if (x == n)return a[x][y];
	return  a[x][y] + (max(f(x + 1, y), f(x + 1, y + 1))> f(x - 1, y+1), f(x + 1, y + 1)?);
}
*/

//递归的思路
/*
1 
2 3
4 5 6
7 8 9 5

#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int arr[100][100];
int getmax(int a, int b, int c)
{
	int max = a;
	max = a > b ? a : b;
	max = max > c ? max : c;
	return max;
}
int getmax(int a, int b)
{
	return a > b ? a : b;
}
int Solution(int row)   //row 行  col 列  
{
	int Answer;
	int temp;
	int R = 0;
	int C = 0; //R当前行数 C 当前列数
	while (R < row-1)
	{
		int Num = R + 1;//当前的列数的最大值
		if (C==0)
		if (C == 0&&Num!=0)
		{
			 temp = getmax(arr[R + 1][C + 1] + arr[R][C + 1], arr[R + 1][C]);
			Answer += temp;
		}
			if (C < Num - 1 && C > 0)
			{
			 temp = getmax(arr[R+1][C], arr[R + 1][C + 1]+ arr[R][C+1], arr[R][C - 1] + arr[R + 1][C - 1]);
				Answer += temp;
			}
			if (C == Num - 1&& C!=0)
			{
				temp = getmax(arr[R + 1][C - 1]+ arr[R][C-1], arr[R + 1][C]);
			}
		
		R++;
	}
	return Answer;
}

int main() 
{
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = Solution(i);
	cout << ans << endl;
	return 0;
	system("pause");
}
*/


/*
#include<iostream>
using namespace std;
int main()
{

	int a;
	int *p = &a;
	printf("请输入一个整数：");
	scanf("%d", &a);
	printf("a=%d\n", a);
	printf("请重新输入一个整数：");
	scanf("%d", p);//p本来存放a的地址
	printf("a=%d\n", a);
	system("pause");
	return 0;
}
*/