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
	dfs(MAX - 1);//��д����MAX�����������ȫ��-1 
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
����״̬�Ĵ洢����������num[a][b][c][d]��
����aΪ��ʣ������bΪ�ҵ����ļ�����cΪ�ҵ������һ������
d��ʾ�Ƿ��Ѿ�����1��4����������
//���仯����=��������ʽ+��̬�滮��˼��
*/


//�����ά��������(x,y)�����ֵ�� 

/*int f(int x, int y) {
	if (x == n)return a[x][y];
	return  a[x][y] + (max(f(x + 1, y), f(x + 1, y + 1))> f(x - 1, y+1), f(x + 1, y + 1)?);
}
*/

//�ݹ��˼·
/*
1
2 3
4 5 6
7 8 9 5
*/
/*
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
int Solution(int row)   //row ��  col ��  
{
	int Answer = 0;
	int temp;
	int R = 0;
	int C = 0; //R��ǰ���� C ��ǰ����
	if (C == 0 && R == 0)
	{
		Answer += arr[0][0];
		R++;
	}
	while (R < row - 1)
	{

		int Num = R;//��ǰ��������Ӧ���������ֵ-1 ��0��ʼ

		if (C == 0 && R != 0)//������ڵ�һ���Ҳ��ǵ�һ��
		{
			temp = getmax(arr[R + 1][C + 1] + arr[R][C + 1], arr[R + 1][C]) + arr[R][0];
			//����C��ֵ
			if (temp == arr[R + 1][C + 1] + arr[R][C + 1] + arr[R][0])
			{
				C++;
			}
			if (temp == arr[R + 1][C] + arr[R][0] + arr[R][0]);
			Answer += temp;
		}
			if (C < Num && C > 0)
			{
			 temp = getmax(arr[R+1][C], arr[R + 1][C + 1]+ arr[R][C+1], arr[R][C - 1] + arr[R + 1][C - 1]);
				Answer += temp;
			}
			if (C == Num && C!=0)
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
	cout << "����������" << endl;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = Solution(i);
	cout << "���·����"<<ans << endl;
	system("pause");
	return 0;
}

*/


/*
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int a[1001][1001], n;

//�����ά��������(x,y)�����ֵ�� 

int f(int x, int y) {
	if (x == n)
	return a[x][y];
	int temp;
	return  a[x][y] +
(temp = max(f(x + 1, y), f(x + 1, y + 1)) > max(f(x + 1, y), f(x + 1, y + 1)) 
	? max(f(x + 1, y), f(x + 1, y + 1)) : 
	max(f(x + 1, y), f(x + 1, y + 1)));
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << f(1, 1);
	system("pause");
	return 0;
}
*/

/*#include<iostream>
#include<algorithm>
#define maxn 100 
using namespace std;

int a[maxn][maxn], N, total, did[maxn][maxn];

int f(int i, int j) {
	if (i == N - 1)
		return a[i][j];
	if (did[i][j])
		return did[i][j];
	did[i][j] = a[i][j] + max(f(i + 1, j), f(i + 1, j + 1));
	return did[i][j];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << f(0, 0);
}
*/




































/*
#include<iostream>
using namespace std;
int main()
{

	int a;
	int *p = &a;
	printf("������һ��������");
	scanf("%d", &a);
	printf("a=%d\n", a);
	printf("����������һ��������");
	scanf("%d", p);//p�������a�ĵ�ַ
	printf("a=%d\n", a);
	system("pause");
	return 0;
}
*/