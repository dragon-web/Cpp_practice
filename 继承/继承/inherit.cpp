#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

//������Ա�ڻ����в������ʵ������������п��Ա�����
//classĬ�ϼ̳з�ʽ��˽�м̳�
//�����������Ը�ֵ������Ķ��󣬻�������ã������ָ��
//��������ܸ�ֵ�����������
//��Ԫ��ϵ���ܼ̳�,�������Ԫ���ܷ����������˽�г�Ա�ͱ�����Ա
//���ඨ���˸�staic��Ա�����������۹�����ٸ�ֻ����һ��staic��Ա
//����̳н���������ԺͶ����Ե�����
class Person
{
public:
	string _name; // ����
};
class Student :virtual public Person
{
protected:
	int _num; //ѧ�� 
};
class Teacher :virtual public Person
{
protected:
	int _id; // ְ�����
};
	class Assistant : public Student, public Teacher
	{
	protected:    string _majorCourse; // ���޿γ� 
	};
	void Test()
	{    // �������ж������޷���ȷ֪�����ʵ�����һ��   
		Assistant a;   
		a._name = "peter";        // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����  
		a.Student::_name = "xxx";
		a.Teacher::_name = "yyy";
		cout << a._name << endl;
	}
















int main()
{
	system("pause");
	return 0;
}