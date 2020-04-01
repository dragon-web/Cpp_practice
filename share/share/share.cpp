#define _CRT_SECURE_NO_WARNINGS 

//计算字符串中最长的数字串

#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*int main()
{
	string str, cur, res;
	cin >> str;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.length() < cur.length())
			{
				res = cur;
				cur.clear();
			}
		}
	}
	cout << res;

	system("pause");
	return 0;
}*/

//1：计算两个字符串最大公共子串的长度
//短的去匹配长的
//连续问题

/*void getCommonStrLength(string & str1,string & str2)
{
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	int max = 0;
	vector < vector<int> > dp(len1, vector<int>(len2, 0));
	for (size_t i = 0; i < len1; ++i)
	{
		for (size_t j = 0; j < len2; ++j)
		{
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	cout << "max = " << max << endl;
 }
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	getCommonStrLength(str1, str2);
	system("pause");
	return 0;
}
*/
//2：将1,2，...9共分成3个数组，并且使这3个三位数构成1:2:3的比例，求出满足条件的3位数；
//穷举 剪枝
//1 2 3 
// 
//
//改变排列顺序就可以
//

/*void dfs(int count)//一定要传个参数进来，不然一会出不去了
{
	if(count == 9)


}*/
#include<iostream>
using namespace std;

int result[9] = { 0 };
int used[9] = { 0 };
int a, b, c;
void dfs(int count);
int main()
{
	dfs(0);
	system("pause");
	return 0;
}
void dfs(int count)//回溯法专业名字
{

	if (count == 9)//出口
	{
		a = result[0] * 100 + result[1] * 10 + result[2];
		b = result[3] * 100 + result[4] * 10 + result[5];
		c = result[6] * 100 + result[7] * 10 + result[8];
		if (a * 2 == b && a * 3 == c)
		{
			cout << a << " " << b << " " << c << endl;
		}
	}
	else {
		for (int i = 0; i < 9; ++i)//入口参数
		{
			if (used[i] == 0)   //没有使用过                                            
			{
				used[i] = 1;//使用掉
				result[count] = i + 1;//记录结果数组
				int temp = count + 1;
				dfs(temp);
				used[i] = 0;
			}
		}
	}
}