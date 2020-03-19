#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stack>
using namespace std;
/*
递归算法
void print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}

int main()
{
 char p[] = "Geneius";
	print(p);

	system("pause");
	return 0;
}


int main()
{
	int i = 3;
	printf("%d %d", ++i, ++i);
	const int a = 10;
	int *p = (int*)(&a);
	*p = 20;
	cout << "a = " << a << "*p = " << *p << endl;
	system("pause");
	return 0;
}*/

//完数


/*
int main()
{
	stack<int>PerStack;
	for (int i = 1; i <= 500000; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if(i % j == 0)
				PerStack.

		}
	}


	system("pause");
	return 0;
}
*/

#include <iostream>
#include <math.h>
using namespace std;

bool IsCom(int num)
{
	int sum = 0;
	/*for(int i = 1; i<num; i++)
	{
		if(num % i == 0)
		{
			sum += i;
		}
	}*/
	for (int i = 2; i < sqrt(num); i++)
	{
		if (num%i == 0)
		{
			if (num / i != i)
			{
				sum += i;
				sum += (num / i);
			}
			else
			{
				sum += i;
			}
		}
	}
	if (sum > 0)//只有这个数不是1才加
		sum += 1;

	if (sum == num)
		return true;
	else
		return false;
}
int count(int n)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (IsCom(i))
			ret++;
	}
	return ret;
}
int main()
{

	int n = 0;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
	return 0;
}
