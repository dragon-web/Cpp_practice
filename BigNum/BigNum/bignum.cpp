#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
using namespace std;
/*
class A
{
public:
	A()
	{

	}
	void setName(const string& s) 
	{
		ss = new const char(s.c_str());
		strcpy(ss, s.c_str());
		ss = s.c_str();
		cout << &ss << endl;
	}
	void getss()
	{
		cout << *ss << endl;
	}
	const char* ss;
};
int main()
{
	A a1;
	a1.setName("anbcd");
	cout << &a1.ss << endl;
	a1.getss();
	string a("abcd");
	system("pause");
	return 0;
}



class A
{
public:
	A(const string& s)
	{
		const char *p = s.c_str();
		cout << &p << endl;
		ss = (char*)p;
	}
void setName()
	{
		
	}
	void getss()
	{
		cout << ss << endl;
	}
private:
	char* ss;
};

int main()
{
	A a1("anbcd");
	a1.getss();
	system("pause");
	return 0;
}*/
/*
 #include<iostream>
#include<string>
 using namespace std;

 class A
 {
   public:
	       A()
		       {
		
		       }
	       void setName(const string& s) //const 
		         {
		               ss = (const char*)s.c_str();
		                   cout << &ss << endl;
		
			         }
	            const char* ss;
	
		 };

 int main()
 {
	     A a1;
	     a1.setName("anbcd");
	     cout << &a1.ss << endl;
	     cout << a1.ss << endl;
		 system("pause");
	     return 0;
 }
 

class A
{
private:
	char *s;
public:
	void Solution(string &ori)
	{
		s = (char*)ori.c_str();
	}
	void cout_s()
	{
		cout << s << endl;
	}
};

int main()
{
	string s;
	cin >> s;
	A a;
	a.Solution(s);
	a.cout_s();

	system("pause");
	return 0;
}
*/

class A
{
public:
	A()
	{

	}
	void setName(const string& s) //const 
	{
		ss = s.c_str();
		cout << &ss << endl;
	}
	
	const char* ss;
};
int main()
{
	A a1;
	string tmp("anbcd");
	a1.setName(tmp);
	//a1.setName("anbcd");
	cout << &a1.ss << endl;
	cout << a1.ss << endl;
	system("pause");
}
