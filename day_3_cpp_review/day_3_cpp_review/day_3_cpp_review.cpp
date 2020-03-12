#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string.h>
using namespace std;


/*int main()
{
	int a = 21;
	a ^= (1 << 5) - 1;
	int c = 9999;
	int count = 0;
	while (c)
	{
		count++;
		c = c & c - 1;
	}
	cout << count << endl;

	int i = 1;
	if (i <= 0)
		cout << "*****" << endl;
	else
		cout << "%%%%\n" << endl;

	system("pause");
	return 0;
}
//递归、位运算实现
int ADD(int x, int y)
{
	if (y == 0)
		return x;
	int sum = x ^ y;             //各位相加（不带进位）
	int carry = (x & y) << 1;  //只存两个数相加的进位
	//将进位与不带进位求和（由于不能用加法，所以递归，到carry为0时返回）
	return ADD(sum, carry);
}
//位运算非递归版
int ADD2(int x, int y)
{
	int sum = 0;
	int carry = 0;
	while (y != 0)
	{
		sum = x ^ y;
		carry = (x & y) << 1;
		x = sum;
		y = carry;
	}
	//当循环至y=0时，即进位为0，两数之和已经加至x上，所以返回x即可
	return x;
}
//通过指针的偏移量的特性实现
int ADD3(int x, int y)
{
	//由于指针可以看成地址，所以可以将x转为地址形式通过指针的便宜来加上y
	char *z = (char*)x;
	return (int)&z[y];  //z + sizeof(char)*y 等价于 x+y
}
*/
/*
class Student
{
private:
	char name[20];
	int number;
	int age;
public:
	Student(const char* name1,int number1,int age1)
	{
		cout << "构造函数" << endl;
		strcpy(name, name1);
		number = number1;
		age = age1;
	}

	void display()
	{
		cout << this->name << endl;
		cout <<this->number << endl;
		cout << this->age << endl;
	}
	~Student()
	{
		cout << "析构函数" << endl;
	}
};
int main()
{
	Student stu1("李华",2589641,15);
	stu1.display();
	system("pause");
	return 0;
}
*/


//算法：不用算数运算符的加法

int ADD3(int x, int y)
{
	//由于指针可以看成地址，所以可以将x转为地址形式通过指针遍历来加上y
	char *z = (char*)x;
	return (int)&z[y];  //z + sizeof(char)*y 等价于 x+y
}
int ADD(int x, int y)
{
	if (y == 0)
		return x;
	int sum = x ^ y;             //各位相加（不带进位）
	int carry = (x & y) << 1;  //只存两个数相加的进位
	//将进位与不带进位求和（由于不能用加法，所以递归，到carry为0时返回）
	return ADD(sum, carry);
}
int main()
{
	cout << ADD(2, 85) << endl;
	system("pause");
	return 0;
}