#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string.h>
using namespace std;
/*һ�����ֶ��岻ͬ�ĺ���
�ڱ�������ȷ������Ϣ�Ͳ��þ�̬���࣬���ܾͲ��ö�̬����
1������ʱ��̬�ԣ�ͨ���������ء���������ء�ģ��ʵ��
2������ʱ��̬�ԣ������麯��ʵ��

using namespace std;
class fruit
{
public:
	fruit()
	{}
	~fruit()
	{}
	virtual void dispFruitName()
	{
		cout << "It is fruit class" << endl;
	}
	virtual void eatFruitName()
	{
		cout << "can't eat abstract fruit" << endl;//����ˮ��
	}
};
class Apple :public fruit
{
private:
	char cAppleName[20];
public:
	Apple(){}
	~Apple(){}
	void getAppleName(char applename[20])
	{
		strcpy(cAppleName, applename);
	}
	void dispAppleName()
	{
		cout << "The Apple name is :" << endl;
	}
	void dispFruitName()
	{
		cout << "The fruitname is apple" << endl;
	}
	void eatFruit()
	{
		cout << "Oh! It is some acid" << endl;
	}
};
class Banana :public fruit
{
private:
	char cBananaName[20];
public:
	Banana() {}
	~Banana() {}
	void getBananaName(char Banananame[20])
	{
		strcpy(cBananaName, Banananame);
	}
	void dispBananaName()
	{
		cout << "The Banana name is :" << endl;
	}
	void dispFruitName()
	{
		cout << "The fruitname is Banana" << endl;
	}
	void eatFruit()
	{
		cout << "Oh! It is some sweet" << endl;
	}
};
int main()
{
	fruit myfruit, *ptrfruit;
	Apple myapple, *ptrapple;
	Banana myBanana, *ptrBanana;
	system("pause");
	return 0;
}
class shape
{
public:
	virtual float area()
	{
		return -1;
	}
};
class circle :public shape
{
private:
	float radious;
public:
	 circle(float r)
	{
		 radious = r;
	}
	 float area()
	 {
		 return 3.14158*radious*radious;
	 }
};

int main()
{
	shape obj, *ptr;
	circle c(3.6);
	ptr = &obj;
	cout << ptr->area() << endl;
	ptr = &c;
	cout << ptr->area() << endl;
	system("pause");
	return 0;
}
���ඨ���б���ѳ�Ա��������Ϊ�麯��
�������У��麯�������¶���ʱ������ԭ��������еĺ���ԭ�ͱ�����ȫ��ͬ
�麯������ֻ�������������ĺ���ԭ�������У����������п����Բ���ʾ������Ϊ�麯�� 
����ʹ�û����ָ�루�������ã������麯������ʱ��̬�Բ���ʵ��
�麯�������ڼ̳���ϵ��ʵ��
�麯����������������ĳ�Ա����
�麯����������Ԫ����
�麯�������Ǿ�̬��Ա����
���������������麯������Ϊ�麯��������ڲ����壬�ڱ���ʱ��Ȼ������������
���캯���������麯���������������������麯��
һ���麯�����۱��̳ж��ٴ��Ա����麯������
*/

//�麯�������غ����Ĺ�ϵ

class base
{
public:
	virtual void func1();
	virtual void func2();
	virtual void func3();
	void  fun4();
};

class derived:public base
{
public:
	virtual void func1();//�麯������ʡ��func1
	void func2(int x);//��ͨ�������أ���������ʧ
	//char func3();
	void func4();//���غ���
};


void main()
{
	base d1, *bp;
	derived d2;
	bp = &d2;
	bp->func1();//����derived::func1()
	bp->func2();//����base::func2()
	bp->func3();//����base::fun3()

	system("pause");
}