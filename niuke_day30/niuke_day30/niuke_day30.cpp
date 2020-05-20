#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
int num[5] = { 1,2,3,4,5 };
int processed[3];
/*void combination(int start, int picked)
{
	if (picked == 3)
	{
		for (int i = 0; i < 3; ++i) cout << processed[i];
		cout << endl;
		return;
	}
	else
	{
		//5-3+picked�������ܵ��������ǳ����ң���ô��������־�ѡ�����ˣ�
		for (int i = start; i <= 5 - 3 + picked; ++i)
		{
			processed[picked] = num[i];
			combination(i + 1, picked + 1);
		}
	}
}
bool JudgeIsPrime(int n);

int num[] = { 3,7,12,9 };
int processed[3];

void combination(int start, int picked)
{
	int count;
	if (picked == 3)
	{
		count = 0;
		for (int i = 0; i < 3; ++i)
		{
			cout << processed[i] << " ";
			count += processed[i];
		}
		cout << endl;
		if (JudgeIsPrime(count))
		{
			cout << count << endl;
		}
		return;
	}
	else
	{
		//5-3+picked�������ܵ��������ǳ����ң���ô��������־�ѡ�����ˣ�
		for (int i = start; i <= 4 - 3 + picked; ++i)
		{
			processed[picked] = num[i];
			combination(i + 1, picked + 1);
		}
	}
}


bool JudgeIsPrime(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	combination(0,0);
	cout << endl;
	system("pause");
	return 0;
}
*/
/*
typedef struct BinTreeNode
{
	int data;
	BinTreeNode *leftChild;
	BinTreeNode *RightChild;
}BinTreeNode;

typedef struct Bin

int main()
{

	system("pause");
	return 0;
}*/


#include <iostream>
#include <queue>    //������ 
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
queue<string>q1, q2;

class BinaryTree;//���� 
class BinaryTreeNode;//���ڵ��� 

class BinaryTreeNode
{
	friend class BinaryTree;
public:
	BinaryTreeNode() { L = NULL; R = NULL; }//���캯������������
	BinaryTreeNode(string &an, BinaryTreeNode *l = NULL, BinaryTreeNode *r = NULL);
	//��֧��㹹�캯������Ҫʹ�����
	void GetAn(string & data)const { data = Data; }
	void release();
protected:
	string Data;	//�������� 
	BinaryTreeNode * L;	//����ָ��
	BinaryTreeNode * R;    //�Һ���ָ�� 
};

void BinaryTreeNode::release()
{
	if (L != NULL)
	{
		L->release();
		delete L;
		L = NULL;
	}
	if (R != NULL)
	{
		R->release();
		delete R;
		R = NULL;
	}
}

class BinaryTree
{
public:
	BinaryTree() { T = NULL; }	//���캯��
	BinaryTree(BinaryTreeNode*P) { T = P; }
	~BinaryTree();	//��������
	void readfile();
	void queuetotree(BinaryTreeNode**);
	void expert(BinaryTreeNode*);
	void treetoqueue(BinaryTreeNode*);
	void writefile();
protected:
	BinaryTreeNode *T;
};

BinaryTree::~BinaryTree()
{
	if (T != NULL)
	{
		T->release();
		delete T;
		T = NULL;

	}
}
void BinaryTree::treetoqueue(BinaryTreeNode*T)//���������е�������ǰ������������ 
{
	string str = "#";
	if (T == NULL)
	{
		q2.push(str);

		return;
	}
	q2.push(T->Data);
	treetoqueue(T->L);
	treetoqueue(T->R);
}

void BinaryTree::queuetotree(BinaryTreeNode**T)//�������е�������ǰ��������ɶ����� 
{
	string str1, str2 = "#";
	str1 = q1.front();
	q1.pop();
	if (str1 == str2)
		*T = NULL;
	else
	{
		*T = new BinaryTreeNode;
		(*T)->Data = str1;
		queuetotree(&(*T)->L);
		queuetotree(&(*T)->R);
	}
}

void BinaryTree::expert(BinaryTreeNode *T)//ר�����ʺ��Ʋ� ��һش� 
{
	string str1 = "��", str2 = "��", str3, str4, str5;
	while (1)
	{
		BinaryTreeNode *N;
		N = T;
		while (1)
		{
			cout << "�Ƿ�" << N->Data << "?" << endl;
			cin >> str3;
			if (N->L == NULL && N->R == NULL)
			{
				if (str3 == str1)
				{
					cout << "ר�Ҳ³���������ʧ�ܣ��Ƿ�����һ�Σ�" << endl;
					cin >> str3;
					break;
				}
				else if (str3 == str2)//��δ�ܲ³���ȷ�𰸣�ר��ѧϰϵͳ�Զ�ѧϰ����
				{
					cout << endl;
					N->release();
					cout << "ר��û�в³������������������ƺ��������" << endl;
					cout << "��������" << endl;
					cin >> str4;
					cout << "�������" << endl;
					cin >> str5;
					BinaryTreeNode *X, *Y;
					X = new BinaryTreeNode;
					Y = new BinaryTreeNode;
					X->L = X->R = Y->L = Y->R = NULL;
					N->L = X;
					N->R = Y;
					Y->Data = N->Data;
					N->Data = str5;
					X->Data = str4;
					cout << "��һ��ʧ��Ҫ����һ���" << endl;
					cin >> str3;
					break;
				}
				else
				{
					cout << "�����롰����ַ���ר�һ����ߣ����������롣" << endl;
				}
			}
			else
			{
				if (str3 == str1)
				{
					N = N->L;
				}
				else if (str3 == str2)
				{
					N = N->R;
				}
				else
				{
					cout << "�����롰����ַ���ר�һ����ߣ����������롣" << endl;
				}
			}
		}
		if (str3 == str2) break;
	}
}


void BinaryTree::readfile()//��ȡ�ļ��е����ݴ������ 
{
	std::ifstream fin("֪ʶ��.txt", std::ios::in);
	char line[1024] = { 0 };
	std::string x = "";
	while (fin.getline(line, sizeof(line)))
	{
		std::stringstream word(line);
		word >> x;
		q1.push(x);
	}
	fin.clear();
	fin.close();
	cout << "ר�������ߣ�׼����ʼ��Ϸ" << endl << endl;
}

void BinaryTree::writefile()//�����е����ݴ����ļ��� 
{
	int a;
	a = q2.size();
	ofstream   f("֪ʶ��.txt ", ios::trunc);
	f.close();
	ofstream   ofresult("֪ʶ��.txt ", ios::app);
	for (int i = 0; i < a; i++)
	{
		ofresult << q2.front() << endl;
		q2.pop();
	}
	//cout<<"¼��ɹ�"<<endl;
}

int main()
{
	cout << "����ѧϰר��ϵͳ" << endl;
	BinaryTreeNode* P = NULL;
	BinaryTree tree(P);
	tree.readfile();//ר�Ҷ�ȡ��֪ʶ�⡱�е�����
	tree.queuetotree(&P);//�������е�������ǰ��������ɶ�����
	tree.expert(P); //ר�����ʺ��Ʋ� ��һش� 
	tree.treetoqueue(P);//���������е�������ǰ������������
	tree.writefile(); //д��ר�ҵġ�֪ʶ�⡱�� 
	return 0;
}

