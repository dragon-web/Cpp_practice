#define _CRT_SECURE_NO_WARNINGS 

/*#include<iostream>
using namespace std;
//A n m����ȫ����  ���� 1 ȫ����
//permutation
//�ݹ�˼·����
int main()
{
	//������ٷ� �������1 2 3 ��ȫ����
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
	if (k == m)//���˵�����������һλ��ȫ���У���ô�Ϳ�ʼ��ӡ ������˵һ������һ�����ݴ�ӡ�ģ��������к��ٴ�ӡ
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
			swap(a[j], a[k]);//������
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
//�ֵ�����������ݽ϶࣬�Ƚ���������ģʽ���̺�������
//���
//�������򣬵����������

#include<iostream>
#include<vector>

using namespace std;

void Combination(vector<int> &a, vector<int> &b, int l, int m, int M)
{
	//b������ʱ�洢�����len(b)==M��lΪ����α꣬��ʼֵȡ0��M��ȡ��������m����ָʾ�ݹ���ȣ���ʼֵȡM��
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


