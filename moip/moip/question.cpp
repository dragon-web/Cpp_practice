#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
typedef struct ListNode
{
	int price;
	int run;
}ListNode;
int main()
{
	int B, N;//N����ţ����  B��Ǯ��
	cin >> B >> N;
	vector<ListNode> dp(N);//��ʼ��N���ڵ�ռ�
	for (int i = 0; i < N; i++)
	{
		cin >> dp[i].price >> dp[i].run;
	}
	sort(dp.begin(), dp.end());//Ĭ������
	//��ʱ�õ��������ռ���������
	int count = 0;
	vector<ListNode>::iterator it = dp.begin();
	//�ؼ��Ż݄����ĸ�ţ��Ӧ��������Żݵ��Ǹ�ţ�������ٽ�����ţ
	while (it != dp.end()&&N > 0)
	{
		B -= ((*it).price + (*it).run);
		count++;
		it++;
	}
	if (it == dp.end())
	{
		cout << "�����ţ��" << count << endl;
	}
	else if (B + (*it).price / 2 >= (*(it + 1)).price + (*(it + 1)).run)
	{
		count++;
	}
	cout << "�����ţ��" << count << endl;
	system("pause");
	return 0;
}

typedef struct ListNode
{
	int price;
	int run;
}ListNode;
int main()
{
	int B, N;
	cin >> B >> N;
	vector<int> dp(N);
	vector<ListNode> dpv(N);//��ʼ��N���ڵ�ռ�
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
		dp[i] = dpv[i].price + dpv[i].run;
	}
	sort(dp.begin(), dp.end());//Ĭ������
	//��ʱ�õ��������ռ���������
	int count = 0;
	auto it = dp.begin();
	//�ؼ��Ż݄����ĸ�ţ��Ӧ��������Żݵ��Ǹ�ţ�������ٽ�����ţ
	while (it != dp.end() && B - (*it) > 0)  //?
	{
		count++;
		it++;
	}
	if (it == dp.end())//��ʱ����ţ���������
	{
	}
	//��ʱB����ȫ��Ϊ��һͷţ��������
	else if (B > (dpv[count].price / 2 + dpv[count].run))
	{
		count++;
	}
	cout << "�����ţ�� = " << count << endl;
	system("pause");
	return 0;
}
*/
typedef struct ListNode
{
	int price;//�ۼ�
	int run;//�˷�
}ListNode;
int main()
{
	int N = 6, B = 20;
	//cin >> N >> B;
	vector<int> dp(N);
	vector<ListNode> dpv(N);//��ʼ��N���ڵ�ռ�
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
	}
	sort(dp.begin(), dp.end());//Ĭ������
	//��dpv������������
	
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - 1-i; ++j)
		{
			if ((dpv[j].price + dpv[j].run) > (dpv[j+1].price + dpv[j+1].run))
			{
				swap(dpv[j], dpv[j + 1]);
			}
		}
	}
	//��ʱ�õ���dpv�����ռ���������
	int count = 0;
	auto it = dpv.begin();
	//�ؼ��Ż݄����ĸ�ţ��Ӧ��������Żݵ��Ǹ�ţ�������ٽ�����ţ
	while (it != dpv.end() && (B - (*it).price-(*it).run) > 0)
	{
		count++;
		B = B - (*it).price - (*it).run;
		it++;
	}
	if (it == dpv.end());//��ʱ����ţ���������
	//��ʱB����ȫ��Ϊ��һͷţ��������
	else if (B >= (dpv[count].price / 2 + dpv[count].run)||(B >= (dpv[count-1].price / 2 + dpv[count].run)))
	{
		count++;
	}
	cout << "�����ţ�� = " << count << endl;
	system("pause");
	return 0;
}