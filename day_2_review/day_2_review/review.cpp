#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

/*class Date;
Date* pa, &ra;
class student
{
public:
	void init(int number1, char* name1, Date &birth, float score);
	void modify(float score);
	void print();
private:
	int number;
	char name[15];
	Date *birthday;
	float score;
};
//һ���������ָ���������͵�ָ���������Ϊ���ݳ�Ա

class Student
{
public:
	Student(int number1, char* name1, float score1);//���캯������
	void modify(float score);
	void print();
private:
	int number;
	char name[15];
	Student* next;
	float score;
};

Student::Student(int number1, char* name1, float score1)//���캯������ ���캯��û�з�������
{
	number = number1;
	strcpy(name, name1);
	score = score1;
}
void Student::modify(float score1)
{
	score = score1;
}
void Student::print()
{
	cout << "Student's number is" << number << endl;
	cout << "The name of student is" << name << endl;
	cout << "The score of student is" << score << endl;
}
int main()
{
	char namei[15];
	int numberi;
	float scorei;
	cout << "Enter name";
	cin >> namei;
	cout << "Enter numberi";
	cin >> numberi;
	cout << "Enter score";
	cin >> scorei;
	Student stu(numberi, namei, scorei);
	stu.modify(100);
	stu.print();
	system("pause");
	return 0;
}*/
//��������


/*class Student
{
public:
	Student(int number1, char* name1, float score1);//���캯������
	~Student();//������������
	void modify(float score);
	void print();
private:
	int number;
	char name[15];
	Student* next;
	float score;
};

Student::Student(int number1, char* name1, float score1)//���캯������ ���캯��û�з�������
{
	number = number1;
	strcpy(name, name1);
	score = score1;
}
Student::~Student()//C++�в�������������������ֵ�����Ҳ������������������� ������������������
{
	delete[] name;
}
void Student::modify(float score1)
{
	score = score1;
}
void Student::print()
{
	cout << "Student's number is" << number << endl;
	cout << "The name of student is" << name << endl;
	cout << "The score of student is" << score << endl;
}
int main()
{
	char namei[15];
	int numberi;
	float scorei;
	cout << "Enter name";
	cin >> namei;
	cout << "Enter numberi";
	cin >> numberi;
	cout << "Enter score";
	cin >> scorei;
	Student stu(numberi, namei, scorei);
	stu.modify(100);
	stu.print();
	system("pause");
	return 0;
}*/
/*������
class timer
{
	int seconds;
public:
	timer(const char* t) {
		seconds = atoi(t);
	}
	timer(int t = 10)
	{
		seconds = t;
	}
	timer(int min, int sec)
	{
		seconds = min * 60 + sec;
	}
	void run();
};

void timer::run()
{
	clock_t t1;
	t1 = clock();
	while ((clock() / CLOCKS_PER_SEC - t1 / CLOCKS_PER_SEC) < seconds);

	cout << "\a";
}

int main()
{
	timer timer1(5), timer2("20"), timer3(1, 5);

	timer1.run();
	cout << "��ʱ��timer1ʱ�䵽��\n";
	timer2.run();
	cout << "������timer2��ʱ�䵽��\n";
	timer3.run();
	cout << "������timer3��ʱ�䵽��\n";
	system("pause");
	return 0;
}
*/

class Date
{
private:
	int day, month, year;
public:
	Date(int dd, int mm, int yy);//���캯��
	void print();
};
void Date::print()
{
	cout << "Year is" << year << "Moonth is" << month << "Day is" << day;
}
Date::Date(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
class Student
{
private:
	int number;
	char name[15];
	Date birthday;
	float score;
public:
	Student(int number1, const char*name1, float score1, int d1, int m1, int y1);
	void modify(float score1)
	{
		score = score1;
	}
	void print();
};
Student::Student(int number1, const char *name1, float score1, int d1, int m1, int y1) :birthday(d1, m1, y1)
{
	number = number1;
	strcpy(name, name1);
	score = score1;
}

void Student::print()
{
	cout << "number:" << number << "name:" << name << '\n';
	cout << "Student's birthday is" << endl;
	 birthday.print();
	 cout << "score is " << score << endl;
}

int main()
{
	Student stu1(15, "��װ�", 100, 1999, 2, 1);
	stu1.print();
	system("pause");
	return 0;
}

//