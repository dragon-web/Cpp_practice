#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
using namespace std;

vector<vector<vector<int>>> Judge(vector<vector<int>> p)
{
	vector<vector<vector<int>>> res(10, vector<vector<int>>(16, vector<int>(16)));
	for (int i = 0; i < 16; ++i)//����
	{
		for (int j = 0; j < 16; ++j)//�Ƚϴ���
		{
			for (int k = 0; k < 10; ++k)//����
			{
				if (j + 1 < 16)
				{
					if (p[j][k] == p[j + 1][k])
						res[i][j][k] = 1;
					else
					{
						res[i][j][k] = 0;
					}
				}

			}
		}
	}
	
	return res;
}
int main()
{

	//16*10 ����
		vector<vector<int>> dp(16,vector<int>(10,0));//��ά����
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> dp[i][j];//�ֶ����������
		}
	}
	auto def = Judge(dp);
	for (int k = 0; k < 10; ++k)
	{
		for (int i = 0; i < 16; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				cout << def[i][j][k];
			}
		}
	}
	system("pause");
	return 0;
}




