#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;

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
	complex operator - ();//一元重载成员函数
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
	c.display();
	system("pause");
	return 0;
}