#pragma once
class HuffmanNode {
public:
	char info; //�����Ϣ
	double weight; //���Ȩֵ��Ҳ��������ֵ
	int parent, lchild, rchild; //���׽�㣬���Һ��ӽ��
	HuffmanNode() {
		parent = lchild = rchild = -1;
	}
	HuffmanNode(const char &data, const double &wt, const int &pa = -1, const int &lch = -1, const int &rch = -1) {
		info = data;
		weight = wt;
		parent = pa;
		lchild = lch;
		rchild = rch;
	}
}; //class HuffmanNode end

class HuffmanTree {
public:
	HuffmanTree(const int &s = 100) {
		maxSize = (s > 100 ? s : 100);
		arrayTree = new HuffmanNode[maxSize];
		currentSize = 0;
		codeArray = 0;
	}
	~HuffmanTree() {
		delete[] arrayTree;
		if (codeArray != 0)
			delete[] codeArray;
	}
	void run(const char*, const char*, const char*);

private:
	HuffmanNode *arrayTree; //�������������
	int maxSize; //�������ֵ
	int currentSize; //��ǰ�����С
	void insert(const char&, const double&); //������
	void createHuffmanTree(); //������������
	void createHuffmanCode(); //��������������
	int findPosition(const char &) const; //�����ַ���arrayTree[]�е�λ��
	int getLongestCodeLength() const; //���ر���ϵͳ�г������ı����λ��
	int isEqual(const char *s) const; //�ж�s�Ƿ�����ڱ���ϵͳ�У��������򷵻�s�ڱ���ϵͳ�е�λ�ã����򷵻�-1
	void print(); //��ӡhuffman����
private:
	class Code { //HuffmanTree��˽���࣬������
	public:
		Code() :length(10) { ptr = new char[length]; }
		~Code() { delete[] ptr; }
		char *ptr;
		const int length;
	};
	Code *codeArray; //�����СΪcurrentSize
	void reverse(char arr[]);
}; 