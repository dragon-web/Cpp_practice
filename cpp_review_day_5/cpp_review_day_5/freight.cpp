#define _CRT_SECURE_NO_WARNINGS 
#include<string.h>
#include<iostream>
using namespace std;
/*
class complex
{
private:
	double real;
	double imag;
public:
	complex(double r = 0.0, double i = 0.0)
	{
		real = r;
		imag = i;
	}
	void display();
	complex operator +(const complex &c);//二元加重载成员函数
	complex operator -(const complex &c);//二元减重载成员函数
	complex operator - ();//一元重减载成员函数
	friend complex operator-(const complex &c1, const complex &c2);//二元重载减友元函数
	friend complex operator-(const complex &c);//一元重载减友元函数
	friend complex operator+(const complex &c1, const complex &c2);//二元重载加友元函数
};

void complex::display()
{
	cout << "real = " << real << endl;
	cout << "imag = " << imag << endl;
}
complex complex::operator+(const complex &c)
{
	double r = real + c.real;
	double i = imag + c.imag;
	return complex(r, i);
}

complex complex::operator-(const complex &c)
{
	double r = real- c.real;
	double i = imag - c.imag;
	return complex(r, i);
}
complex complex::operator-()
{
	return complex(-real, -imag);
}



int main()
{
	complex a(1.5,52.2), b(2.3,63.2);
	complex c = a + b;
	complex d = -a;
	d   .display();
	c.display();
	system("pause");
	return 0;
}




class complex
{
private:
	double real;
	double imag;
public:
	complex(double r = 0.0, double i = 0.0)
	{
		real = r;
		imag = i;
	}
	void display();
	friend complex operator-(const complex &c1, const complex &c2);//二元重载减友元函数
	friend complex operator-(const complex &c);//一元重载减友元函数
	friend complex operator+(const complex &c1, const complex &c2);//二元重载加友元函数
};

void complex::display()
{
	cout << "real = " << real << endl;
	cout << "imag = " << imag << endl;
}

complex operator-(const complex &c1, const complex &c2)
{
	double r = c1.real - c2.real;
	double i = c1.imag - c2.imag;
	return complex(r, i);
}
complex operator-(const complex &c)
{
	double r = -c.imag;
	double i = -c.real;
	return complex(r,i);  
}
complex operator+(const complex &c1, const complex &c2)
{
	double r = c1.real + c2.real;
	double i = c1.imag + c2.imag;
	return complex(r, i);
}

int main()
{
	complex a(1.5, 52.2), b(2.3, 63.2);
	complex c = a + b;
	complex d = -a;
	d.display();
	c.display();
	system("pause");
	return 0;            
}
*/

/*
class test
{
private:
	int t1, t2;
public:
	test(int num1, int num2);
	test operator++();//后置加加
	test operator--();//后置减减
	test operator++(int);//前置加加
	test operator--(int);//前置减减
	void display();
};

test::test(int num1, int num2)
{
	t1 = num1;
	t2 = num2;
}
test test::operator++()
{
	++t1;
	++t2;
	return *this;
}

test test::operator--()
{
	--t1;
	--t2;
	return *this;
}
void test::display()
{
	cout << "t1 = " << t1 << endl;
	cout << "t2 = " << t2 << endl;
}
test test::operator++(int)
{
	int temp1 = t1;
	int temp2 = t2;
	t1++;
	t2++;
	return test(temp1,temp2);
}
test test::operator--(int)
{
	int temp1 = t1;
	int temp2 = t2;
	t1--;
	t2--;
	return test(temp1, temp2);
}
int main()
{

	system("pause");
	return 0;
}
*/

class String
{
private:
	char* ptr;
public:
	String( char* s)
	{
		ptr = new char[strlen(s) + 1];
		strcpy(ptr, s);
	}
	~String()
	{
		delete ptr;
	}
	void print()
	{
		cout << ptr << endl;
	}
	String &operator =  ( String & s);//函数返回引用更为有效
};

String &String::operator=(String &s )
{
	if (this == &s)
	{
		return *this;
	}
	else {
		delete ptr;
		ptr = new char[strlen(s.ptr) + 1];
		strcpy(ptr, s.ptr);
		return *this;
	}
}

int main()
{
	char* str = (char*)"你好";
	String p1(str);
	char* str1 =(char*) "我美吗";
	String p2(str1);
	p1 = p2;
	p1.print();
	system("pause");
	return 0;
}




















/*
class Base
{
public :
	int Bar(char x)
	{
		return (int)x;
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};

class Derived :public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};

int main()
{
	Derived obj;
	Base *pobj = &obj;
	printf("%d  ", pobj->Bar((char)(100)));
	printf("%d ", pobj->Bar(100));


	system("pause");
	return 0;
}*/
