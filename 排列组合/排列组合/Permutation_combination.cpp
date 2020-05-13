#define _CRT_SECURE_NO_WARNINGS 

/*#include<iostream>
using namespace std;
//A n m这种全排列  方法 1 全排列
//permutation
//递归思路讲解
int main()
{
	//暴力穷举法 例如输出1 2 3 的全排列
/*	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3;++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (i != j && i != k && j != k)
				{
					cout << i+1<<" " << j+1<<" " << k+1 << endl;
				}
			}
		}
	}
	*/
/*
1 2 3 
1 3 2
2 1 3 
2 3 1 
3 1 2 
3 2 1

	int arr[] = { 1,2,3,4};
	int sz = sizeof(arr) / sizeof(arr[0]);
	system("pause");
	return 0;
}


#include <iostream>
#include <cstring>
#define N 100
using namespace std;

void permutation(char* a, int k, int m)
{
	int i, j;
	if (k == m)//如果说：到达了最后一位的全排列，那么就开始打印 ，不是说一个数据一个数据打印的，而是排列好再打印
	{
		for (i = 0; i <= m; i++)
			cout << a[i];
		cout << endl;
	}
	else
	{
		for (j = k; j <= m; j++)
		{
			swap(a[j], a[k]);
			permutation(a, k + 1, m);
			swap(a[j], a[k]);//换回来
		}
	}
}
int main()
{
	char a[N];
	int n;
	cin >> a;
	n = strlen(a) - 1;
	permutation(a, 0, n);
	system("pause");
	return 0;
}

#include<iostream>

using namespace std;

void permutation(int* arr, int start, int end)
{
	int i;
	int j;
	if (start == end)
	{
		for (i = 0; i <= end; ++i)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}
	else
	{
		for ( j = start; j <= end; ++j)
		{
			swap(arr[j], arr[start]);
			permutation(arr,start+1,end);
			swap(arr[start], arr[j]);
		}
	}
}
int main()
{
	int arr[] = { 1,2,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	permutation(arr, 0, sz-1);
	system("pause");
	return 0;
}
*/
//字典排序设计内容较多，先将快排三种模式巩固后再来看
//组合
//排列有序，但是组合无序

#include<iostream>
#include<vector>

using namespace std;

void Combination(vector<int> &a, vector<int> &b, int l, int m, int M)
{
	//b用于临时存储结果。len(b)==M；l为左侧游标，初始值取0；M是取出个数；m用于指示递归深度，初始值取M）
	int N = a.size();
	if (m == 0) {
		vector<int> nList;
		for (size_t i = 0; i < b.size(); ++i) {
			cout << b[i]+1 << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = l; i < N; i++) {
		b[M - m] = a[i];
		Combination(a, b, i + 1, m - 1, M);
	}
}
int main()
{
	int M = 3, N = 5;
	vector<int> a, b(M), c(N);
	for (int i = 0; i < N; ++i)
	{
		a.push_back(i);
	}
	Combination(a, b, 0, M, M);
	system("pause");
	return 0;
}


