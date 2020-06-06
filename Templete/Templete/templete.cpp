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
	auto it = str.begin();
	while (it != str.end())
	{
		auto it1 = (*it).begin();
		while (it1 != (*it).end())
		{
			if (*it1 == ',')
			{
				(*it).insert((*it).begin(),'"');
				(*it).insert((*it).end(), '"');
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
	return 0;
}


