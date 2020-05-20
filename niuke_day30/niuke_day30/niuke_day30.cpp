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
		//5-3+picked是最右能到哪里，如果非常靠右，那么后面的数字就选不够了！
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
		//5-3+picked是最右能到哪里，如果非常靠右，那么后面的数字就选不够了！
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
#include <queue>    //队列类 
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
queue<string>q1, q2;

class BinaryTree;//树类 
class BinaryTreeNode;//树节点类 

class BinaryTreeNode
{
	friend class BinaryTree;
public:
	BinaryTreeNode() { L = NULL; R = NULL; }//构造函数，构造根结点
	BinaryTreeNode(string &an, BinaryTreeNode *l = NULL, BinaryTreeNode *r = NULL);
	//分支结点构造函数，主要使用这个
	void GetAn(string & data)const { data = Data; }
	void release();
protected:
	string Data;	//所有数据 
	BinaryTreeNode * L;	//左孩子指针
	BinaryTreeNode * R;    //右孩子指针 
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
	BinaryTree() { T = NULL; }	//构造函数
	BinaryTree(BinaryTreeNode*P) { T = P; }
	~BinaryTree();	//析构函数
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
void BinaryTree::treetoqueue(BinaryTreeNode*T)//将二叉树中的内容以前序遍历存入队列 
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

void BinaryTree::queuetotree(BinaryTreeNode**T)//将队列中的内容以前序遍历生成二叉树 
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

void BinaryTree::expert(BinaryTreeNode *T)//专家提问和推测 玩家回答 
{
	string str1 = "是", str2 = "否", str3, str4, str5;
	while (1)
	{
		BinaryTreeNode *N;
		N = T;
		while (1)
		{
			cout << "是否" << N->Data << "?" << endl;
			cin >> str3;
			if (N->L == NULL && N->R == NULL)
			{
				if (str3 == str1)
				{
					cout << "专家猜出结果，玩家失败，是否再来一次？" << endl;
					cin >> str3;
					break;
				}
				else if (str3 == str2)//，未能猜出正确答案，专家学习系统自动学习功能
				{
					cout << endl;
					N->release();
					cout << "专家没有猜出，快快告诉它动物名称和相关特征" << endl;
					cout << "动物名称" << endl;
					cin >> str4;
					cout << "相关特征" << endl;
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
					cout << "上一次失误，要再来一次嘛？" << endl;
					cin >> str3;
					break;
				}
				else
				{
					cout << "别输入“奇怪字符”专家会下线，请重新输入。" << endl;
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
					cout << "别输入“奇怪字符”专家会下线，请重新输入。" << endl;
				}
			}
		}
		if (str3 == str2) break;
	}
}


void BinaryTree::readfile()//读取文件中的内容存入队列 
{
	std::ifstream fin("知识库.txt", std::ios::in);
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
	cout << "专家已上线，准备开始游戏" << endl << endl;
}

void BinaryTree::writefile()//将队列的内容存入文件中 
{
	int a;
	a = q2.size();
	ofstream   f("知识库.txt ", ios::trunc);
	f.close();
	ofstream   ofresult("知识库.txt ", ios::app);
	for (int i = 0; i < a; i++)
	{
		ofresult << q2.front() << endl;
		q2.pop();
	}
	//cout<<"录入成功"<<endl;
}

int main()
{
	cout << "动物学习专家系统" << endl;
	BinaryTreeNode* P = NULL;
	BinaryTree tree(P);
	tree.readfile();//专家读取“知识库”中的资料
	tree.queuetotree(&P);//将队列中的内容以前序遍历生成二叉树
	tree.expert(P); //专家提问和推测 玩家回答 
	tree.treetoqueue(P);//将二叉树中的内容以前序遍历存入队列
	tree.writefile(); //写入专家的“知识库”中 
	return 0;
}

