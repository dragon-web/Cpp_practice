#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include <Windows.h>
using namespace std;

//review virtual function and polymorphic
/*
class Base1
{
public:
	void display()
	{
		cout << "Base1:: display()"<<endl;
	}
};
class Base2:public Base1
{
	void display()
	{
		cout << "Base2::display" << endl;
	}
};
class Derived : public Base2
{
public:
	void display()
	{
		cout << "Derived :: display" << endl;
	}
};
void fun(Base1 *ptr)
{
	ptr->display();
}
*/

class Base {
public:
	~Base() {
		cout << "~Base()" << endl;
	}
};
class Derived1 : public Base {
public:
	Derived1() :name_(new string("NULL")) {}
	Derived1(const string& n) :name_(new string(n)) {}

	~Derived1() {
		delete name_;
		cout << "~Derived1(): name_ has been deleted." << endl;
	}

private:
	string* name_;
};

class Derived2 : public Base {
public:
	Derived2() :name_(new string("NULL")) {}
	Derived2(const string& n) :name_(new string(n)) {}

	~Derived2() {
		delete name_;
		cout << "~Derived2(): name_ has been deleted." << endl;
	}

private:
	string* name_;
};



int main()
{
	Derived1* d1 = new Derived1();
	Derived2 d2 = Derived2("Bob");
	delete d1;//需要手动释放这个空间
	/*
	Base1 base1;
	Base2 base2;
	Derived derived;
	fun(&base1);
	fun(&base2);
	fun(&derived);
	system("pause");
	return 0;
	*/
}


/*
class CILHook
{
public:
	CILHook();
	~CILHook();
	BOOL Hook(LPSTR pszModuleName, LPSTR pszFunname, PROC pfnHook);
	VOID Unhook();
	BOOL ReHook();
private:
	PROC m_pfnOrig;
	BYTE m_bOldBytes[5];
	BYTE m_bNewBytes[5];
};

CILHook::CILHook()
{
	m_pfnOrig = NULL;
	ZeroMemory(m_bNewBytes, 5);
	ZeroMemory(m_bOldBytes, 5);
}
CILHook::~CILHook()
{
	Unhook();
}
VOID CILHook::Unhook()
{
	if (m_pfnOrig != 0)
	{
		DWORD dwNum = 0;
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bOldBytes, 5, &dwNum);
	}
}
BOOL CILHook::Hook(LPSTR pszModuleName, LPSTR pszFuncName, PROC pfnHookFunc)
{
	BOOL bRet = FALSE;
	m_pfnOrig = GetProcAddress(GetModuleHandle((LPCSTR)pszModuleName), pszFuncName);
	if (m_pfnOrig != NULL)
	{
		DWORD dwNum = 0;
		ReadProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bOldBytes, 5, &dwNum);
		m_bNewBytes[0] = '\xe9';
		*(DWORD*)(m_bNewBytes + 1) = (DWORD)pfnHookFunc - (DWORD)m_pfnOrig - 5;
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bNewBytes, 5, &dwNum);
		bRet = TRUE;
	}
	return bRet;
}
BOOL CILHook::ReHook()
{
	BOOL bRet = FALSE;
	if (m_pfnOrig != 0)
	{
		DWORD dwNum = 0;
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bNewBytes, 5, &dwNum);
		bRet = TRUE;
	}
	return bRet;
}
*/
