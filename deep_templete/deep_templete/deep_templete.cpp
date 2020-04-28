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
对于非模板函数和同名函数模板，
如果其他条件都相同，在调动时会优先调用非模板函数而
不会从该模板产生出一个实例。
如果模板可以产生一个具有更好匹配的函数，
那么将选择模板


//模板函数不能自动类型转换

//类模板
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10) : _pData(new T[capacity]), _size(0), _capacity(capacity) {}
	// 使用析构函数演示：在类中声明，在类外定义。
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

