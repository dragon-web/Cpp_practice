#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
/*
A B C D E

A:�Һ�E��û�з�������
B���������Ǳ�C��E����һ��������ֵ�
C���������Ǳ��Һ�����һ��������ֵ�
D��B��Cû�з������̹���
E����û�з�������
//ֻ������˵�����滰

AΪ�� E��Ϊ��
BΪ����ôC��Ϊ��

CΪ�� DΪ��

DΪ��

*/
int main()
{
	int arr[5] = { 0 };
	for (int i = 0; i < 6; ++i)
	{
		arr[i] = 1;
		for (int j = 0; j < 6; ++j)
		{
			if (j != i)
			{
				arr[j] = 1;
			}
		}
		arr[i] = 0;
	}

	system("pause");
	return 0;
}