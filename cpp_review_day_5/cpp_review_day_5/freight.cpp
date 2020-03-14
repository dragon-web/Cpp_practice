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
	complex operator +(const complex &c);//��Ԫ�����س�Ա����
	complex operator -(const complex &c);//��Ԫ�����س�Ա����
	complex operator - ();//һԪ���س�Ա����
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