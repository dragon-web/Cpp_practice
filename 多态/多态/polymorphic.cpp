#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string.h>
using namespace std;
/*一个名字定义不同的函数
在编译是能确定的信息就采用静态联编，不能就采用动态联编
1：编译时多态性：通过函数重载、运算符重载、模板实现
2：运行时多态性：借助虚函数实现

using namespace std;
class fruit
{
public:
	fruit()
	{}
	~fruit()
	{}
	virtual void dispFruitName()
	{
		cout << "It is fruit class" << endl;
	}
	virtual void eatFruitName()
	{
		cout << "can't eat abstract fruit" << endl;//抽象水果
	}
};
class Apple :public fruit
{
private:
	char cAppleName[20];
public:
	Apple(){}
	~Apple(){}
	void getAppleName(char applename[20])
	{
		strcpy(cAppleName, applename);
	}
	void dispAppleName()
	{
		cout << "The Apple name is :" << endl;
	}
	void dispFruitName()
	{
		cout << "The fruitname is apple" << endl;
	}
	void eatFruit()
	{
		cout << "Oh! It is some acid" << endl;
	}
};
class Banana :public fruit
{
private:
	char cBananaName[20];
public:
	Banana() {}
	~Banana() {}
	void getBananaName(char Banananame[20])
	{
		strcpy(cBananaName, Banananame);
	}
	void dispBananaName()
	{
		cout << "The Banana name is :" << endl;
	}
	void dispFruitName()
	{
		cout << "The fruitname is Banana" << endl;
	}
	void eatFruit()
	{
		cout << "Oh! It is some sweet" << endl;
	}
};
int main()
{
	fruit myfruit, *ptrfruit;
	Apple myapple, *ptrapple;
	Banana myBanana, *ptrBanana;
	system("pause");
	return 0;
}
class shape
{
public:
	virtual float area()
	{
		return -1;
	}
};
class circle :public shape
{
private:
	float radious;
public:
	 circle(float r)
	{
		 radious = r;
	}
	 float area()
	 {
		 return 3.14158*radious*radious;
	 }
};

int main()
{
	shape obj, *ptr;
	circle c(3.6);
	ptr = &obj;
	cout << ptr->area() << endl;
	ptr = &c;
	cout << ptr->area() << endl;
	system("pause");
	return 0;
}
基类定义中必须把成员函数定义为虚函数
派生类中，虚函数被重新定义时，函数原型与基类中的函数原型必须完全相同
虚函数声明只出现在类声明的函数原型声明中，在派生类中可以以不显示的声明为虚函数 
必须使用基类的指针（或者引用）访问虚函数，此时多态性才能实现
虚函数必须在继承体系下实现
虚函数必须是其所在类的成员函数
虚函数不能是友元函数
虚函数不能是静态成员函数
内联函数不能是虚函数，因为虚函数在类的内部定义，在编译时仍然看做是内联的
构造函数不能是虚函数但是析构函数可以是虚函数
一个虚函数无论被继承多少次仍保持虚函数特性
*/

//虚函数和重载函数的关系

class base
{
public:
	virtual void func1();
	virtual void func2();
	virtual void func3();
	void  fun4();
};

class derived:public base
{
public:
	virtual void func1();//虚函数，可省略func1
	void func2(int x);//普通函数重载，虚特性消失
	//char func3();
	void func4();//重载函数
};


void main()
{
	base d1, *bp;
	derived d2;
	bp = &d2;
	bp->func1();//调用derived::func1()
	bp->func2();//调用base::func2()
	bp->func3();//调用base::fun3()

	system("pause");
}