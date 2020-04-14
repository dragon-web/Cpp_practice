#define _CRT_SECURE_NO_WARNINGS 
/*
#include<map>
#include <iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
map<int, int> deal;
vector<int> result;
void back(map<int, int> m, int n)
{
	if (!n)
	{
		result[n]++;
		return;
	}
	else 
	{
		result[n - 1]++;
		auto t = deal.find(n - 1);
		int b = (*t).second;
		back(deal, b);
	}
}
int main()
{
	int num;

	cin >> num;
	deal[0] = 0;
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		result.push_back(0);
	}
	result[0] = 1;
	for (int i = 1; i < num; i++)
	{
		int temp;
		cin >> temp;
		cout << endl;
		deal[i] = temp;
		if (temp != 0)
		{
			auto t = deal.find(temp - 1);
			int b = (*t).second;
			back(deal, b);
		}
		else
			result[i]++;

	}
	for (int i = 1; i < num; i++)
	{
		if (deal[0] != deal[num])
		{
			result[0]--; break;
		}
	}
	for (int i = 0; i < num; i++)
		cout << result[i] << endl;
	system("pause");
	return 0;
}*/
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	int vec[10000];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}
	int ans[10000];
	for (int i = n; i > 0; i--) {
		if (vec[i] == 0) {
			ans[i]++;
		}
		else {
			ans[vec[i]]++;
			ans[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/
/*

输入：4
	  0 1 1 1
输出：4 1 1 1

第一个动物崇拜自己 第二个崇拜1 也可投自己
第三个动物崇拜1 可以投1 和自己
第四个动物崇拜1 可以投1 和自己
所以最大可能就是 4 1 1 1 
*/



#include<iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int *p = new int[n]();
	int *res = new int[n];
	for (int i = 0; i < n;++i)
	{
		cin >> p[i];
		res[i] = 1;
	}

	for (int j = 0; j < n; ++j)
	{
		if (p[j] != 0)
		{
			res[p[j]-1] += 1;
		}
	}
	for (int k = 0; k < n; ++k)
	{
		cout << res[k] << " ";
	}
	system("pause");
	return 0;
}