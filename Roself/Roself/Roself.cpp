#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*void Roself(int sz,int target)//�±��1��ʼ
{
	vector<int> dp;
	for (int i = 1; i <= sz; ++i)
	{
		dp.push_back(i);//���±��㿪ʼ��
	}
	int pos = target;
	int count = 1;
	for (pos = target; dp.size() > 1; pos += target)
	{
		if (pos <= dp.size())
		{
			cout << "ɾ��ֵ:" << dp[pos - 1] << endl;
			cout << "��" << count << "��ɾ��" << endl;
			dp.erase(dp.begin() + pos - 1);
		}
		else
		{
		}
	}
}


void Roself(int sz, int target)
{
	list<int> mylist;
	for (int i = 1; i <= sz; ++i)
	{
		mylist.push_back(i);
	}



}



int main()
{
	int sum;
	cout << "����������" << endl;
	cin >> sum;
	cout << "������Ŀ��ֵ" << endl;
	int target;
	cin >> target;
	Roself(sum, target);
	system("pause");
	return 0;
}*/



#include<iostream>
using namespace std;
int main()
{
	bool a[101] = { 0 };//ֻ����100���˵�
	int n, m, i, f = 0, t = 0, s = 0;
	cin >> n >> m;
	do
	{
		++t;//���ö��Ȧ�е�����λ��
		if (t > n)
			t = 1;//����ģ�⻷״�����һ�����һ������
		if (!a[t])
			s++;//��t��λ������������
		if (s == m)//��ǰ��������m
		{
			s = 0;//����������
			cout << t << ' ';//�����ɱ�˱��
			a[t] = 1;//�˴�������������Ϊ��
			f++;//��������+1
		}
	} while (f != n);//ֱ�������˶���ɱ��Ϊֹ

	system("pause");
	return 0;
}