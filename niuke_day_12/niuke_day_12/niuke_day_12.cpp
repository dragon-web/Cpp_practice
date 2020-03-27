#define _CRT_SECURE_NO_WARNINGS 
/*
#include<iostream>
#include<vector>
using namespace std;

//找最大公约数
int FindMaxCom(int num1, int num2)
{
	int temp = 0;
	int temp1 = 0;
	int min = num1 > num2 ? num2 : num1;//找到小的那个数
	int max = num1 < num2 ? num2 : num1;
	if (max % min == 0)
		return min;
	else
	{
		for (int i = 1; i < min; ++i)
		{
			if (num1 % i == 0 && num2 % i == 0)
				temp1 = i;
			temp = temp > temp1 ? temp : temp1;
		}
	}
	return temp;
}
int Judge(int *arr, int num, int Begin)
{
	for (int p = 0; p < num; p++)
	{
		if (Begin >= arr[p])
		{
			Begin += arr[p];
		}
		else {
			int temp2 = FindMaxCom(Begin,arr[p]);
			Begin += temp2;
		}
	}
	return Begin;
}
int main()
{
	int num, Begin, monster;
	cin >> num >> Begin;
	int *p = (int *)malloc(sizeof(int)*num);
	for (int k = 0; k < num; ++k)
	{
		cin >> monster;
			p[k] = monster;
	}
	int q = Judge(p, num, Begin);
	cout << q << endl;
	system("pause");
	return 0;
}
*/
//找只出现一次的字符

#include<iostream>
#include<string>
using namespace std;

string JudgeOnce(string &str)
{
	string a;
	for (int i = 0; i < str.size()-1; ++i)
	{
		for (int j = i+1; j < str.size(); ++j)
		{
			str[i] == str[j];
		}
	}


}


int main()
{
	string str;
	cin >> str;
	JudgeOnce(str);
	system("pause");
	return 0;
}

/*
#include<stdio.h>
#include<Windows.h>
char findOnceChar(char *str) {
	char result = '\0';

	int array[256];

	for (int i = 0; i < 256; i++) {
		array[i] = 0;
	}

	char *current = str;
	while (*current != '\0') {
		array[*current]++;
		current++;
	}

	// 重新指向字符串头部
	current = str;

	// 遍历字母出现的次数
	while (*current != '\0') {
		if (array[*current] == 1) {
			result = *current;
			break;
		}
		current++;
	}

	return result;
}

int main()
{
	char arr[100];
	while (scanf("%s", arr))
	{
		findOnceChar(arr);
	}
	system("pause");
	return 0;
}
*/