#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#include<iostream>
int Prim(int n)
{
	int i = 2, cnt = 0;
	while (n > 0 && n >= i)
	{
		if (n%i == 0)
		{
			cnt++;
			while (n%i == 0&&n>0)
			{
				n = n / i;
			}
		}
		i++;
	}
	return cnt;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << Prim(n) << endl;
	}
	return 0;
}



/*
void swap(char &a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}
void Judge(string&  res)
{
		int i = 0;
		for(i; i < res.length(); ++i)
		{
			if (res[i] >= 'A'&& res[i] <= 'Z')
			{
				if (i + 5 >= res.length() - 1)
				{
					swap(res[i], res[i - res.length() + 5]);
				}
				else
				{
					swap(res[i], res[i + 5]);
				}
			}
		}
}
int main()
{
	string arr;
	cin >> arr;
	Judge(arr);
	string::iterator it = arr.begin();
	while (it != arr.end())
	{
		cout << *it;
		it++;
	}
	system("pause");
	return 0;
}
*/

