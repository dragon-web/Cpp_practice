#define _CRT_SECURE_NO_WARNINGS 

//����������Ҫ���ڱ����ѹ��

#include<iostream>

//���������� һ���ʵ��ʱ�ڽӱ�����ڽӾ���

typedef struct HuffNode
{
	int weigit;//Ȩֵ
	int lchild;
	int rchild;
	int parent;
};
//ÿ������parentΪ-1��С��ֵ
void HuffmanTree(HuffNode huffTree[], int w[], int n)
{
	for (int i = 0; i < 2 * n - 1; i++)
	{
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++)
	{
		huffTree[i].weigit = w[i];
	}
	for (int k = n; k < 2 * n - 1; k++)//������������ 
	{

	}


}




int main()
{


	system("pause");
	return 0;
}