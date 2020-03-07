#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

/*int main()
{
	int *p;
	p = new int;
	if (!p)
	{
		cout << "Allocation error\n";
		return 1;
	}
	*p = 1000;
	cout << "Here is integer at p:" << *p << "\n";
	delete p;
	system("pause");
	return 0;
}
*/

/*void f(int a[], int n, int *max, int *min)
{
	*max = *min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (*max < a[i])
			*max = a[i];
		if (*min > a[i])
			*min = a[i];
	}
}


int main()
{
	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
	int max, min;
	f(a, 10, &max, &min);
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
	system("pause");
	return 0;
}*/
//����������ĳ�������Ϊ�����ĳ���
/*
void f(int a[], int n, int &max, int &min)
{
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i]) { max = a[i]; }
		if (min > a[i]) { min = a[i]; }
	}
}


int main()
{
	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
	int max, min;
	f(a, 10, max, min);
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
	system("pause");
	return 0;
}
class Student
{
private:
	int number;
	char name[15];
	float score;
public:
	void init(int number1, char* name1, float score1);
	void modify(float score1)
	{
		score = score1;
	}
	void print();
};
void Student::init(int number1, char* name1, float score1)
{
	number = number1;
	strcpy(name, name1);
	score = score1;
}
void Student::print()
{
	cout << "number = " << number;
	cout << "name = " << name;
	cout << "score = " << score<<endl;
}


int main()
{
	int number1;
	float score1;
	char name1[15];
	int number2,  score2;
	char name2[15];
	Student stu1, stu2;
	cout << "please input number:" << endl;
	cin >> number1;
	cout << "please input name:" << endl;
	cin >> name1;
	cout << "please input score:" << endl;
	cin >> score1;

	stu1.init(number1, name1, score1);
	stu1.print();

	       
	system("pause");
	return 0;
}



int main()
{
	int temp;
	stack<int> mystack;
	int num;
	int N;
	char s;
	cout<<"��������Ҫת���Ľ�����"<<endl;
	cin>>num;
	cout<<"��������Ҫת����Ϊ�Ľ���"<<endl;
	cin>>N;
	while (num != 0)
	{
		temp = num % N;
		num /= N;
		if (temp < 10)
		{
			mystack.push(temp);
		}
		else if (temp >= 10)
		{
			switch (temp)
			{
			case 10:
				s = 'A';
				break;
			case 11:
				s = 'B';
				break;
			case 12:
				s = 'C';
					break;
			case 13:
				s = 'D';
				break;
			case 14:
				s = 'E';
				break;
			case 15:
				s = 'F';
				break;
			}
			mystack.push(s);
		}
	}
	while (!mystack.empty()) {
		cout << mystack.top();
		mystack.pop();
	}
	system("pause");
	return 0;
}
*/


int main()
{
	char temp;
	stack<int> mystack;
	int num;
	int N;
	cout << "��������Ҫת���Ľ�����" << endl;
	cout << "��������Ҫת����Ϊ�Ľ���" << endl;
	cin >> num >> N;
	while (num != 0)
	{
		temp = num % N;
		num /= N;

		mystack.push(temp);
	}
	while (!mystack.empty()) {
		cout << mystack.top();
		mystack.pop();
	}
	system("pause");
	return 0;
}