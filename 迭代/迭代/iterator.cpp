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
void BinTreeCreate_1(BinTreeNode** t)//�����ǽڵ�ĵ�ַ
{
	char num;
	scanf("%c", &num);
	if (num == '#')
	{
		*t = NULL;
	}
	else
	{
		(*t) = (BinTreeNode*)malloc(sizeof(BinTreeNode));//����#Ϊ������ռ�
		assert(*t != NULL);//�ռ�����ɹ�
		(*t)->val = num;
		BinTreeCreate_1(&(*t)->left);
		BinTreeCreate_1(&(*t)->right);
	}
}
//����ΪɶҪ�������ṹ����������ÿ���ܲ��ܴ�����һ�������ڵ��ָ�밡�����ܵģ�����Ҫ���������ڵ�ָ��
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
//�ǵݹ����
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
		while (!dp.empty())//ѭ�����������һ���־������ջ����
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
//��������Լ�ȥ������ǵݹ�����ͻ���ֺܶ�����,��Щ�ǳ������ѭ������û����������벻��

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

vector<int> inorderTraversal(BinTreeNode* root)//�����ķ�ʽʵ�ַǵݹ����
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

	/*cout << "ǰ�����" << endl;
	PreOrder(&Tree);
	cout << "�������" << endl;
	InOrder(&Tree);
	cout << "�������" << endl;
	PostOrder(&Tree);
	PreOrderNoRu(&Tree);
	InOrderNoRu(&Tree);*/
	PostOrderNoRu(&Tree);
	system("pause");
	return 0;
}