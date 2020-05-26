#define _CRT_SECURE_NO_WARNINGS 

#include < stdio.h >
#include < stdlib.h >
#include < time.h >
#include<Windows.h>


#define MAX_RECORD_NUM 50
#define MAX_BLOCK_NUM  10
#define TRUE           1
#define FALSE          0

// �ýṹ�嶨���������е�ÿһ��( ��Ӧÿһ�� ) ...
typedef struct
{
	int MaxKey; // ÿһ���е����ؼ���
	int Start;  // ���е�һ����¼��λ��
	int End;    // �������һ����¼��λ��
} BlockIndexRecord;

// �ýṹ�嶨���ҵ��Ĺؼ��ֵ�λ�� ...
typedef struct
{
	int BlockNo; // ���
	int Pos;     // ����λ��
} KeyPosRecord;

int  SeqSearch(int Key, int *p, int N);
void CreateDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);
void DisplayDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);
KeyPosRecord IndexSearch(int Key, int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);

// ��һ������ʵ�ִ� '�ڱ�' ��˳������㷨 ...
// Key - �����ҵĹؼ���
// p   - ָ����� '�ڱ�' λ��( ���еĵ�һ��Ԫ��)
// N   - �鳤��( �� '�ڱ�' )
int SeqSearch(int Key, int *p, int N)
{
	int k;

	*p = Key; // '�ڱ�' ��ֵ ...

	// ˳����� ...
	k = N - 1;
	while (*(p + k) != Key)
		k--;

	// ���� '0' ��ʾδ�ҵ��ؼ��� 'Key' ...
	return k;
}

// ʹ��������ݴ������ұ��е�����, ���ڴ˻����Ͻ��������� ...
// pData      : ָ����ұ����ݵ�ָ��( ����ǰ�Ѿ������� )
// pBlock     : ָ�����������ݵ�ָ��( ����ǰ�Ѿ������� )
// RecNum     : ���ɵĲ��ұ��еļ�¼��Ŀ
// BlockNum   : ���ұ�ֿ����Ŀ
void CreateDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int RecNumPerBlock; // ÿһ���еļ�¼��Ŀ( �ٶ�ÿһ���еļ�¼��Ŀ��� ) ...
	int *pKey, *pt, k, kt, ks, ke, km, CurrMaxKey, PrevMaxKey;

	// ������������� ...
	srand((unsigned)time(NULL));

	// Ϊÿһ���������һ����� 'Key' ֵ ...
	pKey = (int *)malloc(sizeof(int) * BlockNum);
	if (pKey != NULL)
	{
		// ��һ������ 'Key' ֵ( �� 50 �� 100 ֮�� ) ...
		*(pKey + 0) = 50 + rand() % (100 - 50);

		// �������������� 'Key' ֵ ...
		// ( ��һ������ 'Key' ֵ����һ������ 'Key' ֵ�Ļ���������һ�������, ��֤ '�ֿ�����' )
		for (k = 1; k < BlockNum; k++)
			*(pKey + k) = *(pKey + k - 1) + (50 + rand() % (100 - 50));

		// ����ÿһ���еļ�¼��( ���� '�ڱ�' ��λ�� ) ...
		RecNumPerBlock = (int)(RecNum / BlockNum);

		// ������ɲ��ұ��е�����( ���δ���ÿһ�����ݿ� ) ...
		pt = pData;
		PrevMaxKey = 0;
		for (k = 0; k < BlockNum; k++)
		{
			// �õ���ǰ������ 'Key' ֵ ...
			CurrMaxKey = *(pKey + k);

			// �������� 'Key' ֵ ...
			ks = k * RecNumPerBlock + 1; // ���� '�ڱ�' �ڵ�λ�� ...
			ke = k * RecNumPerBlock + (RecNumPerBlock - 1);

			// ������� '1 ~ ( RecNumPerBlock - 1 )' ֮���һ�����λ�� ...
			km = rand() % (RecNumPerBlock - 1) + 1;

			// ������ 'Key' ֵ ...
			*(pt + km) = CurrMaxKey;

			// ÿһ�����ݿ��е�����ֵ���ܳ������ 'Key' ֵ, ����Ҫ������һ�������� 'Key' ֵ ...
			for (kt = 1; kt < RecNumPerBlock; kt++)
				if (kt != km)
					*(pt + kt) = PrevMaxKey + rand() % (CurrMaxKey - PrevMaxKey) + 1;

			// ��������� ...
			(pBlock + k)->MaxKey = CurrMaxKey;
			(pBlock + k)->Start = ks;
			(pBlock + k)->End = ke;

			// ������һ�����ݿ� ...
			pt += RecNumPerBlock;

			// ����ǰһ�������� 'Key' ֵ ...
			PrevMaxKey = CurrMaxKey;
		}

		// �ͷſռ� ...
		free(pKey);
	}
}

// ��ʾ���������� ...
void DisplayDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int k, kt, RecNumPerBlock;
	int *p;

	// ����ÿһ���еļ�¼��( ���� '�ڱ�' ��¼ ) ...
	RecNumPerBlock = (int)(RecNum / BlockNum);

	// ������ʾÿһ�����ݿ�Ͷ�Ӧ��������Ϣ ...
	p = pData;
	for (k = 0; k < BlockNum; k++)
	{
		printf("\n\t< �� %d �����ݿ����Ϣ >", (k + 1));

		// ��ʾ���� ...
		printf("\n\t���� : ");
		for (kt = 1; kt < RecNumPerBlock; kt++)
			printf("%d ", *(p + kt));
		printf("\n");

		// ��ʾ���� ...
		printf("\t���� : %d %d %d\n", (pBlock + k)->MaxKey, (pBlock + k)->Start, (pBlock + k)->End);

		// ������һ�����ݿ� ...
		p += RecNumPerBlock;
	}
}
// ʹ��������ݴ������ұ��е�����, ���ڴ˻����Ͻ��������� ...
// pData      : ָ����ұ����ݵ�ָ��( ����ǰ�Ѿ������� ) 
// pBlock     : ָ�����������ݵ�ָ��( ����ǰ�Ѿ������� )
// RecNum     : ���ɵĲ��ұ��еļ�¼��Ŀ
// BlockNum   : ���ұ�ֿ����Ŀ
// �������� ...
// ( ������Ҫ��ͬѧʵ�� )
KeyPosRecord IndexSearch(int Key, int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int k, RecNumPerBlock;
	RecNumPerBlock = (int)(RecNum / BlockNum);
	KeyPosRecord KeyPos;
	// ��ʼ�� ...
	KeyPos.BlockNo = 0;
	KeyPos.Pos = 0;
	int j;
	for (k = 0; k < BlockNum; ++k)
	{
		if (Key <= pBlock[k].MaxKey )
			break;
	}
	if (k == BlockNum)//����ѭ���˳���
		KeyPos.BlockNo = 0;
	else
	{
		j = pBlock[k].Start;
		KeyPos.BlockNo = k+1;
		while (j < pBlock[k].End)
		{
			if (Key == pData[j])
				break;
			else
				j++;
		}
		if (j >= pBlock[k].End)
		{
			KeyPos.Pos = 0;
		}
		else
		{
			KeyPos.Pos = j;
		}
	}
	return KeyPos;
}
int main()
{
	int  IsStop;
	char UserInput[20];
	int  Key;                   // �����ҵĹؼ��� ...
	int  *DataPtr;              // ָ����ұ����ݵ�ָ�� ...
	BlockIndexRecord *IndexPtr; // ָ���������ָ�� ...
	KeyPosRecord KeyPos;        // �ҵ��Ĺؼ��ֵ�λ�� ...

	// �������ݺ������ռ�( ÿ�����е��������� 1 �� '�ڱ�' ��λ��, ���ڿ���˳����� ) ...
	DataPtr = (int *)malloc(sizeof(int) * (MAX_RECORD_NUM + MAX_BLOCK_NUM));  //���ݱ�ָ��
	IndexPtr = (BlockIndexRecord *)malloc(sizeof(BlockIndexRecord) * MAX_BLOCK_NUM);//������ָ��
	if ((DataPtr == NULL) || (IndexPtr == NULL))
	{
		// �����������֮һ����ɹ�, ����Ҫ�ͷſռ� ...
		if (DataPtr != NULL)
			free(DataPtr);

		if (IndexPtr != NULL)
			free(IndexPtr);

		printf("\n\n");
		printf("\n\t�ڴ�����ʧ��, �����˳� ...");

		return 0;
	}

	// ��������������ڷֿ���� ...
	CreateDataAndIndex(DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);

	// ��ʼ���� ...
	IsStop = FALSE;
	while (!IsStop)
	{
		fflush(stdin); // ��ջ����� ...

		// ��ʾ���ɵ����� ...
		DisplayDataAndIndex(DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);

		// �ֿ���� ...
		printf("\n\t����������Ҽ�¼�Ĺؼ��� : ");
		scanf("%d", &Key);
		KeyPos = IndexSearch(Key, DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);
		if ((KeyPos.BlockNo == 0) || (KeyPos.Pos == 0))
			printf("\n\n\tδ�ҵ���ؼ�¼ ...");
		else
			printf("\n\n\t���ҵ���ؼ�¼, λ�ڵ� %d ��, ���ڵ�ַΪ %d ...", KeyPos.BlockNo, KeyPos.Pos);

		printf("\n\n\t�������зֿ����[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// �ͷſռ� ...
	free(DataPtr);
	free(IndexPtr);

	// �ȴ��û���������һ������ ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
