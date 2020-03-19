#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
 /*
class Test
{
private:
	int data;
public:
	Test() :data 
	{
		cout << "默认构造函数" << endl;
	}
	Test(int m_data) {
		cout << "构造函数" << endl;
		data = m_data;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
};

int main()
{
	Test a();
	Test b(2);
	Test c[3];
	Test &ra = b;
	Test d = b;
	Test *pA = c;
	Test* p = new Test(4);
	system("pause");
	return 0;
}

int Judge(int num)
{
	int sum = 0;
	while (num)
	{
		if ((num & 1) == 1)
		{
			sum++;
		}
	num = num >> 1;
	}
	return sum;
}



int main()
{
	int num;
	cin >> num;
	int p = Judge(num);
	cout << p << endl;
	system("pause");
	return 0;
}

template<class T>
class Stack
{
private:
	T* date;
	int size;
	int top;
	int IsEmpty()
	{
		return (top <= 0) ? 1 : 0;
	}
	int IsFull()
	{
		return (top >= size) ? 1 : 0;
	}
public:
	Stack(int n) {
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


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(float *a, float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void Swap(T& a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	void Swap(int& a,int& b);
	int i = 5;
	int j = 6;
	Swap(i, j);
	cout << i << j;
	char a = 'C';
	char b = 'J';
	Swap(a, b);
	cout << a << b;
	system("pause");
	return 0;
}

template<class T>
T abs(T value)
{
	return value = value > value ? value : -value;
}
 abs<double>(T&, T&);
int main()
{
	int nValue = -1, nResult = 2;
	abs(nValue, nResult);
	cout << nValue << nResult;
	system("pause");
	return 0;
}

template<class T>
int get_max(T a, T b)
{
	return a > b ? a : b;
}
int main()
{
	int a = 4;
	int b = 5;
	get_max(a, b);//隐式调用模板
	int c = 5, d = 3.56985;
	get_max<double>(c, d);
	system("pause");
	return 0;
}
函数模板

template<class T>
T Add(const T& left, const T&right)
{
	return left + right;
}


int main()
{
	int a = 5;
	int b = 6;
	cout<<Add(a, b) << endl;
	double c = 2.8525;
	double d = 6.2;
	cout << Add(c, d) << endl;
	cout << Add(a, (int)c) << endl;//方案一，强转
	cout<<Add<double>(a, c)<<endl;//显式调用
	system("pause");
	return 0;
}
*/
//类模板
template<class T>
class Vector
{
private:
	T*  p_data;
	size_t size;
	size_t capacity;
public:
	Vector(size_t capacity = 10) : _pData(new T[capacity]), size(0), capacity(_capacity)
	{}
	~Vector();
	void pushbank(T &data);
	void popbank(T &data);
};
//注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T> 
Vector<T>::~Vector()
{ if (_pData)
delete[] _pData;
_size = _capacity = 0; 
}
int main()
{
	Vector<int>s1;
	Vector<double>s2;
	system("pause");
	return 0;
}