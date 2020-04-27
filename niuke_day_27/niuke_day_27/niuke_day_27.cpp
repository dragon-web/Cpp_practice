#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include <vector>
using namespace std;
/*
class A
{
	int i;
};
class B
{
	A* p;
public:
	B() { p = new A; }
	~B() { delete p; }
};
void sayHello(B b)
{}
int main()
{
	B b;
	system("pause");
	return 0;
}

int main(void) 
{
	vector<int>array; 
	array.push_back(100);
	array.push_back(300); 
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for(itor=array.begin();itor!=array.end();itor++)
	{  if(*itor==300)
	{   itor=array.erase(itor);  
	}
	} 
	for(itor=array.begin();itor!=array.end();itor++)
	{  
		cout<<*itor<<"";
	}
	system("pause");
	return 0;
}
*/
int main(int argc, char *argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b; c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = ""; if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	system("pause");
	return 0;
}
