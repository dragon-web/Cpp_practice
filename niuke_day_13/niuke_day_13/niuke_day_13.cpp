#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
using namespace std;

/*class Bonus {
public:
	int getMost(vector <vector<int>> board) {
		for(int i = 0;i < board.size())
		board[][]
	}
};*/

int five(int n)
{
	int sum = 0;
	while (n % 5 == 0 && n >= 5)
	{
		++sum;
		n /= 5;
	}
	return sum;
}
int main()
{
	int sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (i % 10 == 0)
		{
			sum += i % 10;
			sum += five(i);
		}
		else if (i % 5 == 0)
		{
			sum += five(i);
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}