#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
//�����ַ������������ֵ������ַ��ĸ���

//sadsnfjha12384zcsdc526ac45aadc
// ����2 ������ ��ǰ���������ִ�  ֮ǰ�����ִ�
//string
using namespace std;
//asdfa12364adsdas785959asd
/*
int main()
{
	string str, res, cur;
	cin >> str;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] < '9')
			cur += str[i];
		else
		{
			if (res.size() < cur.size())
			{
				res = cur;
			}
			cur.clear();
		}
	}
	cout << res;
	system("pause");
	return 0;
}
*/
//���������ַ�����󹫹��Ӵ��ĳ���  ���ֱ�����
//asdacskasasdsas
//dsvmldjas
//�ö̵�ȥƥ�䳤��
//���
//n!
//ƽ��ͼ  ��ά����
void getMaxCommonStrLength(string &str1, string &str2)
{
	size_t len1 = str1.size();
	size_t len2 = str2.size();
	int max = 0;
	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			if (dp[i][j] > max)
			{
				max = dp[i][j];
			}
		}
	}
	cout << max << endl;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	getMaxCommonStrLength(str1, str2);
	system("pause");
	return 0;
}


//��1,2��...9���ֳ�3�����飬����ʹ��3����λ������1:2:3�ı������������������3λ��
//���ݷ�  �ݹ� ��� ��֦ 
// 
//9�� ������ 
/*1 2 3    4 5 6     7 8 9
int a, b, c;
count ��¼�ݹ��������ֵ
int nums[9] �жϣ��ݹ����
//���
count + 1
int used[9] ��¼�������û�б��ù�
���
��һ�εݹ�*/
/*
int used[9] = { 0 };
int result[9] = { 0 };//��ż������ݵ�����
int a, b, c;
void dfs(int count);  //count �ǽ����ݹ����Ҫ��־
int main()
{
	dfs(0);
	system("pause");
	return 0;
}

void dfs(int count)
{
	if (count == 9)
	{
		a = result[0]*100 + result[1]*10 + result[2];
		b = result[3]*100 + result[4]*10 + result[5];
		c = result[6]*100 + result[7]*10 + result[8];
		if (a * 2 == b && a * 3 == c)
		{
			cout << a << " " << b << " " << c << " " << endl;
		}
	}//����
	else
	{
		for (int i = 0; i < 9; ++i)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				result[count] = i + 1;//��ֵ��ϵ��Ӧ
				dfs(count + 1);
				used[i] = 0;
			}
		}
	}
}
*/

