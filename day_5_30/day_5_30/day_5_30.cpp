#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>

class String
{
public:
	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	
	~String()
	{
		/*free(_str);
		_str = nullptr;*/
		delete[] _str;
	}
private:
	char* _str;
};
void test()
{
	String s("str");
}
int main()
{
	test();
	system("pause");
	return 0;
}