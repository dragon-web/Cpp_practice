#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<assert.h>
#include<stack>
#include<vector>
using namespace std;
typedef struct BinTreeNode
{
	char val;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;
void _PreOrder(BinTreeNode *t);
void BinTreeCreate_1(BinTreeNode** t)//传的是节点的地址
{
	char num;
	scanf("%c", &num);
	if (num == '#')
	{
		*t = NULL;
	}
	else
	{
		(*t) = (BinTreeNode*)malloc(sizeof(BinTreeNode));//不是#为其申请空间
		assert(*t != NULL);//空间申请成功
		(*t)->val = num;
		BinTreeCreate_1(&(*t)->left);
		BinTreeCreate_1(&(*t)->right);
	}
}
//我们为啥要设计这个结构啊？你想你每次能不能传进来一个树根节点的指针啊，不能的，我们要传的是树节点指针
void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		cout << t->val;
		_PreOrder(t->left);
		_PreOrder(t->right);
	}
}
void _InOrder(BinTreeNode* p);
void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode* p)
{
	if (p != NULL)
	{
		_InOrder(p->left);
		cout << p->val;
		_InOrder(p->right);
	}
}
void _PostOrder(BinTreeNode* p);
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode* p)
{
	if (p != NULL)
	{
		_PostOrder(p->left);
		_PostOrder(p->right);
		cout << p->val;
	}
}
//非递归遍历
void _PreOrderNoRu(BinTreeNode *p);
stack<BinTreeNode*> dp;
void PreOrderNoRu(BinTree *t)
{
	_PreOrderNoRu(t->root);
}
void _PreOrderNoRu(BinTreeNode *p)
{
	BinTreeNode* q;
	if (p != NULL)
	{
		dp.push(p);
		while (!dp.empty())//循环起来精妙的一部分就是这个栈不空
		{
			q = dp.top();
			dp.pop();
			printf("%c ", q->val);
			if (q->right != NULL)
			{
				dp.push(q->right);
			}
			if (q->left != NULL)
			{
				dp.push(q->left);
			}
		}
	}
}

void _InOrderNoRu(BinTreeNode *t);
void InOrderNoRu(BinTree *t)
{
	_InOrderNoRu(t->root);
}
//如果我们自己去想这个非递归遍历就会出现很多问题,有些非常精妙的循环我们没见过还真的想不来

void _InOrderNoRu(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode *p;
		do
		{
			while (t != NULL)
			{
				dp.push(t);
				t = t->left;
			}
			p = dp.top();
			dp.pop();
			cout << p->val;
			if (p->right != NULL)
				t = p->right;
		} while (!dp.empty() || t != NULL);
	}
}

void _PostOrderNoRu(BinTreeNode *t);
void PostOrderNoRu(BinTree *t)
{
	_PostOrderNoRu(t->root);
}
void _PostOrderNoRu(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode* p, *pre = NULL;
		do
		{
			while (t != NULL)
			{
				dp.push(t);
		
		t = t->left;
			}
			p = dp.top();
			if (p->right == NULL || p->right == pre)
			{
				dp.pop();
				cout << p->val;
				pre = p;
			}
			else
			{
				t = p;
				t = t->right;
			}
		} while (!dp.empty());
	}
}

vector<int> inorderTraversal(BinTreeNode* root)//迭代的方式实现非递归遍历
{
	if (root != NULL)
	{
		BinTreeNode* temp = root;
		stack<BinTreeNode*> s;
		vector<int> res;
		s.push(root);
		while (!s.empty() || temp != NULL)
		{
			while (temp != NULL)
			{
				s.push(temp);
				temp = temp->left;
			}
			if (temp->right != NULL)
			{

			}


		}
	}
}

/*
void _PostOrderNoRu(BinTreeNode *t);

void PostOrderNoRu(BinTree *t)
{
	_PostOrderNoRu(t->root);
}
void _PostOrderNoRu(BinTreeNode *t)
{

}*/
int main()
{
	BinTree Tree;
	BinTreeCreate_1(&(Tree.root));

	/*cout << "前序遍历" << endl;
	PreOrder(&Tree);
	cout << "中序遍历" << endl;
	InOrder(&Tree);
	cout << "后序遍历" << endl;
	PostOrder(&Tree);
	PreOrderNoRu(&Tree);
	InOrderNoRu(&Tree);*/
	PostOrderNoRu(&Tree);
	system("pause");
	return 0;
}