#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

//保护成员在基类中不被访问但是在派生类中可以被访问
//class默认继承方式是私有继承
//派生类对象可以赋值给基类的对象，基类的引用，基类的指针
//基类对象不能赋值给派生类对象
//友元关系不能继承,基类的友元不能访问派生类的私有成员和保护成员
//基类定义了个staic成员，则子类无论构造多少个只有这一个staic成员
//虚拟继承解决了冗余性和二义性的问题
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
















int main()
{
	system("pause");
	return 0;
}