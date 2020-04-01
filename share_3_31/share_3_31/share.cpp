#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
//计算字符串中连续出现的数字字符的个数

//sadsnfjha12384zcsdc526ac45aadc
// 定义2 个容器 当前遇到的数字串  之前的数字串
//string
using namespace std;
//asdfa12364adsdas785959asd
/*
int main()
{
	string str, res, cur;
	cin >> str;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] < '9')
			cur += str[i];
		else
		{
			if (res.size() < cur.size())
			{
				res = cur;
			}
			cur.clear();
		}
	}
	cout << res;
	system("pause");
	return 0;
}
*/
//计算两个字符串最大公共子串的长度  快手笔试题
//asdacskasasdsas
//dsvmldjas
//用短的去匹配长的
//穷举
//n!
//平面图  二维坐标
void getMaxCommonStrLength(string &str1, string &str2)
{
	size_t len1 = str1.size();
	size_t len2 = str2.size();
	int max = 0;
	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
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
			{
				max = dp[i][j];
			}
		}
	}
	cout << max << endl;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	getMaxCommonStrLength(str1, str2);
	system("pause");
	return 0;
}


//将1,2，...9共分成3个数组，并且使这3个三位数构成1:2:3的比例，求出满足条件的3位数
//回溯法  递归 穷举 剪枝 
// 
//9！ 代码量 
/*1 2 3    4 5 6     7 8 9
int a, b, c;
count 记录递归次数的数值
int nums[9] 判断，递归出口
//入口
count + 1
int used[9] 记录这个数有没有被用过
入口
第一次递归*/
/*
int used[9] = { 0 };
int result[9] = { 0 };//存放计算数据的数组
int a, b, c;
void dfs(int count);  //count 是结束递归的重要标志
int main()
{
	dfs(0);
	system("pause");
	return 0;
}

void dfs(int count)
{
	if (count == 9)
	{
		a = result[0]*100 + result[1]*10 + result[2];
		b = result[3]*100 + result[4]*10 + result[5];
		c = result[6]*100 + result[7]*10 + result[8];
		if (a * 2 == b && a * 3 == c)
		{
			cout << a << " " << b << " " << c << " " << endl;
		}
	}//出口
	else
	{
		for (int i = 0; i < 9; ++i)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				result[count] = i + 1;//数值关系对应
				dfs(count + 1);
				used[i] = 0;
			}
		}
	}
}
*/

