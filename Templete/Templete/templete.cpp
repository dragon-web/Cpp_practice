#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	string s;
	int num;
	cin >> num;
	vector<string> str;
	string temp;
	getchar();
	for (int i = 0; i < num; ++i)
	{
		getline(cin,temp);
		str.push_back(temp);
		temp.clear();
	}
	auto it = str.begin();//指向那个string
	while (it != str.end())
	{
		auto it1 = (*it).begin();
		while (it1 != (*it).end())
		{
			if (*it1 == ',')
			{
				auto qq = it1;
				(*it).insert((*it).begin(), '"');//返回插入后迭代器的位置
				(*it).insert((*it).end(), '"');
				it1 = qq;
				it1++;
			}
			it1++;
		}
		it++;
	}
	auto p = str.begin();
	while (p != str.end())
	{
		cout << (*p) << endl;
		p++;
	}
	system("pause");
	return 0;
}

/*
int main()
{
	string a("assfa");
	auto it = a.begin();
	while (it != a.end())
	{
		cout << *it << endl;
		it++;
	}
	system("pause");
	return 0;
}
*/

