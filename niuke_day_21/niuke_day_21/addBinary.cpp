#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
using namespace std;

string AddBinary(string &a, string &b)
{
		string res;
		int carry = 0;         //��ʾ��λ
		int x, y;
		int i = a.size() - 1, j = b.size() - 1;
		for (; i >= 0 || j >= 0; i--, j--) {
			x = i >= 0 ? a[i] - '0' : 0;
			y = j >= 0 ? b[j] - '0' : 0;
			res += (x + y + carry) % 2 + '0';
			carry = (x + y + carry) / 2;
		}
		if (carry)   res += '1';
		reverse(res.begin(), res.end());
		return res;
}

int main()
{
	string a, b;
	cin >> a >> b;
	string res = AddBinary(a, b);
	cout << res << endl;
	system("pause");
	return 0;
}