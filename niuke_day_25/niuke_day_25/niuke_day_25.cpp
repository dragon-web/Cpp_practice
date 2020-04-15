#define _CRT_SECURE_NO_WARNING

#include<iostream>
using namespace std;
int main()
{
	/*long a = (long)(((int*)0) + 4);
	cout << a << endl;
	char c = 'c';
	int i = (int)c;
	cout << i << endl;*/
	int i = 1;
	printf("%d %d", ++i, ++i);
	printf("%d %d", ++i, i++);
	system("pause");
	return 0;
}