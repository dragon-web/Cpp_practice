#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

int Atoi(char* str)
{
	int number = 0;
	while (*str != 0)
	{
		number = number * 10 + *str - '0';
	}
	return number;
}
/*
1:传入指针是否为空
2：正负号
3：超出整数范围
4：非法字符
*/
long long StrToInt(const char* str, bool minus);

int atoi(const char* str)
{
	//给一个比较大的数据类型，方便处理溢出
	long long num = 0;
	//判断指针是否为空，以及是否有有效字符
	if (str != nullptr && *str != '\0')
	{
		//是否为负数
		bool minus = false;
		if (*str == '+')
			++str;
		else if (*str == '-')
		{
			++str;
			minus = true;
		}
		if (*str != '\0')
		{
			num = StrToInt(str, minus);
		}
	}
	return (int)num;
}

long long StrToInt(const char* str, bool minus)
{
	long long num = 0;
	while (*str != '\0')
	{
		//判断是否为有效字符
		if (*str >= '0' && *str <= '9')
		{
			//判断正负数
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*str - '0');
			//判断是否溢出,包括正溢出和负溢出
			if ((!minus && num > 0x7fffffff)
				|| (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			++str;
		}
		else
		{
			num = 0;
			break;
		}
	}
	return num;
}


int main()
{

	system("pause");
	return 0;
}