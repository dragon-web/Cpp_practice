#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;
//�ж�һ�����Ƿ��ǻ�����
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		else
		{
			int count = 1;
			int temp1 = x;
			while (temp1/10)
			{
				temp1 /= 10;
				count++;
			}
			int count1 = count;
			int *p = (int*)malloc(sizeof(int)*count);
			int temp = 0;
			while (x)
			{
				temp = x % 10;
				x /= 10;
				p[count - 1] = temp;
					count--;
			}
			int first = 0, last = count1 - 1;
			while (first <= last)
			{
				if (p[first] == p[last])
				{
					first++;
					last--;
				}
				else
					return false;
			}
			return true;
		}
		
	}
};

int main()
{
	//int a[][3] = { {0,,2},{},{3,4,5} };һ�����ſ��ԣ������������Ų���
	//string s1, s2;
	//int arr[][4] = { {1},{3,2},{4,5,6},{0} };
	//cout << arr[1][2] << endl;
	Solution a;
	int num = 11;
	if (a.isPalindrome(num) == true)
		cout << "������" << endl;
	else
	{
		cout << "���ǻ�����" << endl;
	}

	system("pause");
	return 0;
}