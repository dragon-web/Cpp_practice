#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*     vector
int main()
{
	vector<char> v;//不说明默认长度为0
	vector<int> b;//创建个有5个元素的int类型vector对象
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
	string s3(s2);//调用拷贝构造函数
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
//用迭代器的方式来访问
int main()
{
	string str("Be quiet");
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << endl;
		it++;
	}
	//begin指向第一个数据，rbegin指向最后一个数据
	string::reverse_iterator s = str.rbegin();
	while (s != str.rend())//注意反向迭代器
	{
		cout << *s << " " << endl;
		s++;     
	}
	//for循环访问
	for (auto ch:str)
	{
		cout << ch << endl;
	}
	system("pause");
	return 0;
}

