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
1:����ָ���Ƿ�Ϊ��
2��������
3������������Χ
4���Ƿ��ַ�
*/
long long StrToInt(const char* str, bool minus);

int atoi(const char* str)
{
	//��һ���Ƚϴ���������ͣ����㴦�����
	long long num = 0;
	//�ж�ָ���Ƿ�Ϊ�գ��Լ��Ƿ�����Ч�ַ�
	if (str != nullptr && *str != '\0')
	{
		//�Ƿ�Ϊ����
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
		//�ж��Ƿ�Ϊ��Ч�ַ�
		if (*str >= '0' && *str <= '9')
		{
			//�ж�������
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*str - '0');
			//�ж��Ƿ����,����������͸����
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