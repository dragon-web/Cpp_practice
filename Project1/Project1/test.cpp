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
		//���ԽС����ֵԽ��
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
	//���ԽС����ֵԽ��
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
	ɭ����ѡ���������Ʊ������߻�ʤ��n�����ÿ���������ͶƱ�����1 ��n,���ԽС����Խ��
	ÿ������ֻ��ѡ���Լ�������Ļ������Լ�����Ͷ0��ʱ�����û�г�ݶ������Լ�����ÿ��������
	����ܻ�õ�Ʊ��
	�����һ��  n
	�ڶ��У� ÿ������ĳ�ݱ��
	����� ÿ�����������ܵ�Ʊ��
	����
	���룺
	4
	0 1 1 1 
	�����
	4 1 1 1
*/