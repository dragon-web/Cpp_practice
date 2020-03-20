#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

/*     vector
int main()
{
	vector<char> v;//��˵��Ĭ�ϳ���Ϊ0
	vector<int> b;//��������5��Ԫ�ص�int����vector����
	vector<int>(5);
	int i;
	for (i = 0; i < 10; ++i)
	{
		v.push_back('A'+i);
	}
	for (i = 0; i < 10; i++)
	{
		cout << v[i] << " " << endl;
	}
	system("pause");
	return 0;
}


//string




int main()
{
	string s1;
	string s2("Hello Word");
	string s3(s2);//���ÿ������캯��
	cout << s3.size();

	string s;
	s.reserve(100); 
	size_t sz = s.capacity(); 
	cout << "making s grow:\n"; 
	for (int i = 0; i < 100; ++i) 
	{
		s.push_back('c');   
	if (sz != s.capacity())
	{ sz = s.capacity();        
	cout << "capacity changed: " << sz << '\n'; 
	} 
	}

	system("pause");
	return 0;
}

//�õ������ķ�ʽ������
int main()
{

	string str("Be quiet");
	cout << str.find('e') << endl;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << endl;
		it++;
	}
	system("pause");
	return 0;
}
	//beginָ���һ�����ݣ�rbeginָ�����һ������
/*	string::reverse_iterator s = str.rbegin();
	while (s != str.rend())//ע�ⷴ�������
	{
		cout << *s << " " << endl;
		s++;     
	}
	//forѭ������
	for (auto ch:str)
	{
		cout << ch << endl;
	}
	str.resize(10, 'Z');//���λ����Z���
	str.resize(5);
	cout << str;
	for (auto ant : str)
	{
		cout << ant<<endl;
	}
	str.clear();
	string str("Please shut up");
	str.resize(20, 'A');
	cout<<str.operator[](2);//ʵ���Ϸ��ʵ��ǵ������ַ�
	system("pause");
	return 0;
}
*/
//ţ����string����ϰ
/*
class Solution {
public:
	int StrToInt(string str) {
	double value = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				continue;
			}
			if ((str[i] > '0'&&str[i] < '9'))
			{
				value *= 10;
				value += str[i] - '0';
				double p = pow(2, 31) - 1;
				double p1 = -pow(2, 31);
				if (str[0] == '-')
				{
					if (-value < p1)
					{
						return 0;
					}
				}
				else
				{
					if (value > p)
						return 0;
				}
			}
			else {
				return 0;
			}
		}
		return (int) str[0] == '-'? -value:value;

	}
};

int main()
{
	Solution ans;
	string sub("-2147483648");
	cout << ans.StrToInt(sub) << endl;


	system("pause");
	return 0;
}

int main()
{
	string str("string.cpp");
	size_t pos = str.rfind('.');
	cout << str.substr(pos) << endl;//����������Խ�ȡ��׺
	string url("http://www.cplusplus.com/reference/string/string/find/"); 
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)//�ж�Ѱ�ҵ��ַ��Ƿ���Ч
	{
	cout << "invalid url" << endl;   
	}
	start += 3; 
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	system("pause");
	return 0;
}
*/

//�ַ��������������Ƴ���ֻ�ʺ�λ����ͬ�ļӷ�
/*class Solution {
public:
	string addStrings(string num1, string num2) {
		size_t len = num1.length() > num2.length() ? num1.length() : num2.length();
		string mystring;
		mystring.resize(len + 1, '0');
		for (int i = len; i > 0; --i)
		{
			int temp1 = num1[i-1] - '0';
			int temp2 = num2[i-1] - '0';
			int temp = (temp1 + temp2) % 10;
			if (int res = (temp1 + temp2) / 10)
			{
				mystring[i-1] = '1';
			}
			int temp3 = (mystring[i] - '0' + temp);
			mystring[i] = temp3 + '0';
		}
		if (mystring[0] == '0')
		{
			string::iterator it = mystring.begin();
			mystring.erase(it);
		}
		return mystring;
	}
};

int main()
{
	Solution A;
	string str1("952");
	string str2("952");
	cout << A.addStrings(str1, str2) << endl;
	system("pause");
	return 0;
}
*/
�ķ�~~
������ 1 ����ǰ

530
C++

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		int ln1 = num1.length() - 1;
		int ln2 = num2.length() - 1;
		int carry = 0;
		//����һ�����ַ�����һ�ߺ�����������ַ�
		string c = "";
		while (carry == 1 || ln1 >= 0 || ln2 >= 0)
		{
			//zһ��Ҫ��num1��num2�ֿ����ǣ���ֹ������������λ����ͬ�����ִ���
			int x = ln1 < 0 ? 0 : num1[ln1--] - '0';
			int y = ln2 < 0 ? 0 : num2[ln2--] - '0';
			//�ǵô˴�ת��Ϊchar�ͣ��Լ������'0'
			c.insert(0, 1, char(x + y + carry) % 10 + '0');
			//carry��ʾ��λ
			carry = (x + y + carry) / 10;
		}
		return c;
	}
};

int main()
{
	system("pause");
	return 0;
}