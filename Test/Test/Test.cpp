#define _CRT_SECURE_NO_WARNINGS 
//判断一个数的树根
#include<iostream>
#include<string>
using namespace std;
/*int Solution(int num)
{
	int count = 0;
		while (num)
		{
			count += num % 10;
			num /= 10;
		}
		if (count > 9)
		{
			return Solution(count);
		}
		return count;
}
int main()
{
	int num = 0;
	string str;
	while (cin >> str)
	{
		num = 0;
		for (auto & i : str)
		{
			num += (i - '0');
		}

		cout << Solution(num) << endl;
		
	}
	system("pause");
	return 0;
}
*/

#include<iostream>
#include<string>
using namespace std;
int rootofnumber(int n)
{
	int number1 = 0;
	while (n > 0) {
		number1 += n % 10;
		n /= 10;
	}
	if(number1 > 9) {
		return rootofnumber(number1);
	}
	return number1;
}
int main()
{
	string number;
	while (cin >> number) {
		int sum = 0;
		for (size_t i = 0; i < number.size(); ++i) {
			sum += number[i] - '0';
		}
		cout << rootofnumber(sum) << endl;
	}
	return 0;
}