#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <cmath>
#include <iostream>

/*
1:
int main()
{
	unsigned int n;
	while (std::cin >> n)
	{
		printf("%d =", n); //输出90 =
		for (unsigned i = 2; i <= std::sqrt(n); i++)
		{
			while (n % i == 0 && n != i) //反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况
			{
				printf(" %u *", i); //第一次打印 2 *,第二次打印两个 3 *
				n /= i; //能整除就修改n的值
			}
		}
		printf(" %d\n", n); //跳出后，n已经是处理过的一个质数，就是最后一个质因数：5
	} 
	return 0;
}

//1:蔡勒公式

int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	} 
	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day -
		1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
	{
		week = 7;
	}
	return week;
} 
int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1); //求出1号星期数
	// 1 + 7(n - 1) + (所求星期数 + 7 - 1号星期数) % 7
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
} 
// 元旦
void new_year_day(int year)
{
	printf("%d-01-01\n", year);
} 
//马丁·路德·金纪念日（1月的第三个星期一）
void martin_luther_king_day(int year)
{
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
} 
// 总统日（2月的第三个星期一）
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
} 
// 阵亡将士纪念日（5月的最后一个星期一）
void memorial_day(int year)
{
	// 从 6 月往前数
	int week = day_of_week(year, 6, 1);
	// 星期一的话，从 31 号往前数 6 天，否则，数 week - 2 天
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}
// 国庆
void independence_day(int year)
{
	printf("%d-07-04\n", year);
} 
// 劳动节（9月的第一个星期一）
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
} 
// 感恩节（11月的第四个星期四）
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
} 
// 圣诞节
void christmas(int year)
{
	printf("%d-12-25\n", year);
} 
// 美国节日
void holiday_of_usa(int year)
{
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
} 
int main()
{
	int year;
	while (std::cin >> year)
	{
		holiday_of_usa(year);
		putchar('\n');
	}
}
*/
/*using namespace std;

class Date
{
private:
	int Year;
	int Month;
	int Day;
public:
	Date(int year, int month, int day):Year(year),Month(month),Day(day)
	{
	}
	int getYear()
	{
		return this->Year;;
	}
	int getMonth()
	{
		return this->Month;
	}
	int getDay()
	{
		return this->Day;
	}
};
bool JudgeIsPrim(int &x)
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int Syear, Smonth, Sday;
	int Eyear, Emonth, Eday;
	cin >> Syear >> Smonth >> Sday >> Eyear >> Emonth >> Eday;
	Date dateStart(Syear, Smonth, Sday);
	Date dateEnd(Eyear, Emonth, Eday);
	int count = (dateEnd.getYear() - dateStart.getYear());
	if (dateEnd.getMonth() - dateStart.getMonth() < 0)
	{
		count--;
	}
	count += (dateEnd.getMonth() - dateStart.getMonth())


	system("pause");
	return 0;
}
*/

#include<iostream>
#include<vector>
using namespace std;
long long fib(long long x)
{
	long long count = 1;
	long long a = 1, b = 2;
	long long temp;
	long long ret = 1;
	if (x <= 2)
		return x;
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
	int n;
	while (cin >> n)
	{
		long long res = fib(n);
		//cout << res << endl;
		if (res < 100000)
		{
			cout << res << endl;
		}
		else
		{
			long long temp = 0;
			long long a;
			long long i = 1;
			int num = 1;
			while (num <=6)
			{
				a = res % 10;
				res /= 10;
				temp += a * i;
				i *= 10;
				num++;
			}
			cout << temp << endl;
		}
	}
	return 0;
}