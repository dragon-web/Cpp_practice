#define _CRT_SECURE_NO_WARNINGS 
/*#include<iostream>
using namespace std;

int main()
	{
		int n;
		cin >> n;
		int i = 0;
		int *p = (int*)malloc(sizeof(int)*n);
		int *q = new int[n]();
		for (i = 0; i < n; ++i)
		{
			cin >> p[i];
		}
		//编号越小能力值越大
		for (int j = 0; j < n; j++)
		{
			if (p[j] == 0)
			{
				q[j] +=1;
			}
			else
			{
				for (int k = 0; k < j; ++k)
				{
					q[k] += 1;
				}
			}

		}
		for (int z = 0; z < n; ++z)
		{
			cout << q[z] << endl;
		}
	system("pause");
	return 0;
}
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0;
	int *p = (int*)malloc(sizeof(int)*n);
	int *q = new int[n]();
	for (i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	//编号越小能力值越大
	for (int j = 0; j < n; j++)
	{
		if (p[j] == 0)
		{
			q[j] += 1;
		}
		else
		{
			q[p[j]-1] += 1;
		}

	}
	for (int z = 0; z < n; ++z)
	{
		cout << q[z] << endl;
	}
	system("pause");
	return 0;
}

/*
	森林里选动物大王，票数最高者获胜；n个动物，每个动物进行投票，编号1 到n,编号越小能力越大，
	每个动物只能选比自己能力大的或者是自己，当投0的时候代表没有崇拜对象是自己，求每个动物最
	大可能获得的票数
	输入第一行  n
	第二行： 每个动物的崇拜编号
	输出： 每个动物最大可能的票数
	例：
	输入：
	4
	0 1 1 1 
	输出：
	4 1 1 1
*/