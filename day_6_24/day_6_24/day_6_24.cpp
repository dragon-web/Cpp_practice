#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<Windows.h>

int main()
{
	int i;
	char arr[10];
	for (i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 26 + 'A';
		printf("%c ", arr[i]);
	}
	
	system("pause");
	return 0;
}