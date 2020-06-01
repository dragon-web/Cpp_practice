#define _CRT_SECURE_NO_WARNINGS 
// write your code here cpp
/*#include<iostream>

using namespace std;

bool JudgeIsPrim(int &x)
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int arr[100] = { 0 };
	int num;
	int count = 0;
	while (cin >> num)
	{
		for (int i = 2; i <= num; ++i)
		{
			if (num %i == 0 && JudgeIsPrim(i))
			{
				arr[count++] = i;
			}
		}
		cout << num << "=";
		for (int i = 0; i < count; ++i)
		{
			cout << arr[i] << "*";
		}
	}
	return 0;
}
*/


// write your code here cpp
#include<iostream>

using namespace std;

bool JudgeIsPrim(int &x)//ÅÐ¶ÏËØÊý
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		int arr[100] = { 0 };
		int temp = num;
		for (int i = 2; i <= temp; ++i)
		{
			if (temp %i == 0 && JudgeIsPrim(i))
			{
				arr[count++] = i;
				temp /= i;
				while (temp % i == 0)
				{
					temp /= i;
					arr[count++] = i;
				}
			}
		}
		cout << num << " = ";
		for (int i = 0; i < count; ++i)
		{
			if (i == count - 1)
			{
				cout << arr[i] << endl;
			}
			else
			{
				cout << arr[i] << " * ";
			}
		}
	}
	system("pause");
	return 0;
}