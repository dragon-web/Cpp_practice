#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

ostream &operator<<(ostream &os, vector<string> str)
{
	auto it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		it++;
	}
	return os;
}

void KMP(string str1, string str2)
{
	auto it1 = str1.begin();
	auto it2 = str2.begin();
	string temp1;
	string temp2;
	vector<string>table_front(str2.size()-1);
	vector<string>table_last(str2.size()-1);
	vector<string>Common(str2.size() - 1);
	int i = 0;
	int j = 0;
	if (str2.size() == 1)
	{
		while (it1 != str1.end())
		{
			if ((*it2) == (*it1))
				cout << "最大匹配串是:" << *it2 << endl;
		}
	}
	else
	{
		while (it2 != (str2.end() - 1))//放置前缀
		{
			temp1 += (*it2);
			table_front[i] = temp1;
			it2++;
			i++;
		}
		it2 = str2.begin() + 1;
		while (it2 != str2.end())//放置后缀
		{
			int j = 0;
			auto temp3 = it2;
			while (temp3 != str2.end())
			{
				table_last[j] += (*temp3);
				temp3++;
			}
			it2++;
		}
	}
	//前后缀找到了，开始比较前后缀中相同的集合
	//前缀table_front   后缀table_last  
	int count = 0;
	vector<int> dp(table_front.size());//数值表
	auto p = table_front.begin();
	auto q = table_last.begin();
	//数值表table创建出来
	//你只是找到了最后那个字符的前后缀
}

int main()
{
	string str1;//源字符串
	string str2;//匹配的字符串
	cin >> str1 >> str2;
	KMP(str1, str2);
	system("pause");
	return 0;
}