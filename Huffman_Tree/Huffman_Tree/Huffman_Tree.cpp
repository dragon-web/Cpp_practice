#define _CRT_SECURE_NO_WARNINGS 
#define N 5

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//���������� һ���ʵ��ʱ�ڽӱ�����ڽӾ���
int i1;
int i2;
char AT1;
char AT2;
typedef struct HuffNode
{
	int weigit;//Ȩֵ
	int lchild;
	int rchild;
	int parent;
	vector<int> RE;
}HuffNode;
//ÿ������parentΪ-1��С��ֵ
void Select(HuffNode huffTree[],int k,int &i1,int &i2);
void HuffmanTree(HuffNode huffTree[], int w[], int n)//w��Ȩֵ���飬Ҷ�ӽڵ����n ������������
{
	for (int i = 0; i < 2 * n - 1; i++)//�����еĽڵ�ֵ��ֵΪ-1
	{
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++) //��Ȩֵ��ֵ
	{
		huffTree[i].weigit = w[i];
		huffTree[i].RE.push_back(i);
	}
	for (int k = n; k < 2 * n - 1; k++)//������������ 0~n-1
	{
	
		Select(huffTree, k,i1,i2);//�ҵ�parentΪ-1����С�ʹ�С�ڵ�  ����il i2;
		huffTree[k].weigit = huffTree[i1].weigit + huffTree[i2].weigit;
		auto p1 = huffTree[i1].RE.begin();
		auto p2 = huffTree[i2].RE.begin();
		while(p1 != huffTree[i1].RE.end())
		{
			huffTree[k].RE.push_back(*p1);
			p1++;
		}
		while (p2 != huffTree[i2].RE.end())
		{
			huffTree[k].RE.push_back(*p2);
			p2++;
		}
		sort(huffTree[k].RE.begin(), huffTree[k].RE.end());
		huffTree[i1].parent = k;
		huffTree[i2].parent = k;
		huffTree[k].lchild = i1;
		huffTree[k].rchild = i2;
	}
}
int temp1;
int temp2;
void Select(HuffNode huffTree[], int k, int& i1, int& i2)
{
	int i = 0;
	i1 = INT_MAX;
	i2 = INT_MAX;//��һ��Ȩֵ�����ܳ��ֵ�ֵ����
	for (i; i < k; ++i)
	{
		if (huffTree[i].weigit < i1 &&huffTree[i].parent == -1)
		{
			i1 = huffTree[i].weigit;//�ҵ���С��Ԫ����
			temp1 = i;
		}
	}
	for (int j = 0; j < k; ++j)
	{
		if (huffTree[j].weigit < i2 && j != temp1 && huffTree[j].parent == -1)
		{
			i2 = huffTree[j].weigit;
			temp2 = j;
		}
	}
	i1 = temp1;
	i2 = temp2;
}
/*
int  Cacular_total(HuffNode huffTree[],int start,int end,int TO, vector<int> bp)
{
	int res;
	int i = 2*N -1;
	while (bp.size())
	{
		if (bp.size() <= huffTree[i].RE.size())
		{
			auto it1 = bp.begin();
			auto it2 = huffTree[i].RE.begin();//Ϊɶ�Ҹ���ôд����Ϊ����ź���
			if (*it1 = *it2)
			{
				bp.erase(it1);
				it2++;
			}
		}
		else
		{
			i--;
		}
	}

	
}
*/
int main()
{
	
	vector<int> bp;
	int arr[N];
	for (int j = 0; j < N; ++j)
	{
		arr[j] = rand() % 100 + 1;
	}
	HuffNode huff[2*N-1];
	HuffmanTree(huff, arr, N);
	for (int i = 0; i <	2*N -1; ++i)
	{
		cout << "����:" << i << "   " << huff[i].weigit << " " << huff[i].parent << " " << huff[i].lchild << " " << huff[i].rchild<<" ";
		auto it = huff[i].RE.begin();
		while (it != huff[i].RE.end())
		{
			cout << *it;
			it++;
		}
		cout << endl;
	}
	cout << "______________________________________________________________________________" << endl;
	int num1, num2;
	cout << "Enter Start:" << endl;
	cin >> num1;
	getchar();
	cout << "Enter End:" << endl;
	cin >> num2;
	getchar();
	for (int i = num1; i <= num2; ++i)
	{
		bp.push_back(i);
	}
	
	system("pause");
	return 0;
}

