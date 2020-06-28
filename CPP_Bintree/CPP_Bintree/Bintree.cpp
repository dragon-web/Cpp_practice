#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>

using namespace std;

template <class T>
struct BiNode   //�������Ľ��ṹ
{
	T data;
	BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
	BiTree();             //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
	~BiTree(void);         //�����������ͷŶ��������и����Ĵ洢�ռ�
	BiNode<T>* Getroot();  //���ָ�������ָ��
	void PreOrder(BiNode<T> *root);     //ǰ�����������
	void InOrder(BiNode<T> *root);      //�������������
	void PostOrder(BiNode<T> *root);    //�������������
	void LeverOrder(BiNode<T> *root);   //�������������
private:
	BiNode<T> *root;         //ָ�������ͷָ��
	BiNode<T> *Creat();     //�вι��캯������
	void Release(BiNode<T> *root);   //������������ 
};


//���ʵ��

//�������еĳ�Ա�������ļ���Ϊbitree.cpp



/*
 *ǰ��������������������
 *��    �룺��
 *��    �ܣ�����һ�ö�����
 *��    ������
 *��������������һ�ö�����
 */
template<class T>
BiTree<T>::BiTree()
{
	this->root = Creat();
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
 *��    ������
 *����������������������
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ�������������ָ��
 *��    ����ָ�������������ָ��
 *��������������������
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot()
{
	return root;
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�����������
 *��    �����������н���һ����������
 *��������������������
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if (root == NULL) 
		return;
	else {
		cout << root->data << " ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::InOrder(BiNode<T> *root)
{
	if (root == NULL)  return;      //�ݹ���õĽ�������	          
	else {
		InOrder(root->lchild);    //����ݹ����root��������
		cout << root->data << " ";    //���ʸ�����������
		InOrder(root->rchild);    //����ݹ����root��������
	}
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{
	if (root == NULL)   return;       //�ݹ���õĽ�������
	else {
		PostOrder(root->lchild);    //����ݹ����root��������
		PostOrder(root->rchild);    //����ݹ����root��������
		cout << root->data << " ";      //���ʸ�����������
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //����˳����У����ٶ����ᷢ������

	BiNode<T>* Q[MaxSize];
	BiNode<T>* q;

	if (root == NULL) return;
	else {
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			cout << q->data << " ";
			if (q->lchild != NULL)    Q[rear++] = q->lchild;
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}

/*
 *ǰ���������ն�����
 *��    �룺����ch;
 *��    �ܣ���ʼ��һ�ö�����,���캯������
 *��    ������
 *��������������һ�ö�����
 */
template <class T>
BiNode<T>* BiTree<T>::Creat()
{
	BiNode<T>* root;
	T ch;
	cout << "�����봴��һ�ö������Ľ������" << endl;
	cin >> ch;
	if (ch == "#")
		root = NULL;
	else {
		root = new BiNode<T>;       //����һ�����
		root->data = ch;
		root->lchild = Creat();    //�ݹ齨��������
		root->rchild = Creat();    //�ݹ齨��������
	}
	return root;
}

/*
 *ǰ���������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
 *��    ������
 *����������������������
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
	if (root != NULL) {
		Release(root->lchild);   //�ͷ�������
		Release(root->rchild);   //�ͷ�������
		delete root;
	}
}


//�����������������ļ���Ϊbitreemain.cpp


int main()
{
	BiTree<string> bt; //����һ����
	BiNode<string>* root = bt.Getroot();  //��ȡָ�������ָ�� 

	cout << "------ǰ�����------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.LeverOrder(root);
	cout << endl;
	system("pause");
	return 0;
}
