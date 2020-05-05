#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
using namespace std;

/*vector<vector<vector<int>>> Judge(vector<vector<int>> p)
{
	vector<vector<vector<int>>> res(10, vector<vector<int>>(16, vector<int>(16)));
	for (int i = 0; i < 16; ++i)//行数
	{
		for (int j = 0; j < 16; ++j)//比较次数
		{
			for (int k = 0; k < 10; ++k)//列数
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

vector<vector<int>> Solution(vector<vector<int>> p)
{
	int temp = 0;
	vector<vector<vector<int>>> res(10, vector<vector<int>>(16, vector<int>(16)));
	vector<vector<int>> dp(16, vector<int>(16, 0));
	for (int i = 0; i < 16; ++i)//行数
	{
		for (int j = 0; j < 16; ++j)//比较次数
		{
			for (int k = 0; k < 10; ++k)//列数
			{
				if (j + 1 < 16)
				{
					if (p[j][k] == p[j + 1][k])
					{//	res[i][j][k] = 1;
						temp++;
					}
					else
					{
					}
				}

			}
			dp[i][j] = temp;
			temp = 0;
		}
	}
	return dp;
}

int main()
{

	//16*10 输入
		vector<vector<int>> dp(16,vector<int>(10,0));//二维数组
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> dp[i][j];//手动输入的数组
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
*/




int main()
{
	int arr[6] = { 0,1,8,5,2,6 };
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < (6 - j - 1); ++i)
		{
			if (arr[i] > arr[i+1])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		printf("%2d ", arr[i]);
	}
	system("pause");
	return 0;
}



