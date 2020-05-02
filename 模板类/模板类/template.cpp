#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<queue>
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
*/



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