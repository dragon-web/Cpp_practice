#include<iostream>
using namespace std;
/*
int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			num = num & (num - 1);
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}


/*
#include<iostream>
using namespace std;
int main()
{
	int num = 0;
	cin >> num;
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}
*/
using namespace std;
int main()
{
	int a = 1 & 2 & 3 || 4;
	cout << a << endl;
	system("pause");
	return 0;
}