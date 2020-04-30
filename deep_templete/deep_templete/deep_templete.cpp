#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>

using namespace std;
template<class T> 

T Add(T left, T right)
{
	return left + right;
}
/*
���ڷ�ģ�庯����ͬ������ģ�壬
���������������ͬ���ڵ���ʱ�����ȵ��÷�ģ�庯����
����Ӹ�ģ�������һ��ʵ����
���ģ����Բ���һ�����и���ƥ��ĺ�����
��ô��ѡ��ģ��


//ģ�庯�������Զ�����ת��

//��ģ��
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10) : _pData(new T[capacity]), _size(0), _capacity(capacity) {}
	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector();
	size_t Size() { return _size; }

	T& operator[](size_t pos) 
	{
	assert(pos < _size);
	return _pData[pos]; 
	}
	void PushBack(const T& data);
	void PopBack();
	private:
	T* _pData; 
	size_t _size;
	size_t _capacity;
	
};

template<class T> void Vector<T>::PopBack()
{

}

template <class T> Vector<T>::~Vector() 
{ 
	if (_pData)  
	delete[] _pData;
	_size = _capacity = 0; 
}

template<typename Type>
int main()
{
	cout << Add(1, 2) << endl;
	Vector<int> s1;
	Vector<double> s2;

	system("pause");
	return 0;
}

template <typename T>//���Ǿ��������typename

T Abs(T value)
{
	return value > 0 ? value : -value;
}
int main()
{
	int nValue = -1, nResult;
	double dbValue = -1.3, dblResult;
	nResult = Abs(nValue);
	dblResult = Abs(dbValue);
	cout << nResult << "  " << dblResult << endl;
	system("pause");
	return 0;
}


template <typename Type>

Type max(Type a, Type b)
{
	return a > b ? a : b;
}

template <typename Type>

Type max(Type a, Type b, Type c)
{
	Type t;
	t = a > b ? a : b;
	return t > c ? t : c;
}
int main()
{
	
	system("pause");
	return 0;
}*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Judge(vector<string> &dp)
{
	for (int i = 0; i < dp.size(); i++)
	{
		auto it = dp[i].begin();
		while (it < dp[i].end())
		{
			if ((it + 5) < dp[i].end())
			{
				if ((*it == *(it + 1) && *(it + 2) == *(it + 3) && *(it + 4) == *(it + 5)))
				{
					dp[i].erase(it + 2);
					continue;
				}
			}
			if ((it + 3) < dp[i].end())
			{
				if (*it == *(it + 1) && *(it + 2) == *(it + 3))
				{
					dp[i].erase(it + 2);
					continue;
				}
			}
			if ((it + 2) < dp[i].end())
			{
				if (*it == *(it + 1) && *(it + 1) == *(it + 2))
				{
					dp[i].erase(it);
					continue;
				}
			}
			it++;
		}
		cout << dp[i] << endl;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<string> p(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> p[i];
	}
	Judge(p);
	return 0;
}