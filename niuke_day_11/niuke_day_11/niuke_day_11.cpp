#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
//寻找连续最长的数字串
int main()
{
	string str, res, cur;
	cin>>str;
	for (size_t i = 0; i <= str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
				res = cur;
				cur.clear();
		}
	}
	cout << res;
	system("pause");
	return 0;
}