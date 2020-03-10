#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string.h>

using namespace std;

/*class Circle
{
private:
	float radius;
public:
	Circle(float r)
	{
		radius = r;
	}
	float GetArea()
	{
		return 3.14*radius*radius;
	}
};
/*
int main()
{
	Circle c1(3),*pc;
	pc = &c1;
	cout << pc->GetArea() << endl;
	cout << c1.GetArea() << endl;
	system("pause");
	return 0;
}
//对象指针域对象数组,this指针
class Square
{
private:
	int side;
public:
	void set(int x)
	{
		side = x;
	}
	void out()
	{
		cout << side << "\n";
	}
};

void f(Square &x)
{
	x.out();
	x.set(10);
	x.out();
}

int main()
{
	Square s;
	s.set(100);
	f(s);
	s.out();
	system("pause");
	return 0;
}
class mystring
{
private:
	char s[80];
public:
	void print()
	{
		cout << s << "\n";
	}
	void set(char *str)
	{
		strcpy(s, str);
	}
};

mystring input()
{
	char instr[80];
	mystring str;
	cout << "Enter a string";
	cin >> instr;
	str.set(instr);
	return str;
}


int main()
{
	mystring ob;
	char arr[] = "你这个大胖子";
	ob.set(arr);
	ob.print();
	ob = input();
	ob.print();
	system("pause");
	return 0;
}
*/

class Student
{
private:
	int number;
	char* name;
	float score;
	static int count;
	static float sum;
public:
	Student(int number1,const char* name1, float score1);
	~Student();
	void modify(float score1)
	{score = score1; }
	void print();
};

Student::Student(int number1, const char* name1, float score1)
{
	number = number1;
	name = new char[strlen(name1) + 1];//申请动态内存单元
	strcpy(name,name1);
	score = score1;
	count++;
	sum = sum + score;
}
Student::~Student()
{
	delete[]name;
	count--;
}
void Student::print()
{
	cout << number << ' ' << name << ' ' << score << ' ' << count << ' ' << sum << endl;
}
int Student::count = 0;//静态成员的变量应在创建类的对象前进行定义并初始化
float Student::sum = 0;

int main()
{
	Student stu1(1,"刘聪", 100);
	stu1.print();
	system("pause");
	return 0;
}