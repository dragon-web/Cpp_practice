#include"huffman.h"
#include"common.h"
//������ǲ���
void HuffmanTree::insert(const char &data, const double &wt) { //������
	if (2 * currentSize - 1 >= maxSize) //Ҷ�ӽ��Ϊn�Ĺ�����������2n-1�����
		return;
	arrayTree[currentSize].info = data;
	arrayTree[currentSize].weight = wt;
	currentSize++;
}

void HuffmanTree::reverse(char arr[]) { //��ת�ַ���
	const int len = strlen(arr);
	char *p;
	p = new char[len + 1];
	strcpy(p, arr);
	p[len] = '\0';
	int k = 0;
	for (int i = len - 1; i >= 0; i--)
		arr[i] = p[k++];
	arr[len] = '\0';
	delete[] p;
}

int HuffmanTree::findPosition(const char &ch) const { //�����ַ�ch��arrayTree[]�е�λ��
	for (int i = 0; i < currentSize; i++)
		if (arrayTree[i].info == ch)
			return i;
	return -1;
}

int HuffmanTree::getLongestCodeLength() const { //���ر�������codeArray[]������ı����λ��
	if (currentSize == 0)
		return -1;
	int len = strlen(codeArray[0].ptr);
	int i = 1;
	while (i < currentSize) {
		int tmp = strlen(codeArray[i].ptr);
		if (tmp > len)
			len = tmp;
		i++;
	}
	return len;
}

int HuffmanTree::isEqual(const char *s) const { //�ж�s�ı����Ƿ���ڣ������ڷ��ر���������codeArray[]�е�λ�ã����򷵻�-1
	for (int i = 0; i < currentSize; i++)
		if (strlen(s) == strlen(codeArray[i].ptr)) //����ȥ������
			if (strcmp(s, codeArray[i].ptr) == 0)
				return i;
	return -1;
}

void HuffmanTree::print() { //��ӡ����
	int k = 0;
	while (k < currentSize) {
		cout << arrayTree[k].info << '(' << arrayTree[k].weight << "): " << codeArray[k].ptr << endl;
		k++;
	}
}

void HuffmanTree::createHuffmanTree() { //����huffmanTree
	int i = currentSize;
	int k;
	double wt1, wt2;
	int lnode, rnode;
	while (i < 2 * currentSize - 1) {
		wt1 = wt2 = numeric_limits<double>::max();
		k = 0;
		while (k < i) {
			if (arrayTree[k].parent == -1) {
				if (arrayTree[k].weight < wt1) {
					wt2 = wt1;
					rnode = lnode;
					wt1 = arrayTree[k].weight;
					lnode = k;
				}
				else if (arrayTree[k].weight < wt2) {
					wt2 = arrayTree[k].weight;
					rnode = k;
				}
			}
			k++;
		}
		arrayTree[i].weight = arrayTree[lnode].weight + arrayTree[rnode].weight;
		arrayTree[i].lchild = lnode;
		arrayTree[i].rchild = rnode;
		arrayTree[lnode].parent = arrayTree[rnode].parent = i;
		i++;
	}
}

void HuffmanTree::createHuffmanCode() { //����huffmanCode��������������
	codeArray = new Code[currentSize];
	int i = 0;
	int k, n, m;
	while (i < currentSize) {
		k = arrayTree[i].parent;
		n = 0;
		m = i;
		while (k != -1 && k < currentSize * 2 - 1) {
			if (arrayTree[k].lchild == m)
				codeArray[i].ptr[n++] = '0';
			else if (arrayTree[k].rchild == m)
				codeArray[i].ptr[n++] = '1';
			m = k;
			k = arrayTree[m].parent;
		}
		codeArray[i].ptr[n] = '\0';
		reverse(codeArray[i].ptr); //��ת�ַ�����ʹ֮�����ȷ�ı���
		i++;
	}
}

void HuffmanTree::run(const char *inFilename, const char *outFilename, const char *secondOutName) { //run������ʵ��
	//��inFilename�ṩ����
	ifstream fileIn(inFilename, ios::in);
	if (!fileIn) {
		cerr << "\"" << inFilename << "\" could not open." << endl;
		exit(1);
	}
	char ch;
	int pos;

	//���ļ��ж����ַ�����ͳ�Ƹ����ַ�����
	fileIn >> ch;
	while (fileIn && !fileIn.eof()) {
		pos = findPosition(ch);
		if (pos != -1)
			arrayTree[pos].weight++;
		else
			insert(ch, 1);
		fileIn >> ch;
	}

	createHuffmanTree(); //����huffman��
	createHuffmanCode(); //��ͳ���ַ����б���

	//��outFilename�ṩ���
	ofstream fileOut(outFilename, ios::out);
	if (!fileOut) {
		cerr << "\"" << outFilename << "\" could not open." << endl;
		exit(1);
	}
	fileIn.clear(); //ˢ��������, ע��ofstreamû��flush()��������ifstream����flush()����
	fileIn.seekg(0, ios::beg);

	//�Ѵ�inFilename�ļ��е��ַ����б��룬��д��outFilename�ļ�
	fileIn >> ch;
	while (fileIn && !fileIn.eof()) {
		pos = findPosition(ch);
		if (pos != -1)
			fileOut << codeArray[pos].ptr;
		fileIn >> ch;
	}
	fileIn.close();
	fileOut.close();

	//��outFilename, secondOutName���ֱ��ṩ�������
	fileIn.open(outFilename, ios::in);
	fileOut.open(secondOutName, ios::out);
	if (!fileIn || !fileOut) {
		cerr << "File could not open." << endl;
		exit(1);
	}

	//��outFileName�ļ��еı���������룬����������д��secondOutName�ļ�
	const int longestLen = getLongestCodeLength();
	char *p = new char[longestLen + 1];
	int k = 0;
	fileIn >> ch;
	while (fileIn && !fileIn.eof()) {
		if (k < longestLen) {
			p[k++] = ch;
			p[k] = '\0';
			pos = isEqual(p);
			if (pos != -1) {
				fileOut << arrayTree[pos].info;
				k = 0;
			}
		}
		else {
			cerr << "The code is wrong." << endl;
			exit(1);
		}
		fileIn >> ch;
	}

	fileIn.close();
	fileOut.close();
}
