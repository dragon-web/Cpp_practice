#define _CRT_SECURE_NO_WARNING

#include<iostream>
using namespace std;
int main()
{
	long a = (long)(((int*)0) + 4);
	cout << a << endl;
	char c = 'c';
	int i = (int)c;
	cout << i << endl;
	system("pause");
	return 0;
}