#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*int num[5] = { 1,2,3,4,5 };
int processed[3];
/*void combination(int start, int picked)
{
	if (picked == 3)
	{
		for (int i = 0; i < 3; ++i) cout << processed[i];
		cout << endl;
		return;
	}
	else
	{
		//5-3+picked是最右能到哪里，如果非常靠右，那么后面的数字就选不够了！
		for (int i = start; i <= 5 - 3 + picked; ++i)
		{
			processed[picked] = num[i];
			combination(i + 1, picked + 1);
		}
	}
}*/
bool JudgeIsPrime(int n);

int num[] = { 3,7,12,9 };
int processed[3];

void combination(int start, int picked)
{
	int count;
	if (picked == 3)
	{
		count = 0;
		for (int i = 0; i < 3; ++i)
		{
			cout << processed[i] << " ";
			count += processed[i];
		}
		cout << endl;
		if (JudgeIsPrime(count))
		{
			cout << count << endl;
		}
		return;
	}
	else
	{
		//5-3+picked是最右能到哪里，如果非常靠右，那么后面的数字就选不够了！
		for (int i = start; i <= 4 - 3 + picked; ++i)
		{
			processed[picked] = num[i];
			combination(i + 1, picked + 1);
		}
	}
}


bool JudgeIsPrime(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	combination(0, 0);
	cout << endl;
	system("pause");
	return 0;
}
