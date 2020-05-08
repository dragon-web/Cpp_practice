#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<functional>
using namespace std;

//函数模板可以重载

//数组类模板
/*
template <typename T, int I>

class CmyArry
{
private:
	T data[I];
public:
	int SetItem(int index, const T & item);
	int GetItem(int index, T & item);
};

template <class T>

class Stack
{
private:
	T* data;
	int size;
	int top;
	int IsEmpty()
	{
		return top <= 0 ? 1 : 0;
	}
	int IsFull()
	{
		return top >= size ? 1 : 0;
	}
public:
	Stack(int n)
	{
		date = new T[n];
		size = n;
		top = 0;
	}
	~Stack()
	{
		delete date;
	}
	void pop(T a);
	T push();
};

template<typename T>

T Stack<T>::push(T a)
{
}
int main()
{
	vector<int> ve = { 1,2,5,9,6 };
	priority_queue<int> dp;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < ve.size();++i)
	{
		dp.push(ve[i]);
		pq.push(ve[i]);
	}
	while (pq.size() > 0 )
	{
		int temp = pq.top();
		pq.pop();
		cout << temp<<endl;
	}
		
		system("pause");
	return 0;
}


int main()
{
	int *p = new int[36]();
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << p[j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}


//类模板

template<class T1,class T2>
class Pair
{
public:
	T1 key;
	T2 value;
	Pair(T1 k,T2 v):key(k),value(v){}
	bool operator<(const Pair<T1, T2> &p)const;
};

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p)const
{
	return key < p.key;
}

int main()
{
	Pair<string, int>student("Tom", 19);
	cout << student.key << " " << student.value;
	system("pause");
	return 0;
}

//函数模板作为类模板的成员
template<class T>
class A
{
public:
	template<class T2>
	void Func(T2 t)
	{
		cout << t;
	}
};

int main()
{
	A <int> a;
	a.Func('K');
	a.Func("Hello");
	system("pause");
	return 0;
}
*/

//可变长数组类模板

template <typename T>

class CArray
{
	int size;
	T* ptr;
public:
	CArray(int s = 0);
	CArray(CArray &a);
	~CArray();
	void push_bank(const T& v);
	CArry & operator = (const T& v);
	T length()
	{
		return size;
	}
	T &operator[](int i)
	{
		return ptr[i];
	}
};

template <typename T>
CArray<T>::CArray(int s) : size(s)
{
	if (s == 0)
		ptr = NULL;
	else
		ptr = new T[s];
}

template <typename T>
CArray<T>::CArray(CArray &a)
{
	if (!a.ptr)
	{
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new T[a.size];
	memcpy(ptr, a.ptr, sizeof(T)*a.size);
	size = a.size;
}

template <class T>

CArray<T>::~CArray()
{
	if (pyr)
		delete[] ptr;
}

template<class T>
CArray<T> &CArray<T>::operator=(const)