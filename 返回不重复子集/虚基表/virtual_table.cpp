#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>

using namespace std;

/*
1. 如果同一层次中包含多个虚基类，这些虚基类的构造函数按他们先后次序调用，
2. 若虚基类由非虚基类派生而来，则仍先调用基类构造函数，再调用派生类的构造函数
3. 若同一层次中包含
*/


string Judge(string& str)
{
	auto it = str.begin();
	auto it1 = it + 1;
	while (it != str.end())
	{
		while (it1 != str.end())
		{
			if (*it == *it1)
			{
				str.erase(it1);
			}
			else {
				it1++;
			}
		}
		it++;
		if (it != str.end())
			it1 = it + 1;
	}
	return str;
}

int main()
{
	string str;
	while(cin >> str)
	{
		string temp = Judge(str);
		cout << temp;
	}
	system("pause");
	return 0;
}