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
//�ݹ顢λ����ʵ��
int ADD(int x, int y)
{
	if (y == 0)
		return x;
	int sum = x ^ y;             //��λ��ӣ�������λ��
	int carry = (x & y) << 1;  //ֻ����������ӵĽ�λ
	//����λ�벻����λ��ͣ����ڲ����üӷ������Եݹ飬��carryΪ0ʱ���أ�
	return ADD(sum, carry);
}
//λ����ǵݹ��
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
	//��ѭ����y=0ʱ������λΪ0������֮���Ѿ�����x�ϣ����Է���x����
	return x;
}
//ͨ��ָ���ƫ����������ʵ��
int ADD3(int x, int y)
{
	//����ָ����Կ��ɵ�ַ�����Կ��Խ�xתΪ��ַ��ʽͨ��ָ��ı���������y
	char *z = (char*)x;
	return (int)&z[y];  //z + sizeof(char)*y �ȼ��� x+y
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
		cout << "���캯��" << endl;
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
		cout << "��������" << endl;
	}
};
int main()
{
	Student stu1("�",2589641,15);
	stu1.display();
	system("pause");
	return 0;
}
*/


//�㷨����������������ļӷ�

int ADD3(int x, int y)
{
	//����ָ����Կ��ɵ�ַ�����Կ��Խ�xתΪ��ַ��ʽͨ��ָ�����������y
	char *z = (char*)x;
	return (int)&z[y];  //z + sizeof(char)*y �ȼ��� x+y
}
int ADD(int x, int y)
{
	if (y == 0)
		return x;
	int sum = x ^ y;             //��λ��ӣ�������λ��
	int carry = (x & y) << 1;  //ֻ����������ӵĽ�λ
	//����λ�벻����λ��ͣ����ڲ����üӷ������Եݹ飬��carryΪ0ʱ���أ�
	return ADD(sum, carry);
}
int main()
{
	cout << ADD(2, 85) << endl;
	system("pause");
	return 0;
}