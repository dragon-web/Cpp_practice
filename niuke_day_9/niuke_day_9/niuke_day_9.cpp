#define _CRT_SECURE_NO_WARNINGS 
/*#include<iostream>
#include<string.h>
using namespace std;
/*
void swap(string::iterator head, string::iterator tail)
{
	string::iterator temp = head;
	head = tail;
	tail = temp;
}

string Reverse(string& arr)
{
	string::iterator head = arr.begin();
	string::iterator tail = arr.end();

	while (head <= tail)
	{
		swap(head, tail);
		head++;
		tail--;
	}
	return arr;
}

int main()
{
	string arr("abcd");
	Reverse(arr);
	string::iterator it = arr.begin();
	for(size_t i = 0;i < arr.size();++i)
	cout << *it << endl;
	system("pause");
	return 0;
}

void Reverse(char* arr)
{
	size_t sz = strlen(arr);
	//char* p = (char*)malloc(sz);
	size_t head = 0;
	size_t tail = sz - 1;
	while (head <= tail)
	{
		char temp = arr[head];
		arr[head] = arr[tail];
		arr[tail] = temp;
		head++;
		tail--;
	}
}
int main()
{
	char arr[] = "abcdefg";
	Reverse(arr);
	cout << arr << endl;
	system("pause");
	return 0;
}


#include<iostream>
#include<string.h>
using namespace std;
void Reverse(char* arr)
{
	size_t sz = strlen(arr);
	//char* p = (char*)malloc(sz);
	size_t head = 0;
	size_t tail = sz - 1;
	while (head <= tail)
	{
		char temp = arr[head];
		arr[head] = arr[tail];
		arr[tail] = temp;
		head++;
		tail--;
	}
}
int main()
{
	string s;
	while (cin>>s);
	{
		Reverse();
		cout << *arr;
	}
	system("pause");
	return 0;
}
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		cout << s[i];
	}
	return 0;
}