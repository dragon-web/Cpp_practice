#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include "mmsystem.h"
using namespace std;
/*
������Ա�ڻ����в������ʵ������������п��Ա�����
classĬ�ϼ̳з�ʽ��˽�м̳�
�����������Ը�ֵ������Ķ��󣬻�������ã������ָ��
��������ܸ�ֵ�����������
��Ԫ��ϵ���ܼ̳�,�������Ԫ���ܷ����������˽�г�Ա�ͱ�����Ա
���ඨ���˸�staic��Ա�����������۹�����ٸ�ֻ����һ��staic��Ա
����̳н���������ԺͶ����Ե�����
class Person
{
public:
	string _name; // ����
};
class Student :virtual public Person
{
protected:
	int _num; //ѧ�� 
};
class Teacher :virtual public Person
{
protected:
	int _id; // ְ�����
};
	class Assistant : public Student, public Teacher
	{
	protected:    string _majorCourse; // ���޿γ� 
	};
	void Test()
	{    // �������ж������޷���ȷ֪�����ʵ�����һ��   
		Assistant a;   
		a._name = "peter";        // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����  
		a.Student::_name = "xxx";
		a.Teacher::_name = "yyy";
		cout << a._name << endl;
	}


//���̳�
//1 ���м̳�

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
	int gety() const  //const�ĺ������ܶ������ݳ�Ա�����޸Ĳ���
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
//������Ա���м̳�
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

//����ı�����Ա���Ա�������ĳ�Ա�������ʣ����ǲ��ܱ��ⲿ��������
/*int main()
{
	derive obj;
	obj.setable(2, 4);
	obj.setc(3);
	obj.showabc();
	system("pause");
	return 0;
}


//˽�м̳�
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

//�ص㣺���ʻ����˽�г�Ա����Ҫͨ�������ӿ�������
//�����̳�

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
		y = n;//���ܷ���˽��
	}
};


void main()
{
	samp obj(20,30);
	//����obj.b������Ա����ͨ���ⲿ����ֱ�ӷ���
}
*/




int main()
{

	system("pause");
	return 0;
}