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
}
//�±������
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Judge(vector<string> &dp)
{
	for (int i = 0; i < dp.size(); i++)
	{
		int j = 0;
		auto it = dp[i].begin();
		while (j < dp[i].length())
		{
			if (j+5 < dp[i].length())
			{
				if ((dp[i].at(j) == dp[i].at(j+1) && dp[i].at(j + 2) ==dp[i].at(j+3)&& dp[i].at(j+4) == dp[i].at(j + 5)))
				{
					dp[i].erase(it + 2);
					continue;
				}
			}
			if ((j + 2) < dp[i].length())
			{
				if ((dp[i].at(j) == dp[i].at(j + 1) && (dp[i].at(j+1) == dp[i].at(j + 2))))
				{
					dp[i].erase(it + 2);
					continue;
				}
			}
			if ((j + 3) < dp[i].length())
			{
				if (dp[i].at(j) == dp[i].at(j + 1)&& (dp[i].at(j + 2) == dp[i].at(j + 3)))
				{
					dp[i].erase(it+3);
					continue;
				}
			}
			j++;
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
	system("pause");
	return 0;
}
*/

//�����СӲ����

int Defalt(int N)
{
	int count = 1024 - N;
	int num = 0;
	while (count >= 0)
	{
		count -= 64;
		num++;
	}
	count = count+64;//�ҵ��Ǹ��ٽ�
	num -= 1;
	while (count>=0)
	{
		count -= 16;
		num++;
	}
	count = count + 16;//�ҵ��Ǹ��ٽ�
	num -= 1;
	while (count>=0)
	{
		count -= 4;
		num++;
	}
	count = count + 4;//�ҵ��Ǹ��ٽ�
	num -= 1;
	while (count>=0)
	{
		count -= 1;
		num++;
	}
	count = count + 1;//�ҵ��Ǹ��ٽ�
	num -= 1;
	return num;
}


int main()
{
	int N;
	cin >> N;
	int b = Defalt(N);
	cout << b << endl;

	system("pause");
	return 0;
}