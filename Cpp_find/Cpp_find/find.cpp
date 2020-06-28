#include<iostream>
using namespace std;

struct BiNode
{
	int data;
	BiNode *lchild, *rchild;
};

class BiSortTree    //�ٶ���¼��ֻ��һ������������
{
public:
	BiSortTree(int a[], int n);    //�������Ҽ���a[n]�Ķ���������
	~BiSortTree(void);        //�����������ͷŶ��������������н�㣬ͬ�����������������
	BiNode* Getroot();       //��ȡָ�������ָ��
	BiNode* InsertBST(BiNode *root, BiNode *s);          //�ڶ����������в���һ�����s
	void DeleteBST(BiNode *p, BiNode *f);               //ɾ�����f�����ӽ��p
	BiNode* SearchBST(BiNode *root, int k, int count);   //����ֵΪk�Ľ��
private:
	BiNode *root;    //�����������������������ĸ�ָ��
	void Release(BiNode *root);   //������������
};

//������BiSortTree�еĳ�Ա�������ļ���Ϊbisorttree.cpp


/*
 *ǰ������������������������
 *��    �룺����a[n]
 *��    �ܣ�����һ������ֵΪa[n]�Ķ���������
 *��    ������
 *��������������һ�ö���������
 */
BiSortTree::BiSortTree(int a[], int n)//���캯��
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		BiNode* s = new BiNode;
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		root = InsertBST(root, s);
	}
}
/*
 *ǰ�������������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ��������������н��
 *��    ������
 *��������������������������
 */
BiSortTree::~BiSortTree(void)
{
	Release(root);
}

/*
 *ǰ�������������������Ѿ�����
 *��    �룺��
 *��    �ܣ���ȡָ�������ָ��
 *��    ����ָ�������ָ��
 *������������������������
 */
BiNode* BiSortTree::Getroot()
{
	return root;
}
/*
 *ǰ���������յĶ���������
 *��    �룺ָ�������ָ���ָ���½�����ָ��
 *��    �ܣ����½������뵽������������
 *��    ����ָ�������ָ��
 *��������������һ���µĶ���������
 */

BiNode* BiSortTree::InsertBST(BiNode *root, BiNode *s)
{
	if (root == NULL) return s;
	else {
		if (s->data < root->data) root->lchild = InsertBST(root->lchild, s);//���뵽��������
		else  root->rchild = InsertBST(root->rchild, s);                 //���뵽��������
		return root;
	}
}

/*
 *ǰ�������������������Ѿ�����
 *��    �룺ָ����f��ָ��Ϳ�ָ��p
 *��    �ܣ������f�����ӽ��pɾ��
 *��    ������
 *��������������һ���µĶ���������
 */
void BiSortTree::DeleteBST(BiNode *p, BiNode *f)
{
	p = f->lchild;
	BiNode *par;
	BiNode *s;
	if (!p->lchild && !p->rchild) { //pΪҶ��	  
		f->lchild = NULL;
		delete p;
	}
	else {
		if (!p->rchild) {         //pֻ��������		    
			f->lchild = p->lchild;
			delete p;
		}
		else {
			if (!p->lchild) {     //pֻ��������			  
				f->lchild = p->rchild;
				delete p;
			}
			else {                //��������������			   
				par = p;
				s = p->rchild;
				while (s->lchild != NULL)   //���������½��
				{
					par = s;
					s = s->lchild;
				}
				p->data = s->data;
				if (par == p)  par->rchild = s->rchild;  //�����������
				else par->lchild = s->rchild;          //һ�����
				delete s;
			}       //�������������յ�����������
		}
	}
}
/*
 *ǰ�������������������Ѿ�����
 *��    �룺ָ�������ָ��Ͳ�ѯ������k
 *��    �ܣ���������ֵΪk�Ľ��
 *��    ����ָ������ֵΪk�Ľ��
 *������������������������
 */
BiNode* BiSortTree::SearchBST(BiNode *root, int k, int count)
{
	if (root == NULL) {
		cout << "�˽�㲻����!" << endl;
		cout << "�Ƚϴ���Ϊ" << count << endl;
		return NULL;
	}
	else {
		if (root->data == k) { //���ҳɹ�������		
			count++;
			cout << "����" << root->data << "�ɹ�!" << endl;
			cout << "�Ƚϴ���Ϊ" << count << endl;
			return root;
		}
		else {
			if (k < root->data) {
				count++;
				return SearchBST(root->lchild, k, count);  //����������
			}
			else {
				count++;
				return SearchBST(root->rchild, k, count);  //����������
			}
		}
	}
}
/*
 *ǰ�������������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ����������Ĵ洢�ռ䣬������������
 *��    ������
 *��������������������������
 */
void BiSortTree::Release(BiNode* root)
{
	if (root != NULL) {
		Release(root->lchild);   //�ͷ�������
		Release(root->rchild);   //�ͷ�������
		delete root;
	}
}
//����77
int main()
{
	int count = 0;
	BiNode* p = NULL;
	int arr[6] = { 70,50,80,46,55,77 };
	cout << "����������������ֵ" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}

	BiSortTree bst = BiSortTree(arr,6);
	BiNode* root = bst.Getroot();
	cout << "����ֵΪ77�Ľڵ�" << endl;
		bst.SearchBST(root, 77, count);


	system("pause");
	return 0;
}