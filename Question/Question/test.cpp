#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;
//str1插入到str2的n号上面去
char* f(const char * & str1, const char * & str2, size_t n)
{
	size_t length1 = strlen(str1);
	size_t length2 = strlen(str2);
	char * p = (char*)malloc(length1 + length2+1);
	char *temp1 = (char*)malloc(n);
	for (size_t i = 0; i < n; ++i)
	{
		temp1[i] = str2[i];
	}
	const char* q = (str2 + n);
	strcpy(p, temp1);
	for (size_t k = 0; k < length1; k++)
	{
		p[k + n] = str1[k];
	}
	for (size_t j = n; j < length2; j++)
	{
		p[j + length1] = str2[j];
	}
	p[length1 + length2] = '\0';
	return p;
}
int main()
{
	const char * str1 = "The website address of our university is:";
	const char * str2 = "www.xupt.edu.cn";
	char* p = f(str1, str2, 4);
	cout << p << endl;
	system("pause");
	return 0;
}
