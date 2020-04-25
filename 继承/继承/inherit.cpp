#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include "mmsystem.h"
using namespace std;
/*
保护成员在基类中不被访问但是在派生类中可以被访问
class默认继承方式是私有继承
派生类对象可以赋值给基类的对象，基类的引用，基类的指针
基类对象不能赋值给派生类对象
友元关系不能继承,基类的友元不能访问派生类的私有成员和保护成员
基类定义了个staic成员，则子类无论构造多少个只有这一个staic成员
虚拟继承解决了冗余性和二义性的问题
class Person
{
public:
	string _name; // 姓名
};
class Student :virtual public Person
{
protected:
	int _num; //学号 
};
class Teacher :virtual public Person
{
protected:
	int _id; // 职工编号
};
	class Assistant : public Student, public Teacher
	{
	protected:    string _majorCourse; // 主修课程 
	};
	void Test()
	{    // 这样会有二义性无法明确知道访问的是哪一个   
		Assistant a;   
		a._name = "peter";        // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决  
		a.Student::_name = "xxx";
		a.Teacher::_name = "yyy";
		cout << a._name << endl;
	}


//单继承
//1 公有继承

class A
{
private:
	int y;
protected:
	int x;
public:
	void setx(int m)
	{
		x = m;
	}
	void sety(int n)
	{
		y = n;
	}
	int getx() const
	{
		return x;
	}
	int gety() const  //const的函数不能对其数据成员进行修改操作
	{
		return y;
	}
};

class B:public A
{
public:
	int getsum()
	{
		return x + gety();
	}
};
//保护成员公有继承
class base
{
protected:
	int a, b;
public:
	void setable(int m, int n)
	{
		a = m;
		b = n;
	}
};
class derive :public base
{
	int c;
public:
	void setc(int n)
	{
		c = n;
	}
	void showabc()
	{
		cout << a << " " << b << " " << c << endl;
	}
};

//基类的保护成员可以被派生类的成员函数访问，但是不能被外部函数访问
/*int main()
{
	derive obj;
	obj.setable(2, 4);
	obj.setc(3);
	obj.showabc();
	system("pause");
	return 0;
}


//私有继承
class C :private A
{
public:
	void setBx(int m)
	{
		x = m;
	}
	void setBy(int n)
	{
		int n;
	}
	int getBx() const
	{
		return getx();
	}
	int getBy()
	{
		return gety();
	}
	int getsum()
	{
		return x + gety();
	}
};

//特点：访问基类的私有成员还是要通过函数接口来访问
//保护继承

class samp
{
private:
	int a;
protected:
	int b;
public:
	int c;
	samp(int n, int m)
	{
		a = n;
		b = m;
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
};

class D :protected A
{
public:
	void setBx(int m)
	{
		x = m;
	}
	void setBy(int n)
	{
		y = n;//不能访问私有
	}
};


void main()
{
	samp obj(20,30);
	//不能obj.b保护成员不能通过外部函数直接访问
}
*/




int main()
{

	system("pause");
	return 0;
}