#include<iostream>
#include<string.h>

using namespace std;
/*class Control
{
private:
	static int resource;
public:
	int get_source();
	void free_recource()
	{
		resource = 0;
	}
};
int Control::get_source()
{
	if (resource)
		return 0;
	else
	{
		resource = 1;
		return 1;
	}
}

int Control::resource = 0;

int main()
{
	Control ob1, ob2;
	if (ob1.get_source())
		cout << "ob1 has resource" << endl;
	if (!ob2.get_source())
		cout << "ob2 denied by resource" << endl;
	ob1.free_recource();
	if (ob2.get_source())
		cout << "ob2 can use resource now.\n";
	system("pause");
	return 0;
}*/
//使用全局变量可以实现数据共享，但是违背了面向对象封装行的原则，因此使用静态变量可以很好的实现
//静态数据成员主要用途在于定义类的各个对象所共用的数据

//静态成员函数: 只使用静态数据成员的函数可以定义成静态成员函数，静态成员函数不具有this指针

//类的友元 分为友元函数和友元类


/*
class Point
{
private:
	double X;
	double Y;
public:
	Point(double xi, double yi)
	{
		X = xi;
		Y = yi;
	}
	double GetX()
	{
		return X;
	}
	double GetY()
	{
		return Y;
	}
	friend double Distance(Point& a, Point& b);
};

double Distance(Point& a, Point& b)
{
	double dx = a.X - b.X;
	double dy = a.Y - b.Y;
	return sqrt(dx*dx + dy * dy);
}

int main()
{
	Point p1(3.0, 5.0), p2(4.0, 6.0);
	double d = Distance(p1, p2);
	cout << "The distance is" << d << endl;
	system("pause");
	return 0;
}*/
//友元类
class A
{
private:
	int a;
public:
		friend class B;
};
class node
{
private:
	int data;
	node* next;
public:
	node(int d, node* n = 0)
	{
		data = d;
		next = n;
	}
	friend class list;
};

class list
{
private:
	node* head;
	node* tail;
	size_t length;
public:
	list()//拷贝构造函数
	{
		head = 0;
		tail = 0;
	}
	~list()
	{
		while (head)
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void push_bank(int x)
	{
		if (length == 0)
		{
			node* p = new node(x);
		head = tail = p;
		}
		else
		{
			node* p = new node(x);
			tail->next = p;
			tail = p;
		}
		length++;
		tail->next = NULL;
	}
	void pop_bank(int x)
	{
		if (length == 0)
		{
			node* p = new node(x);
			head = tail = p;
		}
		else
		{
			node*p = new node(x);
			p->next = head;
			head = p;
		}
		length++;
	}
	void ListShow()
	{
		node *q = head;
		while(q)
		{
			cout << q->data << "-->";
			q = q->next;
		}
	}
};

int main()
{
	list mylist;
	mylist.pop_bank(1);
	mylist.pop_bank(2);
	mylist.pop_bank(3);
	mylist.ListShow();
	system("pause");
	return 0;
}


