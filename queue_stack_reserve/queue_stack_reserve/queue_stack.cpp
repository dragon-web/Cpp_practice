#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>
#include<queue>

using namespace std;
//栈和对列的相互转换具体体现在能够用两个栈实现对列，能够用两个对列实现栈
/*
int main()
{
	int arr[] = { 1,8,6,7,9,3,3,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	stack<int> Stack1;
	stack<int> Stack2;

	for (int i = 0; i < sz; ++i)
	{
		Stack1.push(arr[i]);
	}
	for (int j = 0; j < sz; ++j)
	{
		Stack2.push(Stack1.top());
		Stack1.pop();
	}
	//实现队列取元素
	/*for (int i = 0; i < sz; ++i)
	{
		cout << Stack1.top();
		Stack1.pop();
	}
	cout << endl;
	for (int i = 0; i < sz; ++i)
	{
		cout << Stack2.top();
		Stack2.pop();
	}

	system("pause");
	return 0;
}
*/
//用两个队列实现栈
class MyStack {
private:
	queue<int> q;
public:
	MyStack() {}

	void push(int x) {
		q.push(x);
	}

	int pop() {
		int ans = q.back();
		queue<int> tmp;
		for (int i = q.size() - 1; i > 0; --i) {
			tmp.push(q.front());
			q.pop();
		}
		q = tmp;
		return ans;
	}

	int top() {
		return q.back();
	}

	bool empty() {
		return q.empty();
	}
};
//用两个栈实现队列
class MyQueue
{
private:
	stack<int> q;

public:
	bool empty()
	{
		return q.empty();
	}
	void push(int x)
	{
		q.push(x);
	}
	int front()
	{
		return q.top();
	}
	int back()
	{
		stack<int> temp;
		while (!q.empty())
		{
			temp.push(q.top());
			q.pop();
		}
		q = temp;
		return q.top();
	}
	void pop()//首出队，想研究尾出对可以用dequeue
	{
		q.pop();
	}
};



int main()
{

	/*MyStack mystack;
	int arr[] = { 1,2,3,5,2,2,45,54,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; ++i)
	{
		mystack.push(arr[i]);
	}
	mystack.pop();*/

	MyQueue myqueue;
	int arr[] = { 1,2,3,5,2,2,45,54,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; ++i)
	{
		myqueue.push(arr[i]);
	}
	myqueue.pop();
	int f = myqueue.front();
	int b = myqueue.back();
	system("pause");
	return 0;
}
