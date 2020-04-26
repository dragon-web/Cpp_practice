#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
//派生类的构造函数和析构函数
/*
class Animal
{
public:
	Animal()//构造函数
	{
		cout << "constring Animal" << endl;
	}
	~Animal()
	{
		cout << "destructing Animal" << endl;
	}
	void setm(int a = 0)
	{
		age = a;
	}
	int getage()
	{
		return age;
	}
private:
	int age;
};

class Dog:public Animal
{
public:
	void setd(int a)
	{
		setm(a);
	}
	Dog()
	{
		cout << "constructing Dog" << endl;
	}
	~Dog()
	{
		cout << "destorying Dog" << endl;
	}
};
int main()
{
	Dog d;
	d.setd(2);
	cout << d.getage() << endl;
	system("pause");
	return 0;
}


class stud
{
protected:
	int num;
	 char name[10];
	 char sex;
public:
	stud(int n,const char nam[], const char s)
	{
		num = n;
		strcpy(name, nam);
		sex = s;
	}
	~stud()
	{
		cout << "destory stud" << endl;
	}
};

class student : public stud
{
private:
	int age;
	char add[30];
public:
	student(int n,char nam[], char s, int a, char ad[]) :stud(n, nam, s)
	{
		age = a;
		strcpy(add, ad);
	}

	void show()
	{
		cout <<"num:"<< num << endl;
		cout << "name" << name << endl;
		cout << "sex" << sex << endl;
		cout << "age" << age << endl;
		cout << "address" << add << endl;
	}
	~student()
	{
		cout << "destory student" << endl;
	}
};

int main()
{
	
	char name[] = "libai";
	char Sex[] = "男";
	student a(ab,name,Sex , 19, "151北京胡同");
	a.show();
	system("pause");
	return 0;
}



class A
{
public:
	void f()
	{
		cout << "A" << endl;
	}
};
class B
{
public:
	void f()
	{
		cout << "B" << endl;
	}
};
class C :public A, public B
{
public:
	C()
	{
		cout << "constrcting C" << endl;
	}
};
int main()
{
	C c;
	c.A::f();
	c.B::f();
	system("pause");
	return 0;
}


class A
{
public:
	void fun()
	{}
};
class B :public A
{
public:
	void funb(){}
};
class C :public A
{
public:
	void func(){}
};
class D :public B, public C
{
public:
	void fund() {}
};
*/

class A
{
protected:
	int x;
public:
	A(int a)
	{
		x = a;
		cout << "调用A的构造函数" << endl;
	}
	~A()
	{}

	int getX()const { return x; }
};
class B :virtual public A
{
public:
	B() :A(1)
	{
		cout << "调用B的构造函数" << endl;
	}
	~B()
	{};
};
class C:virtual public A
{
public:
	C() :A(2) { cout << "构造类C的构造函数" << endl; }
	~C() {};
};
class D :public B, private C
{
public:
	D(int d) :A(d) { cout << "调用D的构造函数" << endl; }
	~D() {};
};
int main()
{
	D d(3);

	system("pause");
	return 0;
}