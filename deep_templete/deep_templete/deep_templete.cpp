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
*/

