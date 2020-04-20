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
	int N = 5, B = 24;
	//cin >> N >> B;
	vector<int> dp(N);
	vector<ListNode> dpv(N);//��ʼ��N���ڵ�ռ�
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
		dp[i] = dpv[i].price + dpv[i].run;
	}
	sort(dp.begin(), dp.end());//Ĭ������
	for (int i = 1; i < N; ++i)
	{
		if (dp[i - 1] == dp[i] && dpv[i - 1].price > dpv[i].price)
			swap(dpv[i - 1], dpv[i]);
	}
	//��ʱ�õ��������ռ���������
	int count = 0;
	auto it = dp.begin();
	//�ؼ��Ż݄����ĸ�ţ��Ӧ��������Żݵ��Ǹ�ţ�������ٽ�����ţ
	while (it != dp.end() && B - (*it) > 0)
	{
		count++;
		B -= (*it);
		it++;
	}
	if (it == dp.end())//��ʱ����ţ���������
	{
	}
	//��ʱB����ȫ��Ϊ��һͷţ��������
	else if (B >= (dpv[count].price / 2 + dpv[count].run))
	{
		count++;
	}
	cout << "�����ţ�� = " << count << endl;
	system("pause");
	return 0;
}