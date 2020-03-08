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
//一个类可以用指向自身类型的指针或引用作为数据成员

class Student
{
public:
	Student(int number1, char* name1, float score1);//构造函数声明
	void modify(float score);
	void print();
private:
	int number;
	char name[15];
	Student* next;
	float score;
};

Student::Student(int number1, char* name1, float score1)//构造函数定义 构造函数没有返回类型
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
//析构函数


/*class Student
{
public:
	Student(int number1, char* name1, float score1);//构造函数声明
	~Student();//析构函数声明
	void modify(float score);
	void print();
private:
	int number;
	char name[15];
	Student* next;
	float score;
};

Student::Student(int number1, char* name1, float score1)//构造函数定义 构造函数没有返回类型
{
	number = number1;
	strcpy(name, name1);
	score = score1;
}
Student::~Student()//C++中不允许析构函数带返回值，并且不允许析构函数带参数 析构函数不允许重载
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
/*计数器
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
	cout << "计时器timer1时间到。\n";
	timer2.run();
	cout << "计数器timer2的时间到。\n";
	timer3.run();
	cout << "计数器timer3的时间到。\n";
	system("pause");
	return 0;
}
*/

class Date
{
private:
	int day, month, year;
public:
	Date(int dd, int mm, int yy);//构造函数
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
	Student stu1(15, "李白白", 100, 1999, 2, 1);
	stu1.print();
	system("pause");
	return 0;
}

//