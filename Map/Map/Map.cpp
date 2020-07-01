#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	pair<int,string> pv1 = { 1,"Student" }; 
	pair<int, string> pv2 = { 2,"Teacher" };
	pair<int, string> pv3 = { 3,"Firend" };
	pair<int, string> pv4 = { 4,"Bit" };
	pair<int, string> pv5 = { 5,"helloworld" };

	//cout << pv1.first << pv2.second << endl;
	map<int, string> ismap;
	ismap.insert(pv1);
	ismap.insert(pv2);
	ismap.insert(pv3);
	ismap.insert(pv4);
	ismap.insert(pv5);
	for (const auto& e : ismap)
	{
		cout << e.first << ": " << e.second << endl;
	}
	auto it = ismap.begin();
	while (it != ismap.end())
	{
		cout << it->first << ": " << it->second << endl;
		it++;
	}
	//手动定义迭代器
	cout << "**********************************" << endl;
	map<int, string>::iterator it1 = ismap.begin();
	while (it1 != ismap.end())
	{
		cout << it1->first << ": " << it1->second << endl;
		it1++;
	}
	cout << ismap[2] << endl;//通过重载方括号来访问

	//ismap.clear();
	ismap.erase(ismap.begin(), ismap.end());
	auto it2 = ismap.begin();
	if (it2 == ismap.end())
	{
		cout << "数据已经被清空" << endl;
	}
	else
	{
		cout << "数据没有被清空" << endl;
	}
	system("pause");
	return 0;
}