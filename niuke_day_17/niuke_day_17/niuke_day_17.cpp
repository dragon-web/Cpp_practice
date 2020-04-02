#define _CRT_SECURE_NO_WARNINGS 
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

/*
int main()
{
	float o, m;
	int N = 1000000;
	double x, y, pi;
	srand(time(NULL));
	for (o = 0, m = 0; o < N; o++)
	{
		x = 2.0*rand() / RAND_MAX - 1;
		y = 2.0*rand() / RAND_MAX - 1;
		if ((x*x + y * y) <= 1)
			m++;
	}
	pi = 4.0*m / N;
	cout << pi << endl;
	_getch();
	return 1;
}*/
int getSum(int a, int b)
{
	while (a&b)
	{
		int n = a;
		int m = b;
		a = m ^ n;
		b = (n&m) << 1;
	}
	return a^b;
}
//1:如果不产生进位 则异或就是相加
//2: 如果产生进位,a 将不进位的位保留下来 //b = (n&m) << 1;产生进位
//循环是直到不产生进位为止
int main()
{
	int num1, num2;
	
	while (cin >> num1 >> num2)
	{
		int p = getSum(num1, num2);
		cout << p << endl;
	}
	system("pause");
	return 0;
}


/*void Judge(int a, int b, int c)
{
	if ((a + b > c) && (a - b < c) && (b + c > a) && (b - c < a) && (a - c < b) && (a + c > b))
	{
		cout <<"Yes"<<endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

void Judge(long long a, long long b, long long c)
{
	if ((a + b > c) && (a - b < c) && (b + c > a) && (b - c < a) && (a - c < b) && (a + c > b))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

int main()
{
	long long a, b, c;
	while (cin >> a >> b >> c)
	{
		Judge(a, b, c);
	}
	return 0;
}
*/