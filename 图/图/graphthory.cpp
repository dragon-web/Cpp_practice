#define _CRT_SECURE_NO_WARNINGS 
#define DataType char
#include<iostream>
#include<stack>
using namespace std;
//ŷ������ ���û��һ������ͨ�����ţ���ô���۴��ĳ��������ҵ�ŷ����·

//�ڽӱ����ͼ�Ĵ洢  �ʺ�ϡ��ͼ
//�ٽӱ�洢������ͼ���ӷ���һ��   �洢����ͼ��ʱ������һ���ߴ洢���ε����
//����ж϶���i�������Ƿ���ڱߣ�
const int MAX_VERTEX = 10;//����ͼ���ڵ���10
struct ArcNode//�߱�
{
	int adjvex; // �ٽ����  
	ArcNode*next;
};
struct VertexNode//�����
{
	DataType vertex;
	ArcNode* firstEdge;
};
class ALGraph
{
private:
	VertexNode adjList[MAX_VERTEX];
	int vertexNum, arcNum;
public:
	ALGraph(DataType v[], int n, int e);
	~ALGraph();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
};
ALGraph::ALGraph(DataType v[], int n, int e)
{
	vertexNum = n;//��ʼ���������
	arcNum = e;//��ʼ���ߵĸ���
	for (int i = 0; i < vertexNum; ++i)
	{
		adjList[i].vertex = v[i];
		adjList[i].firstEdge = NULL;
	}
	for (int i = 0; i < arcNum; ++i)
	{
		cout << "����ߵ���Ϣ" << endl;
		int vi, vj;//vi������� vj�����ص�
		cin >> vi >> vj;
		auto s = new ArcNode;
		s->adjvex = vj;
		s->next = adjList[vi].firstEdge;
		adjList[i].firstEdge = s;
	}
}


//ʮ������
//�ڽӱ�  ���ڽӱ� ʮ��������ǽ��ڽӱ�����ڽӱ�϶�Ϊһ



int main()
{



	system("pause");
	return 0;
}
 