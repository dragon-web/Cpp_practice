#define _CRT_SECURE_NO_WARNINGS 

//�����ַ�����������ִ�

#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*int main()
{
	string str, cur, res;
	cin >> str;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.length() < cur.length())
			{
				res = cur;
				cur.clear();
			}
		}
	}
	cout << res;

	system("pause");
	return 0;
}*/

//1�����������ַ�����󹫹��Ӵ��ĳ���
//�̵�ȥƥ�䳤��
//��������

/*void getCommonStrLength(string & str1,string & str2)
{
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	int max = 0;
	vector < vector<int> > dp(len1, vector<int>(len2, 0));
	for (size_t i = 0; i < len1; ++i)
	{
		for (size_t j = 0; j < len2; ++j)
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
				max = dp[i][j];
		}
	}
	cout << "max = " << max << endl;
 }
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	getCommonStrLength(str1, str2);
	system("pause");
	return 0;
}
*/
//2����1,2��...9���ֳ�3�����飬����ʹ��3����λ������1:2:3�ı������������������3λ����
//��� ��֦
//1 2 3 
// 
//
//�ı�����˳��Ϳ���
//

/*void dfs(int count)//һ��Ҫ����������������Ȼһ�����ȥ��
{
	if(count == 9)


}*/
#include<iostream>
using namespace std;

int result[9] = { 0 };
int used[9] = { 0 };
int a, b, c;
void dfs(int count);
int main()
{
	dfs(0);
	system("pause");
	return 0;
}
void dfs(int count)//���ݷ�רҵ����
{

	if (count == 9)//����
	{
		a = result[0] * 100 + result[1] * 10 + result[2];
		b = result[3] * 100 + result[4] * 10 + result[5];
		c = result[6] * 100 + result[7] * 10 + result[8];
		if (a * 2 == b && a * 3 == c)
		{
			cout << a << " " << b << " " << c << endl;
		}
	}
	else {
		for (int i = 0; i < 9; ++i)//��ڲ���
		{
			if (used[i] == 0)   //û��ʹ�ù�                                            
			{
				used[i] = 1;//ʹ�õ�
				result[count] = i + 1;//��¼�������
				int temp = count + 1;
				dfs(temp);
				used[i] = 0;
			}
		}
	}
}