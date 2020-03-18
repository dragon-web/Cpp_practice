#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
 /*
class Test
{
private:
	int data;
public:
	Test() :data 
	{
		cout << "默认构造函数" << endl;
	}
	Test(int m_data) {
		cout << "构造函数" << endl;
		data = m_data;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
};

int main()
{
	Test a();
	Test b(2);
	Test c[3];
	Test &ra = b;
	Test d = b;
	Test *pA = c;
	Test* p = new Test(4);
	system("pause");
	return 0;
}
*/
int Judge(int num)
{
	int sum = 0;
	while (num)
	{
		if ((num & 1) == 1)
		{
			sum++;
		}
	num = num >> 1;
	}
	return sum;
}



int main()
{
	int num;
	cin >> num;
	int p = Judge(num);
	cout << p << endl;
	system("pause");
	return 0;
}