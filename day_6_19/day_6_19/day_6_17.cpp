#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		switch (i)
		{
			case 0:
			cout << i << endl;
			case 2:
				cout << i << endl;
			default:
				cout << i << endl;
		}

	}

	system("pause");
	return 0;
}