#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>

using namespace std;

/*
1. ���ͬһ����а����������࣬��Щ�����Ĺ��캯���������Ⱥ������ã�
2. ��������ɷ���������������������ȵ��û��๹�캯�����ٵ���������Ĺ��캯��
3. ��ͬһ����а���
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