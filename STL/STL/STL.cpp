#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
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
*/
//�õ������ķ�ʽ������
int main()
{
	string str("Be quiet");
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << endl;
		it++;
	}
	//beginָ���һ�����ݣ�rbeginָ�����һ������
	string::reverse_iterator s = str.rbegin();
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
	system("pause");
	return 0;
}

