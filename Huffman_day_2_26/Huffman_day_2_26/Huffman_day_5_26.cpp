#define _CRT_SECURE_NO_WARNINGS 

// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<windows.h>

#define TRUE  1
#define FALSE 0

// ��������( Huffman Tree ) �нڵ�Ľṹ�����Ͷ���( ��̬�������� ) ...
typedef struct HuffmanTreeNode
{
	float Weight; // Ȩ��ֵ ...
	int   Parent; // ������������е��±�( ��Ϊ�Ǿ�̬�������� ) ...
	int   LChild; // �����������е��±� ...
	int   RChild; // �Һ����������е��±� ...
}HuffmanTreeNode;

// ��Դ���ż���( �������ѹ������Ϣ�����������ַ���� ) ...
const char *MSG_BASE_CHAR_SET = "ABCDE";

// ������еĵ�������Ľṹ�����Ͷ��� ...
typedef struct HuffmanCodeNode
{
	char BaseChar;          // ��Դ���� ...
	char HuffmanCode[20]; // ��Դ���Ŷ�Ӧ�� 'Huffman' ���� ...
}HuffmanCodeNode;

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                            �����Ǹ�����������                               // 
//                                                                          // 
// ######################################################################## //

void DisplayMsg(char *Title, char *Msg);
void DisplayHuffmanCodeBook(HuffmanCodeNode *HuffmanCodeBook, int NumOfCharSet);
void FindTwoMinWeights(HuffmanTreeNode *HuffmanTree, int N, int *k1, int *k2);
void CountEncodingMsgCharFrequency(char *Msg, float *pCharFreq, int NumOfCharSet);//ͳ�Ʊ�����Ϣ����Դ�ַ�Ƶ��
void HuffmanEncoding(char *OrigMsg, char *EncodingMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook);
void HuffmanDecoding(char *EncodingMsg, char *OrigMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook);

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                           �����Ǹ���������ʵ��                               // 
//                                                                          // 
// ######################################################################## //

// ��ʾ�ַ���( �� '#' ��β ) ...
void DisplayMsg(const char *Title, char *Msg)
{
	int k;

	if (strlen(Title) > 0)
		printf("\n\n\t%s", Title);

	// ������������ַ� ...
	for (k = 0; k < strlen(Msg); k++)
	{
		if (*Msg != '#')
		{
			printf("%c", *Msg);
			Msg++;
		}
	}

	printf("\n");
}

// ��ʾ����������� ...
void DisplayHuffmanCodeBook(HuffmanCodeNode *HuffmanCodeBook, int NumOfCharSet)
{
	int k;

	printf("\n\n\t���ɵĹ����������Ϊ :\n");

	// ��������������� ...
	for (k = 0; k < NumOfCharSet; k++)
	{
		printf("\t�ַ� %c -> ", (HuffmanCodeBook + k)->BaseChar);
		DisplayMsg("", (HuffmanCodeBook + k)->HuffmanCode);
	}

	printf("\n");
}

// �����ɹ���������Ȩֵ�����ҳ�Ȩֵ��С�� 2 �����ڵ���� ...
void FindTwoMinWeights(HuffmanTreeNode *HuffmanTree, int N, int *k1, int *k2)
{
	float Min1, Min2, wt; // 2 ����Сֵ, Լ�� 'Min1 <= Min2' ...
	int k;

	// ( 1 ) ɨ��� 1 ��Ѱ����С��ֵ ...

	// 'N' ��ʾ���ɹ���������Ȩֵ���еĵ�ǰ���� ...
	Min1 = 2.0; // Ȩ��ֵ���ᳬ�� '1.0' ...
	for (k = 0; k < N; k++)
	{
		if ((HuffmanTree + k)->Parent == -1) // ֻ����Ȩֵ���е������ڵ� ...
		{
			// �õ�Ȩ��ֵ ...
			wt = (HuffmanTree + k)->Weight;

			if (Min1 > wt)
			{
				Min1 = wt;
				*k1 = k; // ��¼ 'Min1' ��λ�� ...
			}
		}
	}

	// ( 2 ) ɨ��� 2 ��Ѱ�Ҵ�С��ֵ ...

	// 'N' ��ʾ���ɹ���������Ȩֵ���еĵ�ǰ���� ...
	Min2 = 2.0; // Ȩ��ֵ���ᳬ�� '1.0' ...
	for (k = 0; k < N; k++)
	{
		if ((HuffmanTree + k)->Parent == -1) // ֻ����Ȩֵ���е������ڵ� ...
		{
			if (k != *k1)
			{
				// �õ�Ȩ��ֵ ...
				wt = (HuffmanTree + k)->Weight;

				if ((Min2 > wt) && (Min2 >= Min1))
				{
					Min2 = wt;
					*k2 = k; // ��¼ 'Min2' ��λ�� ...
				}
			}
		}
	}
}

// ͳ�ƴ�������Ϣ����Դ�ַ���Ƶ�� ...
void CountEncodingMsgCharFrequency(char *Msg, float *pCharFreq, int NumOfCharSet)
{
	int  k, MsgLen;
	char *p;

	// 'Msg' Ϊ��������ַ���, �� 'AAABCDACBBA' ...
	MsgLen = strlen(Msg);
	if (MsgLen > 0)
	{
		// ��ʼ�� ...
		for (k = 0; k < NumOfCharSet; k++)
			*(pCharFreq + k) = 0;

		p = Msg;
		while (*p) // �ַ���û�н��� ...
		{
			if ((*p >= 'A') && (*p <= 'E')) // �����ַ�����Ч�Լ�� ...
			{
				k = *p - 'A';
				*(pCharFreq + k) = *(pCharFreq + k) + 1; // ͳ���ַ����ֵĸ��� ...
			}

			p++;
		}

		// ����Ƶ��ֵ ...
		// ( 1 ) 'MsgCharFrequency' �����д�������Դ��ÿ�����ŵ�Ƶ��, 'NumOfCharSet' ��ʾ��Դ�з��ŵĸ���.
		// ( 2 ) 'MsgCharFrequency' ������Ԫ�صĸ�����Ϊ 'NumOfCharSet'.
		for (k = 0; k < NumOfCharSet; k++)
			*(pCharFreq + k) = *(pCharFreq + k) / MsgLen;
	}
}

// Huffman ���� ...
void HuffmanEncoding(char *OrigMsg, char *EncodingMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook)
{
	float *pMsgCharFrequency;
	int k, k1, k2, kt, km, kn, N, Level, NodeParent, NodeChild;
	char HCode[20];

	// ����ͳ����Դ����Ƶ�ȵĿռ� ...
	pMsgCharFrequency = (float *)malloc(sizeof(float) * NumOfCharSet);
	if (pMsgCharFrequency == NULL)
	{
		printf("\n\n\t�ڴ�����ʧ��, �����˳� ...");

		return;
	}

	// ( 1 ) ͳ�ƴ�������Ϣ����Դ�ַ���Ƶ��( �������䵽 'pCharFreq' ��, 'pCharFreq' �ռ������� ) ...
	CountEncodingMsgCharFrequency(OrigMsg, pMsgCharFrequency, NumOfCharSet);

	//////////////////////////////////////////////////////////////
	printf("\n\t��������Ϣ����Դ�ַ���Ƶ�� :\n\t");
	for (k = 0; k < NumOfCharSet; k++)
		printf("%f ", *(pMsgCharFrequency + k));
	printf("\n");
	//////////////////////////////////////////////////////////////

	// ( 2 ) ��ʼ�� 'Huffman Tree' ...
	for (k = 0; k < (2 * NumOfCharSet - 1); k++)
	{
		// ǰ 'NumOfCharSet' �ڵ�ΪҶ�ӽڵ�, ������Ϣ���ַ���Ƶ��ֵ ... 
		if (k < NumOfCharSet)
			(HuffmanTree + k)->Weight = *(pMsgCharFrequency + k);
		else
			(HuffmanTree + k)->Weight = 0;

		// ��������
		(HuffmanTree + k)->Parent = -1; // û�и��ڵ� ...
		(HuffmanTree + k)->LChild = -1; // û�����Ӻ��Һ���( 'Huffman Tree' �нڵ������ '0' ��ʼ ) ...
		(HuffmanTree + k)->RChild = -1;
	}

	// ( 3 ) ���� 'Huffman Tree' ...

	// ���� 'HuffmanTree' �ĺ� 'NumOfCharSet - 1' ���ڵ� ...
	N = NumOfCharSet; // Ȩֵ����( �����˴���ڵ��λ�� ) ...
	for (k = 0; k < (NumOfCharSet - 1); k++)
	{
		// �����ɹ���������Ȩֵ�����ҳ�Ȩֵ��С�� 2 �����ڵ���� ...
		FindTwoMinWeights(HuffmanTree, N, &k1, &k2);

		// ���ɸ��ڵ�( Ȩֵ��С��Ϊ����, Ȩֵ�ϴ���Ϊ�ҽ�� )������Ȩֵ�� ...
		(HuffmanTree + N)->Weight = (HuffmanTree + k1)->Weight + (HuffmanTree + k2)->Weight;
		(HuffmanTree + N)->Parent = -1; // ���ڵ� ...
		(HuffmanTree + N)->LChild = k1; // Ȩֵ��С��Ϊ���� ...
		(HuffmanTree + N)->RChild = k2; // Ȩֵ�ϴ���Ϊ�ҽ�� ...

		// ��Ȩֵ����ɾ���ҳ��� 2 ���ڵ�( ���ø��׽ڵ�λ�� ) ...
		(HuffmanTree + k1)->Parent = N;
		(HuffmanTree + k2)->Parent = N;

		// ������һ��λ�� ...
		N++;
	}

	//////////////////////////////////////////////////////////////
	printf("\n\t���ɵĹ������� :\n");
	for (k = 0; k < (2 * NumOfCharSet - 1); k++)
		printf("\t%f %d %d %d\n", (HuffmanTree + k)->Weight, (HuffmanTree + k)->Parent, (HuffmanTree + k)->LChild, (HuffmanTree + k)->RChild);
	printf("\n");
	//////////////////////////////////////////////////////////////

	// ( 4 ) ���ɱ���� 'HuffmanCodeBook' ...
	// ( �����еĽ������Ϊ '0', �ҽ��Ϊ '1', �Ӹ���㿪ʼ���м��㵽��Ҷ���, ��·�����뼴�Ǹý��� 'Huffman' ���� )

	// ��ʼ�� 'Huffman' ����� ...
	for (k = 0; k < NumOfCharSet; k++)
	{
		(HuffmanCodeBook + k)->BaseChar = MSG_BASE_CHAR_SET[k];
		(HuffmanCodeBook + k)->HuffmanCode[0] = '#'; // ���ֽ������ ...
	}

	// ��ÿ��Ҷ�ӳ���, �ɵ����ϴﵽ�����, �õ����� ...
	// ( Ȩֵ���е�ǰ 'NumOfCharSet' ���ڵ㼴ΪҶ�ӽ�� )
	for (k = 0; k < NumOfCharSet; k++)
	{
		Level = 0; // Ҷ�ӽ�������Ĳ��� ...
		kt = 0;
		NodeChild = k;

		NodeParent = (HuffmanTree + k)->Parent;
		while (NodeParent != -1)
		{
			if ((HuffmanTree + NodeParent)->LChild == NodeChild) // ��ǰ����Ǹ��������� ...
			{
				HCode[kt] = '0';
				kt++;
			}
			else if ((HuffmanTree + NodeParent)->RChild == NodeChild) // ��ǰ����Ǹ������Һ��� ...
			{
				HCode[kt] = '1';
				kt++;
			}

			// �������ݸ����ֱ�����ڵ� ...
			NodeChild = NodeParent; // ��ǰ���������һ����ĺ��� ...
			NodeParent = (HuffmanTree + NodeParent)->Parent;

			// ���ӽ��Ĳ��� ...
			Level++;
		}

		// �������ɵı�����Ϣ�Ǵ�Ҷ�ӽ�㵽���ڵ�, �������� ...
		for (kt = Level - 1; kt >= 0; kt--)
			(HuffmanCodeBook + k)->HuffmanCode[Level - kt - 1] = HCode[kt];

		// ���ĩβ�����ַ� '#' ...
		(HuffmanCodeBook + k)->HuffmanCode[Level] = '#';
	}

	//////////////////////////////////////////////////////////////
	DisplayHuffmanCodeBook(HuffmanCodeBook, NumOfCharSet);
	//////////////////////////////////////////////////////////////

	// ( 5 ) ���������� ...
	km = 0;
	for (k = 0; k < strlen(OrigMsg); k++)
	{
		// �ڱ�����в����ַ� ...
		for (kt = 0; kt < NumOfCharSet; kt++)
			if (*(OrigMsg + k) == (HuffmanCodeBook + kt)->BaseChar)
				break;

		// �ҵ� ...
		if (kt < NumOfCharSet)
		{
			// �������� ...
			kn = 0;
			while ((HuffmanCodeBook + kt)->HuffmanCode[kn] != '#')
			{
				*(EncodingMsg + km) = (HuffmanCodeBook + kt)->HuffmanCode[kn];

				km++;
				kn++;
			}
		}
	}

	// ���ĩβ�����ַ� '#' ...
	*(EncodingMsg + km) = '#';

	// �ͷſռ� ...
	free(pMsgCharFrequency);
}

// Huffman ���� ...
void HuffmanDecoding(char *EncodingMsg, char *OrigMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook)
{

	





}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             �������������ʵ��                              // 
//                                                                          // 
// ######################################################################## //

int main()
{
	int  IsStop;
	char UserInput[20];
	int  NumOfCharSet;
	char OrigMsg[100];     // ��������ַ��� ...
	char EncodingMsg[100]; // ������ ...

	HuffmanTreeNode *HuffmanTree;  // Huffman Tree ...
	HuffmanCodeNode *HuffmanCodeBook; // Huffman ����� ...

	// ������Դ�ķ��Ÿ��� ...
	NumOfCharSet = strlen(MSG_BASE_CHAR_SET);

	// ��ʼ���� ...
	IsStop = FALSE;
	while (!IsStop)
	{
		fflush(stdin); // ��ջ����� ...

		// ����������ַ��� ...
		printf("\n\t������������ַ��� : ");
		scanf("%s", OrigMsg);

		if (strlen(OrigMsg) > 0)
		{
			// ���� 'Huffman Tree' �Ŀռ� ...
			HuffmanTree = (HuffmanTreeNode *)malloc(sizeof(HuffmanTreeNode) * (2 * NumOfCharSet - 1));
			if (HuffmanTree != NULL)
			{
				// ���� 'Huffman' �����Ŀռ� ...
				HuffmanCodeBook = (HuffmanCodeNode *)malloc(sizeof(HuffmanCodeNode) * NumOfCharSet);
				if (HuffmanCodeBook != NULL)
				{
					// ���� 'Huffman' ���� ...
					HuffmanEncoding(OrigMsg, EncodingMsg, NumOfCharSet, HuffmanTree, HuffmanCodeBook);

					// ��������� ...
					printf("\n\n\t< ��Դ���� > %s", MSG_BASE_CHAR_SET);
					printf("\n\n\t< ԭʼ��Ϣ > %s", OrigMsg);
					DisplayMsg("< ������Ϣ > ", EncodingMsg);

					// ���� 'Huffman' ���� ...
					HuffmanDecoding(EncodingMsg, OrigMsg, NumOfCharSet, HuffmanTree, HuffmanCodeBook);

					// ��������� ...
					DisplayMsg("< ������Ϣ > ", OrigMsg);

					// �ͷſռ� ...
					free(HuffmanCodeBook);
				}
				else
					printf("\n\n\t���� Huffman �����ʧ�� ...");

				// �ͷſռ� ...
				free(HuffmanTree);
			}
			else
				printf("\n\n\t���� Huffman Tree ʧ�� ...");
		}
		else
			printf("\n\n\t����Ĵ������ַ�������Ϊ�� ...");

		printf("\n\n\t�������� Huffman ����[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
