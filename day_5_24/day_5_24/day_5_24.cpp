#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
const int LENGTH = 10;

//静态数据成员
/*
class Point
{
private: 
		int x, y;
		static int count;
public:
	Point(int X = 0,int Y = 0):x(X),y(Y)
	{
		count++;
	}
	~Point()
	{
		count--;
	}
		int getx()
	{
			return x;
	}
		int gety()
		{
			return y;
		}
		void showCount()
		{
			cout << "Object count = " << count << endl;
		}

};
//注意要在外面进行操作
int Point::count = 0;

//静态成员函数

class Point
{
private:
	int x, y;
	static int count;
public:
	Point(int X = 0, int Y = 0) :x(X), y(Y)
	{
		count++;
	}
	~Point()
	{
		count--;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	static void showCount()//静态成员函数智能包含静态成员变量
	{
		cout << "Object count = " << count << endl;
	}

};
//注意要在外面进行操作
int Point::count = 0;
//new 和delete要成对出现

int main()
{
	Point ptr[3];
	Point * p = new Point[3];
	ptr[0].getx();
	delete[] p;
	system("pause");
	return 0;
}
*/

//对象指针和对象数组

//类的继承 ： 软件工程原则，一个模块只能有一个功能






int main()
{



	system("pause");
	return 0;
}