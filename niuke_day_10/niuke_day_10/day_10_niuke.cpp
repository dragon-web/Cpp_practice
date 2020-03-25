#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getCommonStrLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int max = 0;
	//所有值初始化为0
	vector<vector<int>>  dp(len1, vector<int>(len2, 0));
	//计算dp
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			//如果当前结尾的字符相等，则在dp[i-1][j-1]的基础上加1
			if ((str1[i] == str2[j]) || (str1[i] + 32 - 'a') % 32 == (str2[j] + 32 - 'a') % 32)
			{
				if (i >= 1 && j >= 1)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					//dp[i][0] or dp[0][j]
					dp[i][j] = 1;
			}
			//更新最大值
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	cout << max << endl;

}
int main()
{
	string str1,str2;
	cin >> str1;
	cin >> str2;
	getCommonStrLength(str1, str2);
	system("pause");
	return 0;
}