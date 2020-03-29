#define _CRT_SECURE_NO_WARNINGS 
/*
#include<iostream>
#include<vector>

using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		int count = 0;
		int temp = 0;
		int num;
		std::vector<int>::iterator it = gifts.begin();
		std::vector<int>::iterator it1 = gifts.begin();
		while (it != gifts.end())
		{
			while (it1 != gifts.end())
			{
				if(*it == *it1)
				{
					temp++;
				}
				if (temp > count)
				{
					count = temp;
					num = *it;
				}
				it1++;
			}
			it++;
			temp = 0;
		}
		return num > n / 2 ? num : 0;
	}
};
int main()
{
	
	system("pause");
	return 0;
}
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minDistance(string& word1, string& word2) {
		int row = word1.size();
		int col = word2.size();
		vector<vector<int> >dp(row + 1, vector<int>(col + 1, 0));

		for (int i = 1; i <= row; i++)
			dp[i][0] = i;//从长度为i的字符串到空串需要变换i次
		for (int j = 1; j <= col; j++)
			dp[0][j] = j;//从长度为kong的字符串到长度为j的字符串需要变换j次

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
			}
		}
		return dp[row][col];
	}
};
int main()
{
	Solution a;
	string str1, str2;
	cin >> str1 >> str2;
	
	a.minDistance(str1, str2);
	
	return 0;
}