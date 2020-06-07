#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
int main()
{
	string str1;
	string str2;
	/*while (cin >> str1)
	{
		cin >> str2;
		int pos = 0;
		auto it = str1.begin();
		if (*it == '"')
		{
			it++;
			pos++;
		}
		while (pos = str1.find(str2, pos) != string::npos)//当没有找到时
		{
			pos += str2.size();
		}


	}
	//vector<int> fp[5];


int count2 = 0;
void dfs(vector<int>& v, int cur, int  k)
{

	if (k == 0)
	{
		//for (int i = 0; i < v.size(); i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;
		return;
	}
	//2  2          10
	for (int i = cur; i < v.size(); i++)
	{
		swap(v[i], v[cur]);
		dfs(v, cur + 1, k - 1); // i + 1
		swap(v[i], v[cur]);

	}
}*/


int count2 = 0;
void dfs(vector<int>& v, int cur, int  k)
{

	if (k == 0)
	{
		//for (int i = 0; i < v.size(); i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;
		return;
	}
	//2  2          10
	for (int i = cur; i < v.size(); i++)
	{
		swap(v[i], v[cur]);
		dfs(v, cur + 1, k - 1); // i + 1
		swap(v[i], v[cur]);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i;
	}
	vector<bool> used(n);
	vector<int> tmp;
	int k = n;
	dfs(v, 0, k);
	cout << count2 << endl;
	system("pause");
}



/*
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i;
	}
	vector<bool> used(n);
	vector<int> tmp;
	int k = n;
	dfs(v, 0, k);

	cout << count2 << endl;
	system("pause");
	return 0;
}
*/

	