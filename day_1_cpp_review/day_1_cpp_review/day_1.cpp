#include<iostream>
using namespace std;

/*int main()
{
	int *p;
	p = new int;
	if (!p)
	{
		cout << "Allocation error\n";
		return 1;
	}
	*p = 1000;
	cout << "Here is integer at p:" << *p << "\n";
	delete p;
	system("pause");
	return 0;
}
*/

/*void f(int a[], int n, int *max, int *min)
{
	*max = *min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (*max < a[i])
			*max = a[i];
		if (*min > a[i])
			*min = a[i];
	}
}


int main()
{
	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
	int max, min;
	f(a, 10, &max, &min);
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
	system("pause");
	return 0;
}*/
//将上述程序改成引用作为参数的程序
/*
void f(int a[], int n, int &max, int &min)
{
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i]) { max = a[i]; }
		if (min > a[i]) { min = a[i]; }
	}
}


int main()
{
	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
	int max, min;
	f(a, 10, max, min);
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
	system("pause");
	return 0;
}*/

          