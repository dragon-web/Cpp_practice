#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*void Roself(int sz,int target)//下标从1开始
{
	vector<int> dp;
	for (int i = 1; i <= sz; ++i)
	{
		dp.push_back(i);//从下标零开始的
	}
	int pos = target;
	int count = 1;
	for (pos = target; dp.size() > 1; pos += target)
	{
		if (pos <= dp.size())
		{
			cout << "删除值:" << dp[pos - 1] << endl;
			cout << "第" << count << "次删除" << endl;
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
	cout << "请输入人数" << endl;
	cin >> sum;
	cout << "请输入目标值" << endl;
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
	bool a[101] = { 0 };//只能玩100个人的
	int n, m, i, f = 0, t = 0, s = 0;
	cin >> n >> m;
	do
	{
		++t;//逐个枚举圈中的所有位置
		if (t > n)
			t = 1;//数组模拟环状，最后一个与第一个相连
		if (!a[t])
			s++;//第t个位置上有人则报数
		if (s == m)//当前报的数是m
		{
			s = 0;//计数器清零
			cout << t << ' ';//输出被杀人编号
			a[t] = 1;//此处人已死，设置为空
			f++;//死亡人数+1
		}
	} while (f != n);//直到所有人都被杀死为止

	system("pause");
	return 0;
}