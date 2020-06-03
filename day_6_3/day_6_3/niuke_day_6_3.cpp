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
		printf("%d =", n); //���90 =
		for (unsigned i = 2; i <= std::sqrt(n); i++)
		{
			while (n % i == 0 && n != i) //������ͬһ������ֱ�����������ų��պ��Ǹ�����n�η������
			{
				printf(" %u *", i); //��һ�δ�ӡ 2 *,�ڶ��δ�ӡ���� 3 *
				n /= i; //���������޸�n��ֵ
			}
		}
		printf(" %d\n", n); //������n�Ѿ��Ǵ������һ���������������һ����������5
	} 
	return 0;
}

//1:���չ�ʽ

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
	int week = day_of_week(year, month, 1); //���1��������
	// 1 + 7(n - 1) + (���������� + 7 - 1��������) % 7
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
} 
// Ԫ��
void new_year_day(int year)
{
	printf("%d-01-01\n", year);
} 
//����·�¡�������գ�1�µĵ���������һ��
void martin_luther_king_day(int year)
{
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
} 
// ��ͳ�գ�2�µĵ���������һ��
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
} 
// ������ʿ�����գ�5�µ����һ������һ��
void memorial_day(int year)
{
	// �� 6 ����ǰ��
	int week = day_of_week(year, 6, 1);
	// ����һ�Ļ����� 31 ����ǰ�� 6 �죬������ week - 2 ��
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}
// ����
void independence_day(int year)
{
	printf("%d-07-04\n", year);
} 
// �Ͷ��ڣ�9�µĵ�һ������һ��
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
} 
// �ж��ڣ�11�µĵ��ĸ������ģ�
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
} 
// ʥ����
void christmas(int year)
{
	printf("%d-12-25\n", year);
} 
// ��������
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