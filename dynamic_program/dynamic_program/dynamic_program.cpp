#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<Windows.h>
#include<string.h>
/*
int f(int i, int j, int(*a)[4])
{
	int f1, f2, tmp = 0, k;
	if (i == 0 || j == 0)
		return a[0][0];
	if (j == i)
	{
		for (k = 0; k <= i; k++)
			tmp += a[k][k];
		return tmp;
	}
	f1 = f(i - 1, j, a);
	f2 = f(i - 1, j - 1, a);
	if (f1 < f2)
		return f2 + a[i][j];
	else
		return f1 + a[i][j];
}

int main()
{

	system("pause");
	return 0;
}
*/
//拿短的去匹配长的
/*
void printcom(char* arr1,char*arr2)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int temp1 = 0;
	size_t length1 = strlen(arr1);
	size_t length2 = strlen(arr2);
	for (i = 0; i < length1; ++i)
	{
		for (j = 0; j < length2; ++j)
		{
			if (arr2[j] == arr1[i])
			{
				j++;
				i++;
				temp++;
			}
//判断连续与否
		}

	}
}
*/
void printcom(char* arr1, char*arr2)
{
	size_t length1 = strlen(arr1);
	size_t length2 = strlen(arr2);
	int temp = 0;
	int** p = (int**)malloc(length1*sizeof(int));
	for (int k = 0; k < length1; ++k)
		p[k] = (int*)malloc(sizeof(int)*length2);
	for (int i = 0; i < length1; ++i)
	{
		for (int j = 0; j < length2; ++j)
		{
			p[i][j] = 0;
			if (arr1[i] == arr2[j])
			{
				p[i][j] = 1;
				if (i > 0 && j > 0)
				{
					p[i][j] += p[i - 1][j - 1];
				}
				
			}
			if (p[i][j] > temp)
			{
				temp = p[i][j];
			}
		}
	}
	printf("%d", temp);
}
int main()
{
	char arr1[100];
	char arr2[100];
	scanf("%s", arr1);
	scanf("%s", arr2);
	printcom(arr1, arr2);

	system("pause");
	return 0;
}
//char** q = (char**)malloc(length1*length2);
