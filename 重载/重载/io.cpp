#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
public:
	Date(int m = 1,int d = 20,int y = 2020)//���캯��
	{
		month = m;
		day = d;
		year = y;
	}
	friend ostream &operator<<(ostream& os, Date date);
	friend istream &operator>>(istream &in, Date &dt);
};
ostream &operator<<(ostream& os, Date date)
{
	os << "date.month:"<<date.month << "date.day"<<date.day << "date.year"<<date.year;
	return os;
}
istream &operator>>(istream &in, Date &date)
{
	cout << "day month year" << endl;
	in >> date.day >> date.month >> date.year;
}

int main()
{
	Date dt;//��������
	cin >> dt;
	cout << dt << endl;
	system("pause"); 
	return 0;
}