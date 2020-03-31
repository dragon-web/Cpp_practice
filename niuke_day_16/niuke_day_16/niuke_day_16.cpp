#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		if (number > 2)
		{
			return jumpFloorII(number - 1) + jumpFloorII(number - 2);
		}
		else if (number == 1)
		{
			return 1;
		}
		else if (number == 2)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
};
int main()
{
	Solution a;
	int num;
	while (cin >> num)
	{
		cout << a.jumpFloorII(num) << endl;
	}
	system("pause");
	return 0;
}


/*
#include<iostream>
using namespace std;

void Judge(long long r, long long length)
{
	if (length > 3.14*2*r)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
}

int main()
{
	long long r,length;
	while (cin >> length >> r)
	{
		Judge(r, length);
	}

	return 0;
}*/