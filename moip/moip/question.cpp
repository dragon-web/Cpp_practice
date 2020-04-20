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
	int B, N;//N是奶牛数量  B是钱数
	cin >> B >> N;
	vector<ListNode> dp(N);//初始化N个节点空间
	for (int i = 0; i < N; i++)
	{
		cin >> dp[i].price >> dp[i].run;
	}
	sort(dp.begin(), dp.end());//默认升序
	//此时得到的向量空间就是升序的
	int count = 0;
	vector<ListNode>::iterator it = dp.begin();
	//关键优惠劵给哪个牛，应该是最大优惠的那个牛即礼物临届最贵的牛
	while (it != dp.end()&&N > 0)
	{
		B -= ((*it).price + (*it).run);
		count++;
		it++;
	}
	if (it == dp.end())
	{
		cout << "最大奶牛数" << count << endl;
	}
	else if (B + (*it).price / 2 >= (*(it + 1)).price + (*(it + 1)).run)
	{
		count++;
	}
	cout << "最大奶牛数" << count << endl;
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
	vector<ListNode> dpv(N);//初始化N个节点空间
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
		dp[i] = dpv[i].price + dpv[i].run;
	}
	sort(dp.begin(), dp.end());//默认升序
	//此时得到的向量空间就是升序的
	int count = 0;
	auto it = dp.begin();
	//关键优惠劵给哪个牛，应该是最大优惠的那个牛即礼物临届最贵的牛
	while (it != dp.end() && B - (*it) > 0)  //?
	{
		count++;
		it++;
	}
	if (it == dp.end())//此时所有牛都获得礼物
	{
	}
	//此时B不能全额为下一头牛购买礼物
	else if (B > (dpv[count].price / 2 + dpv[count].run))
	{
		count++;
	}
	cout << "最大奶牛数 = " << count << endl;
	system("pause");
	return 0;
}
*/
typedef struct ListNode
{
	int price;//售价
	int run;//运费
}ListNode;
int main()
{
	int N = 6, B = 20;
	//cin >> N >> B;
	vector<int> dp(N);
	vector<ListNode> dpv(N);//初始化N个节点空间
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
	}
	sort(dp.begin(), dp.end());//默认升序
	//对dpv向量进行排序
	
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
	//此时得到的dpv向量空间就是升序的
	int count = 0;
	auto it = dpv.begin();
	//关键优惠劵给哪个牛，应该是最大优惠的那个牛即礼物临届最贵的牛
	while (it != dpv.end() && (B - (*it).price-(*it).run) > 0)
	{
		count++;
		B = B - (*it).price - (*it).run;
		it++;
	}
	if (it == dpv.end());//此时所有牛都获得礼物
	//此时B不能全额为下一头牛购买礼物
	else if (B >= (dpv[count].price / 2 + dpv[count].run)||(B >= (dpv[count-1].price / 2 + dpv[count].run)))
	{
		count++;
	}
	cout << "最大奶牛数 = " << count << endl;
	system("pause");
	return 0;
}