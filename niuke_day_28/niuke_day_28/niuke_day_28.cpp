#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int num;//塔数
	int kum;//需要实现最少相等塔高的塔数
	vector<int>* Arr;
public:
	Solution(int n,int k,vector<int>* p)
	{
		num = n;
		kum = k;
		Arr = p;
	}
	/*~Solution()
	{
		delete[] Arr;
	}*/
public:
	void move();
	int FindTargetH();
	int FindTargetL();
	int FinfCommonHeigth();
	int FindCommonValue();
};

int Solution::FindTargetH()
{
	int maxValue = max_element(Arr->begin(), Arr->end()) - Arr->begin();
	return maxValue;
}
int Solution::FindTargetL()
{
	int minValue = min_element(Arr->begin(), Arr->end()) - Arr->begin();
	return minValue;
}

int Solution::FinfCommonHeigth()//找到最大相同高度值的个数
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int res = 0;
	for (i = 0; i < Arr->size();++i)
	{
		for (j = 0; j < Arr->size();++j)
		{
			if ((*Arr)[i] == (*Arr)[j])
			{
				temp++;
			}
		}
		res = temp > res ? temp : res;
		temp = 0;
	}
	return res;
}
int Solution::FindCommonValue()//找到最大相同高度值需要再申请一个数组
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int res = 0;
	int max = 0;
	int* p = new int[Arr->size()]();
	for (i = 0; i < Arr->size(); ++i)
	{
		p[(*Arr)[i]] += 1;
	}
	for (int j = 0; j < Arr->size(); ++j)
	{
		max = max > p[j] ? max : p[j];
	}//我要找的是下标对不对
	for (int k = 0; k < Arr->size(); ++k)
	{
		if (max == p[k])
			return k;
	}
	return -1;
}

void Solution::move()
{
	int max = FindTargetH();//最大值的位置
	int min = FindTargetL();//最小值的位置
	FinfCommonHeigth();
	int common = FindCommonValue();
	if ((*Arr)[min] != common)
	{
		(*Arr)[min]++;
	}
	
	else { (*Arr)[max]--; }
	sort(Arr->begin(), Arr->end());
}
//每次从最高塔的塔尖拿走一块或者从最低塔的塔底加一块（sort）
int main()
{
	int n;
	int k;
	cin >> n >> k;
	vector<int> dp(n,0);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> dp[i];
	}
	Solution a(n,k,&dp);
	int p = a.FinfCommonHeigth();
	while ( p != k)
	{
		a.move();
		p = a.FinfCommonHeigth();
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}