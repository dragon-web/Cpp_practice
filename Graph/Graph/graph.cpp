#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
using namespace std;
const int MaxSize = 12;
int visited[MaxSize];
struct ArcNode                   //����߱���
{
	int adjvex;                    //�ڽӵ���
	ArcNode *next;                 //ָ����һ���߽���ָ��
};
template <class T>
struct VertexNode               //���嶥�����
{
	T vertex;                     //���������
	ArcNode *firstedge;           //�߱��ͷָ��
};
template <class T>
class ALGraph
{
public:
	ALGraph(T a[], int n, int e);   //���캯������ʼ��һ����n������e���ߵ�ͼ
	~ALGraph();                      //�����������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
	T GetVex(int i);                 //ȡͼ�е�i������������Ϣ
	void PutVex(int i, T value);     //��ͼ�е�i���������������Ϊvalue
	void InsertVex(int i, T value);  //��ͼ�в���һ�����㣬����Ϊi��ֵΪvalue
	void DeleteVex(int i);           //ɾ��ͼ�е�i������
	void InsertArc(int i, int j);    //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j
	void DeleteArc(int i, int j);    //��ͼ��ɾ��һ���ߣ�����������������ı��Ϊi��j
	void DFSTraverse(int v);         //������ȱ���ͼ
	void BFSTraverse(int v);         //������ȱ���ͼ
private:
	VertexNode<T> adjlist[MaxSize];  //��Ŷ���������
	int vertexNum, arcNum;           //ͼ�Ķ������ͱ���
};


/*
 *ǰ��������ͼ������
 *��    �룺��
 *��    �ܣ�ͼ�ĳ�ʼ��
 *��    ������
 *�����������õ�һ������ͼ
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	arcNum = e;                             //����
	vertexNum = n;                            //������
	int i, j;
	for (i = 0; i < vertexNum; i++)
	{
		VertexNode<T> tempvertex;
		tempvertex.vertex = a[i];
		tempvertex.firstedge = NULL;
		adjlist[i] = tempvertex;
	}
	for (int k = 0; k < arcNum; k++)           //��������ÿһ���ߣ�������Ӧ�߱��в�����
	{
		cout << "���������������������������";
		cin >> i >> j;                         //�������������������������
		ArcNode *s = new ArcNode; s->adjvex = j;  //����һ���߱���s
		s->next = adjlist[i].firstedge;      //�����s���뵽���i�ı߱�ı�ͷ  
		adjlist[i].firstedge = s;
	}
	//InsertArc(0, 1);                   //�����
	//InsertArc(1, 0);                   //�����
	//InsertArc(0, 2);
	//InsertArc(2,0);
	//InsertArc(0, 3);
	//InsertArc(1, 3);
	//InsertArc(3, 1);

	//InsertArc(1, 4);
	//InsertArc(4,1);
	//InsertArc(2, 0);
	//InsertArc(2, 4);
	//InsertArc(3, 1);
	//InsertArc(3, 4);
	//InsertArc(4, 3);

	//InsertArc(4, 2);
	//InsertArc(4, 3);
}
/*   ǰ��������ͼ�Ѵ���
 *   ��    �룺��
 *   ��    �ܣ�����ͼ
 *   ��    ������
 *   �����������ͷ�ͼ��ռ�õĴ洢�ռ�
 */
template <class T>
ALGraph<T>::~ALGraph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode * p = adjlist[i].firstedge;
		while (p != NULL)                                              //ѭ��ɾ��
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //�ͷŽ��ռ�
			p = adjlist[i].firstedge;
		}
	}
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ����ͼ�ж���i��������Ϣ
 *��    ����ͼ�ж���i��������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
T ALGraph<T>::GetVex(int i)
{
	if (i > vertexNum || i < 0) throw "���붥���λ�ò���ȷ"; //����i���������׳��쳣
	return adjlist[i].vertex;                               //���ص�i�������������  
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ���ͼ�ж���i����������Ϊvalue
 *��    ������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::PutVex(int i, T value)
{
	if (i > vertexNum || i < 0) 
		throw "���붥���λ�ò���ȷ"; //����i���������׳��쳣
	adjlist[i].vertex = value;                              //��i���������������Ϊvalue
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����value,λ��i
 *��    �ܣ���ͼ��iλ�ò���һ������name
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ������
 */
template <class T>
void ALGraph<T>::InsertVex(int i, T value)
{
	if (i > vertexNum || i<0 || i>MaxSize) throw "���붥���λ�ò���ȷ"; //����i���������׳��쳣
	vertexNum++;                                            //��������1
	VertexNode<T> tempvertex;
	tempvertex.vertex = value;
	tempvertex.firstedge = NULL;
	adjlist[i] = tempvertex;  	                    //��i���������������Ϊvalue	
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ���ͼ��ɾ������i
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ������,��Ӧ�����������ı�Ҳ��ȥ
 */
template <class T>
void ALGraph<T>::DeleteVex(int i)
{
	if (i<0 || i>MaxSize)
		throw "λ��";       //��������������׳��쳣
	int k;
	for (k = 0; k < vertexNum; k++)               //ɾ����ȱ�
		if (k != i)	 DeleteArc(k, i);
	ArcNode *s;                                //����һ���߱���s
	if (adjlist[i].firstedge != NULL)
	{
		ArcNode *s;
		s = adjlist[i].firstedge->next;
		while (s != NULL)
		{
			ArcNode *p;
			p = s;
			adjlist[i].firstedge->next = s->next;
			s = s->next;
			delete p;                        //ɾ��p���
		}
		s = adjlist[i].firstedge;
		adjlist[i].firstedge = NULL;
		delete s;
	}
	for (k = i; k < vertexNum; k++)
	{
		adjlist[k] = adjlist[k + 1];             //�洢������Ϣ       
	}
	vertexNum--;                             //��������1
	for (k = 0; k < vertexNum; k++)
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;                //�����s���뵽���i�ı߱�ı�ͷ
			while (s != NULL)
			{
				if (s->adjvex > i)                  //����i���
					s->adjvex--;
				s = s->next;
			}
		}
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i��j
 *��    �ܣ���ͼ�в��붥��i��j�����������ı�
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ����
 */
template <class T>
void ALGraph<T>::InsertArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "λ��";   //��������������׳��쳣
	ArcNode *s = new ArcNode; s->adjvex = j;      //����һ���߱���s
	s->next = adjlist[i].firstedge;             //�����s���뵽���i�ı߱�ı�ͷ
	adjlist[i].firstedge = s;
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i��j
 *��    �ܣ���ͼ��ɾ������i��j �����ı�
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ����
*/
template <class T>
void ALGraph<T>::DeleteArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "λ��";  //��������������׳��쳣
	ArcNode *s;
	ArcNode *tempnode;
	s = adjlist[i].firstedge;
	tempnode = adjlist[i].firstedge;
	while (s != NULL && s->adjvex != j)
	{
		tempnode = s;
		s = s->next;
	}
	if (s != NULL)
	{
		tempnode->next = s->next;
		delete s;
	}
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if (v > vertexNum) throw "λ��";                          //��������������׳��쳣
	ArcNode * p;
	int j;
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p)                                                //������������v���ڽӵ�j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;
	}
}
/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum) throw "λ��";                           //��������������׳��쳣
	int front, rear, j;
	ArcNode * p;                                              //����һ���߱���p
	int Q[MaxSize];
	front = rear = -1;                                            //��ʼ������, ������в���˳��洢�Ҳ��ᷢ�����
	cout << adjlist[v].vertex << " ";  visited[v] = 1; Q[++rear] = v; //�����ʶ������
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //�߱��еĹ���ָ��p��ʼ��
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}
			p = p->next;
		}
	}
}


int main()
{
	int which;
	int j;
	string name;
	int choose = 1;
	//string a[5] = { "����","�廪","����","���ִ�ѧ","��������" };
	string a[5] = { "A","B","C","D","E" };

	ALGraph<string> algraphTest(a, 5, 5);        //����ͼ
	while (choose == 1)                                      //����
	{
		cout << "��Ҫ���������Ϣ�밴0" << endl;		         //������Ҫ���еĲ��������
		cout << "��Ҫ�������һ��������Ϣ�밴1" << endl;
		cout << "��Ҫ���붥���밴2" << endl;
		cout << "��Ҫ�޸Ķ����밴3" << endl;
		cout << "��Ҫɾ�������밴4" << endl;
		cout << "��Ҫ������ȱ����밴5" << endl;
		cout << "��Ҫ������ȱ����밴6" << endl;
		cout << "��Ҫ�˳��밴7" << endl;
		cin >> which;
		switch (which)                                        //����ѡ��
		{
		case 0:
			for (j = 0; j < 5; j++)
				cout << algraphTest.GetVex(j) << " ";              //�������
			cout << endl;
			break;
		case 1:
			int i;
			cout << "�����붥�㣺" << endl;
			cin >> i;
			try
			{
				cout << algraphTest.GetVex(i) << endl;              //���i�����������
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 2:                                               //��ͼ�е�iλ�ò���һ����ֵΪname
			cout << "�����붥�㼰���֣�" << endl;
			cin >> i >> name;
			try
			{
				algraphTest.InsertVex(i, name);

			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 3:                                               //�޸�ͼ��һ�����ֵ
			cout << "�����붥�㼰���֣�" << endl;
			cin >> i >> name;
			try
			{
				algraphTest.PutVex(i, name);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 4:                                               //ɾ��ͼ��һ�����ֵ
			cout << "�����붥�㣺" << endl;
			cin >> i;
			try
			{
				algraphTest.DeleteVex(i);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 5:                                               //ͼ�������������
			cout << "�����붥�㣺" << endl;
			cin >> i;
			cout << endl << "�ӵ�" << i << "������������ȱ���ͼ" << endl;
			try
			{
				for (int ii = 0; ii < MaxSize; ii++) visited[ii] = 0;
				algraphTest.DFSTraverse(i);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
			break;
		case 6:                                               //ͼ�Ĺ����������
			cout << "�����붥�㣺" << endl;
			cin >> i;
			cout << endl << "�ӵ�" << i << "�����������ȱ���ͼ" << endl;
			try
			{
				for (int ii = 0; ii < MaxSize; ii++) visited[ii] = 0;
				algraphTest.BFSTraverse(i);
			}
			catch (char*s)
			{
				cout << s << endl;
			}
			break;
		case 7:                                             //�˳�
			choose = 0;
			break;
		}
	}
}
/*
int main()
{
	string a[5] = { "A","B","C","D","E" };
	int edg = 5;
	ALGraph<string> gra(a, 5, 5);
	gra.DFSTraverse(0);
	system("pause");
	return 0;
}*/