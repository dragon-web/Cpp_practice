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
				cout << "���ƥ�䴮��:" << *it2 << endl;
		}
	}
	else
	{
		while (it2 != (str2.end() - 1))//����ǰ׺
		{
			temp1 += (*it2);
			table_front[i] = temp1;
			it2++;
			i++;
		}
		it2 = str2.begin() + 1;
		while (it2 != str2.end())//���ú�׺
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
	//ǰ��׺�ҵ��ˣ���ʼ�Ƚ�ǰ��׺����ͬ�ļ���
	//ǰ׺table_front   ��׺table_last  
	int count = 0;
	vector<int> dp(table_front.size());//��ֵ��
	auto p = table_front.begin();
	auto q = table_last.begin();
	//��ֵ��table��������
	//��ֻ���ҵ�������Ǹ��ַ���ǰ��׺
}

int main()
{
	string str1;//Դ�ַ���
	string str2;//ƥ����ַ���
	cin >> str1 >> str2;
	KMP(str1, str2);
	system("pause");
	return 0;
}