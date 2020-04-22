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

 vector<string> FindPrefix(string &str1)//��ñ�֤�������Ķ��������ǿյ�
{
	   vector<string> dp(str1.size()-1);
	   auto it = str1.begin();
	   int k = 0;
	   string temp;
	   while (it != str1.end())
	   {
		   temp += (*it);
		   dp[k] = temp;
		   it++;
		   k++;
	   }
	   return dp;
}//Ѱ��ǰ׺

 vector<string> FindSuffix(string &str2)//Ѱ�Һ�׺
 {
	 vector<string> dp(str2.size() - 1);
	 auto it = str2.begin()+1;
	 int k = 0;
	 string temp;
	 auto it1 = it;
	 while (it != str2.end())
	 {
		 while (it1 != str2.end())
		 {
			 temp += (*it1);
			 it1++;
		 }
		 it++;
		 it1 = it; 
	 }
 }

 vector<string> GetCommonFix(string &str1)//�ҵ������Ĵ��Ӽ�
 {
	 auto res1 = FindSuffix(str1);
	 auto res2 = FindPrefix(str1);
	 //��ʼ��ǰ��׺�����Ӽ�
	 vector<string> pp;
	 int k = 0;
	 auto temp1 = res1.begin();
	 auto temp2 = res2.begin();
	 while (temp1 != res1.end())
	 {
		 while (temp2 != res2.end())
		 {
			 if (*temp2 == *temp1)
			 {
				 pp.push_back(*temp2);
			 }
				 temp2++;
		 }
		 temp1++;
	 }
	 return pp;
 }

 //���ݹ����Ӽ�����table
 vector<int> KMP_table(string &str1, string &str2)
 {
	 //str1ΪĿ���ַ���  str2Ϊȥƥ����ַ���
	 FindPrefix(str1);
	 FindSuffix(str1);
 }

 void KMP(string& str1, string& str2)
 {



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


//�����ַ����г��ֵ���󹫹��Ӵ�����
void getCommonStrlegth(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int max = 0;
	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
					dp[i][j] = 1;
			}
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	cout << max << endl;
}



/*void KMP(string str1, string str2)
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
*/