#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int num;//����
	int kum;//��Ҫʵ������������ߵ�����
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

int Solution::FinfCommonHeigth()//�ҵ������ͬ�߶�ֵ�ĸ���
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
int Solution::FindCommonValue()//�ҵ������ͬ�߶�ֵ�ĸ���
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int max = 0;
	int res = 0;
	for (i = 0; i < Arr->size(); ++i)
	{
		for (j = 0; j < Arr->size(); ++j)
		{
			if ((*Arr)[i] == (*Arr)[j])
			{
				temp++;
			}
		}
		res = temp > res ? temp : res;
		temp = 0;
	}
	return max;
}

void Solution::move()
{
	int max = FindTargetH();//���ֵ��λ��
	int min = FindTargetL();//��Сֵ��λ��
	FinfCommonHeigth();
	
	
	(*Arr)[min]++;
	(*Arr)[max]--;
}

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