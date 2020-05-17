#define _CRT_SECURE_NO_WARNINGS 

//哈夫曼数主要用于编码和压缩

#include<iostream>

//哈夫曼编码 一般的实现时邻接表或者邻接矩阵

typedef struct HuffNode
{
	int weigit;//权值
	int lchild;
	int rchild;
	int parent;
};
//每次搜索parent为-1最小的值
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
	for (int k = n; k < 2 * n - 1; k++)//构建哈夫曼树 
	{

	}


}




int main()
{


	system("pause");
	return 0;
}