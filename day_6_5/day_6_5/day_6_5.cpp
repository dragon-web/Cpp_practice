#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
/*
int main()
{
	string str;
	string ori;
	size_t count = 0;
	while (cin >> str >> ori)
	{
		auto it = str.begin();
		auto it1 = ori.begin();
		while (it != str.end())
		{
			if (*it == *it1)
			{
				it1++;
				it++;
			}
			else
			{
				it++;
				it1 = ori.begin();
			}
			if (it1 == ori.end())
			{
				count++;
				it1 = ori.begin();
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string dic, str;
	while (cin >> dic >> str)
	{
		int pos = 0;
		int ret = 0;
		while ((pos = dic.find(str, pos)) != string::npos)//找到了
		{
			++ret;
			pos += str.size();
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}*/

// write your code here cpp

#include<iostream>
using namespace std;
unsigned long long fib(int x)
{
	int count = 1;
	unsigned long long a = 1, b = 1;
	unsigned long long temp;
	int ret = 1;
	if (x <= 2)
		return ret;
	while (count + 2 <= x)
	{
		temp = b;
		b = a + b;
		a = temp;
		count++;
	}
	return b;
}

int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		unsigned long long sum = 0;
		for (int i = from; i <= to; ++i)
		{
			sum += fib(i);
		}
		cout << sum << endl;
	}
	return 0;
}


/*
int main()
{
	string s, t;
	while (getline(cin, s) && getline(cin, t))
	{
		int flag = 0, i = 0, j = 0;
		while (i < s.size())
		{
			if (s[i] == t[j] && j < t.size())
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
			if (j == t.size())
			{
				j = 0;
				flag++;
			}
		}
		cout << flag << endl;
	}
	return 0;
}
*/



#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	//提前计算斐波那契数列，只保留后6位
	for (int i = 2; i <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000; //由于是相加，所以只要后六位不影响下一个数的结果
	} //这里利用了OJ平台计时从开始读取数据的trick，这个技巧可以用在很多题目里
		int n;
	while (std::cin >> n)
	{
		if (n < 29)
		{
			//斐波那契数列小于6位
			printf("%d\n", fib[n]);
		}
		else
		{
		printf("%06d\n", fib[n]);
		}
	} 
	return 0;
}