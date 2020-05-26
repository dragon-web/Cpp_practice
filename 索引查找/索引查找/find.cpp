#define _CRT_SECURE_NO_WARNINGS 

#include < stdio.h >
#include < stdlib.h >
#include < time.h >
#include<Windows.h>


#define MAX_RECORD_NUM 50
#define MAX_BLOCK_NUM  10
#define TRUE           1
#define FALSE          0

// 用结构体定义索引表中的每一项( 对应每一块 ) ...
typedef struct
{
	int MaxKey; // 每一块中的最大关键字
	int Start;  // 块中第一个记录的位置
	int End;    // 块中最后一个记录的位置
} BlockIndexRecord;

// 用结构体定义找到的关键字的位置 ...
typedef struct
{
	int BlockNo; // 块号
	int Pos;     // 块内位置
} KeyPosRecord;

int  SeqSearch(int Key, int *p, int N);
void CreateDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);
void DisplayDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);
KeyPosRecord IndexSearch(int Key, int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum);

// 在一个块内实现带 '哨兵' 的顺序查找算法 ...
// Key - 待查找的关键字
// p   - 指向块中 '哨兵' 位置( 块中的第一个元素)
// N   - 块长度( 含 '哨兵' )
int SeqSearch(int Key, int *p, int N)
{
	int k;

	*p = Key; // '哨兵' 赋值 ...

	// 顺序查找 ...
	k = N - 1;
	while (*(p + k) != Key)
		k--;

	// 返回 '0' 表示未找到关键字 'Key' ...
	return k;
}

// 使用随机数据创建查找表中的数据, 并在此基础上建立索引表 ...
// pData      : 指向查找表数据的指针( 传入前已经创建好 )
// pBlock     : 指向索引表数据的指针( 传入前已经创建好 )
// RecNum     : 生成的查找表中的记录数目
// BlockNum   : 查找表分块的数目
void CreateDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int RecNumPerBlock; // 每一块中的记录数目( 假定每一块中的记录数目相等 ) ...
	int *pKey, *pt, k, kt, ks, ke, km, CurrMaxKey, PrevMaxKey;

	// 生成随机数种子 ...
	srand((unsigned)time(NULL));

	// 为每一块随机生成一个最大 'Key' 值 ...
	pKey = (int *)malloc(sizeof(int) * BlockNum);
	if (pKey != NULL)
	{
		// 第一块的最大 'Key' 值( 在 50 至 100 之间 ) ...
		*(pKey + 0) = 50 + rand() % (100 - 50);

		// 生成其他块的最大 'Key' 值 ...
		// ( 下一块的最大 'Key' 值在上一块的最大 'Key' 值的基础上增加一个随机数, 保证 '分块有序' )
		for (k = 1; k < BlockNum; k++)
			*(pKey + k) = *(pKey + k - 1) + (50 + rand() % (100 - 50));

		// 计算每一块中的记录数( 包含 '哨兵' 的位置 ) ...
		RecNumPerBlock = (int)(RecNum / BlockNum);

		// 随机生成查找表中的数据( 依次处理每一个数据块 ) ...
		pt = pData;
		PrevMaxKey = 0;
		for (k = 0; k < BlockNum; k++)
		{
			// 得到当前块的最大 'Key' 值 ...
			CurrMaxKey = *(pKey + k);

			// 先填充最大 'Key' 值 ...
			ks = k * RecNumPerBlock + 1; // 跳过 '哨兵' 节点位置 ...
			ke = k * RecNumPerBlock + (RecNumPerBlock - 1);

			// 随机生成 '1 ~ ( RecNumPerBlock - 1 )' 之间的一个随机位置 ...
			km = rand() % (RecNumPerBlock - 1) + 1;

			// 填充最大 'Key' 值 ...
			*(pt + km) = CurrMaxKey;

			// 每一个数据块中的所有值不能超过最大 'Key' 值, 而且要大于上一个块的最大 'Key' 值 ...
			for (kt = 1; kt < RecNumPerBlock; kt++)
				if (kt != km)
					*(pt + kt) = PrevMaxKey + rand() % (CurrMaxKey - PrevMaxKey) + 1;

			// 填充索引表 ...
			(pBlock + k)->MaxKey = CurrMaxKey;
			(pBlock + k)->Start = ks;
			(pBlock + k)->End = ke;

			// 处理下一个数据块 ...
			pt += RecNumPerBlock;

			// 设置前一个块的最大 'Key' 值 ...
			PrevMaxKey = CurrMaxKey;
		}

		// 释放空间 ...
		free(pKey);
	}
}

// 显示数据与索引 ...
void DisplayDataAndIndex(int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int k, kt, RecNumPerBlock;
	int *p;

	// 计算每一块中的记录数( 包含 '哨兵' 记录 ) ...
	RecNumPerBlock = (int)(RecNum / BlockNum);

	// 依次显示每一个数据块和对应的索引信息 ...
	p = pData;
	for (k = 0; k < BlockNum; k++)
	{
		printf("\n\t< 第 %d 个数据块的信息 >", (k + 1));

		// 显示数据 ...
		printf("\n\t数据 : ");
		for (kt = 1; kt < RecNumPerBlock; kt++)
			printf("%d ", *(p + kt));
		printf("\n");

		// 显示索引 ...
		printf("\t索引 : %d %d %d\n", (pBlock + k)->MaxKey, (pBlock + k)->Start, (pBlock + k)->End);

		// 处理下一个数据块 ...
		p += RecNumPerBlock;
	}
}
// 使用随机数据创建查找表中的数据, 并在此基础上建立索引表 ...
// pData      : 指向查找表数据的指针( 传入前已经创建好 ) 
// pBlock     : 指向索引表数据的指针( 传入前已经创建好 )
// RecNum     : 生成的查找表中的记录数目
// BlockNum   : 查找表分块的数目
// 索引查找 ...
// ( 本函数要求同学实现 )
KeyPosRecord IndexSearch(int Key, int *pData, BlockIndexRecord *pBlock, int RecNum, int BlockNum)
{
	int k, RecNumPerBlock;
	RecNumPerBlock = (int)(RecNum / BlockNum);
	KeyPosRecord KeyPos;
	// 初始化 ...
	KeyPos.BlockNo = 0;
	KeyPos.Pos = 0;
	int j;
	for (k = 0; k < BlockNum; ++k)
	{
		if (Key <= pBlock[k].MaxKey )
			break;
	}
	if (k == BlockNum)//结束循环退出的
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
	int  Key;                   // 待查找的关键字 ...
	int  *DataPtr;              // 指向查找表数据的指针 ...
	BlockIndexRecord *IndexPtr; // 指向索引表的指针 ...
	KeyPosRecord KeyPos;        // 找到的关键字的位置 ...

	// 创建数据和索引空间( 每个块中的数据增加 1 个 '哨兵' 的位置, 用于块内顺序查找 ) ...
	DataPtr = (int *)malloc(sizeof(int) * (MAX_RECORD_NUM + MAX_BLOCK_NUM));  //数据表指针
	IndexPtr = (BlockIndexRecord *)malloc(sizeof(BlockIndexRecord) * MAX_BLOCK_NUM);//索引表指针
	if ((DataPtr == NULL) || (IndexPtr == NULL))
	{
		// 处理可能其中之一申请成功, 则需要释放空间 ...
		if (DataPtr != NULL)
			free(DataPtr);

		if (IndexPtr != NULL)
			free(IndexPtr);

		printf("\n\n");
		printf("\n\t内存申请失败, 程序退出 ...");

		return 0;
	}

	// 生成随机数据用于分块查找 ...
	CreateDataAndIndex(DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);

	// 开始处理 ...
	IsStop = FALSE;
	while (!IsStop)
	{
		fflush(stdin); // 清空缓冲区 ...

		// 显示生成的数据 ...
		DisplayDataAndIndex(DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);

		// 分块查找 ...
		printf("\n\t请输入待查找记录的关键字 : ");
		scanf("%d", &Key);
		KeyPos = IndexSearch(Key, DataPtr, IndexPtr, (MAX_RECORD_NUM + MAX_BLOCK_NUM), MAX_BLOCK_NUM);
		if ((KeyPos.BlockNo == 0) || (KeyPos.Pos == 0))
			printf("\n\n\t未找到相关记录 ...");
		else
			printf("\n\n\t已找到相关记录, 位于第 %d 块, 块内地址为 %d ...", KeyPos.BlockNo, KeyPos.Pos);

		printf("\n\n\t继续进行分块查找[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// 释放空间 ...
	free(DataPtr);
	free(IndexPtr);

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
