#define _CRT_SECURE_NO_WARNINGS 
/*
#include<iostream>
#include<stdbool.h>
using namespace std;

int Judgemax(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		return 2;
	else
	{
		return Judgemax(x - 1) + Judgemax(x - 2);
	}
}
int main()
{
	int num;
	cin >> num;
	int p = Judgemax(num);
	cout << p;
	system("pause");
	return 0;
}
*/
/*
void swap(int * a, int *b)
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}*/
/*
class A
{
public:
	int GetValue() 
	{
		vv = 1;
		return vv;
	}
private:
	int vv;
};

int main()
{ 
	int num1 = 5;
	int num2 = 6;
	swap(&num1, &num2);
	/*char arr[] = "wang\0miao";
	cout << sizeof(arr) << strlen(arr);
	char arr1[] = "Is Page Fault??";
	char arr2[] = "No Page Fault??";
	strcpy(arr1, "No");
	if (strcmp(arr1, arr2) == 0)
	{
		cout << arr2;
	}
	cout << arr1;



	system("pause");
	return 0;
}*/

#include<iostream>

using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int Year, int Month, int Day);
	bool JudgeRapYear(Date& A);
	int JudgeDay(Date & B);

};
bool Date::JudgeRapYear(Date& A)//判断当年是否为闰年
{
	if (A.year / 400 == 0||A.year % 100 != 0 && A.year % 4 == 0)
	{
		return true;
	}
	return false;
}
Date::Date(int Year, int Month, int Day)
{
	year = Year;
	month = Month;
	day = Day;
}
int Date::JudgeDay(Date &B)
{
	int Nowday = 0;
	if (JudgeRapYear(B))
	{
		switch(B.month)
		{
		case 1:
			if (B.day > 31)
				return -1;
			Nowday = 0 + B.day;
			break;
		case 2:
			if (B.day > 29)
				return -1;
			Nowday = 31 + B.day;
			break;
		case 3:
			if (B.day > 31)
			return -1;
			Nowday = 60 +B.day;
			break;
		case 4:
			if (B.day > 30)
				return -1;
			Nowday = 91+B.day;
			break;
		case 5:
			if (B.day > 31)
				return -1;
			Nowday = 121+B.day;
			break;
		case 6:
			if (B.day > 30)
				return -1;
			Nowday = 152+B.day;
			break;
		case 7:
			if (B.day > 31)
				return -1;
			Nowday = 182+B.day;
			break;
		case 8:
			if (B.day > 31)
				return false;
			Nowday = 213+B.day;
			break;
		case 9:
			if (B.day > 30)
				return -1;
			Nowday = 244+B.day;
			break;
		case 10:
			if (B.day > 31)
				return -1;
			Nowday = 274+B.day;
			break;
		case 11:
			if (B.day > 30)
				return -1;
			Nowday = 305+B.day;
			break;
		case 12:
			if (B.day > 31)
				return -1;
			Nowday = 335+B.day;
			break;
		default:
			return -1;
		}
	}
	else
	{
		switch (B.month)
		{
		case 1:
			if (B.day > 31)
				return -1;
				Nowday = 0 + B.day;
			break;
		case 2:
			if (B.day > 28)
				return -1;
			Nowday = 31 + B.day;
			break;
		case 3:
			if (B.day > 31)
				return -1;
			Nowday = 59 + B.day;
			break;
		case 4:
			if (B.day > 30)
				return -1;
			Nowday = 90 + B.day;
			break;
		case 5:
			if (B.day > 31)
				return -1;
			Nowday = 120 + B.day;
			break;
		case 6:
			if (B.day > 30)
				return -1;
			Nowday = 151 + B.day;
			break;
		case 7:
			if (B.day > 31)
				return -1;
			Nowday = 181 + B.day;
			break;
		case 8:
			if (B.day > 31)
				return -1;
			Nowday = 212 + B.day;
			break;
		case 9:
			if (B.day > 30)
				return -1;
			Nowday = 243 + B.day;
			break;
		case 10:
			if (B.day > 31)
				return -1;
			Nowday = 273 + B.day;
			break;
		case 11:
			if (B.day > 30)
				return -1;
			Nowday = 304 + B.day;
			break;
		case 12:
			if (B.day > 31)
				return -1;
			Nowday = 334 + B.day;
			break;
		default:
			return -1;
		}
	}
	return Nowday;
}
int main()
{
	int Y, M, D;
	cout << "输入年月日" << endl;
	cin >> Y >> M >> D;
	Date A(Y, M, D);
	int p =	A.JudgeDay(A);
	cout << p;
	system("pause");
	return 0;
}