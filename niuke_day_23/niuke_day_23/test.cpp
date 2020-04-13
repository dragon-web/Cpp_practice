#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
enum string {
	x1,
	x2,
	x3 = 10,
	x4,
	x5,
} x;
/*void perm(int list[], int k, int m)
{
	if ()
	{
		copy(list, list + m, ostream_iterator<int>(cout, " "));
		cout << endl;
		return;
	}
	for (int i = k; i <= m; i++)
	{
		swap(&list[k], &list[i]);
		();
		swap(&list[k], &list[i]);
	}
}

int sum(int a)
{
	auto int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}*/
int sum(int a)
{
 int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}
int main()
{
		int i;
		int a = 2;
		for (i = 0; i < 5; i++)
		{
			printf("%d,", sum(a));
		}
	int *p1 = new int[10];
	int *p2 = new int[10]();
	cout << x << endl;
	system("pause");
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
	char *myString()
	{
		char buffer[6] = { 0 };
		const char *s = "Hello World!";
		size_t p = sizeof(buffer) - 1;
		for (int i = 0; i < p; i++)
		{
			buffer[i] = *(s + i);
		}
		return buffer;
	}
	int main(int argc, char **argv)
	{
		printf("%s\n", myString());
		system("pause");
		return 0;
	}
	*/