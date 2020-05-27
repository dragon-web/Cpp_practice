#define _CRT_SECURE_NO_WARNINGS 

#include < stdio.h >
#include < stdlib.h >
#include < string.h >
#include<windows.h>


#define TRUE  1
#define FALSE 0


// 哈夫曼树( Huffman Tree ) 中节点的结构体类型定义( 静态三叉链表 ) ...
typedef struct HuffmanTreeNode  //自定义结构体类型
{
	float Weight; // 权重值 ...
	int   Parent; // 父结点在数组中的下表( 因为是静态三叉链表 ) ...
	int   LChild; // 左孩子在数组中的下表 ...
	int   RChild; // 右孩子在数组中的下表 ...
}HuffmanTreeNode;

// 信源符号集合( 欲编码和压缩的消息必须由下面字符组成 ) ...
const char *MSG_BASE_CHAR_SET = "ABCDE";   

// 编码表中的单个编码的结构体类型定义 ...
typedef struct HuffmanCodeNode
{
	char BaseChar;          // 信源符号 ...
	char HuffmanCode[20]; // 信源符号对应的 'Huffman' 编码 ...
}HuffmanCodeNode;
//根据频度编码的




void DisplayMsg(char *Title, char *Msg); //展示函数
void DisplayHuffmanCodeBook(HuffmanCodeNode *HuffmanCodeBook, int NumOfCharSet); //哈夫曼书表
void FindTwoMinWeights(HuffmanTreeNode *HuffmanTree, int N, int *k1, int *k2);//weight 权重
void CountEncodingMsgCharFrequency(char *Msg, float *pCharFreq, int NumOfCharSet);//统计编码信息中信源字符频度
void HuffmanEncoding(char *OrigMsg, char *EncodingMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook);
void HuffmanDecoding(char *EncodingMsg, char *OrigMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook);



// 显示字符串( 以 '#' 结尾 ) ...
void DisplayMsg(const char *Title, char *Msg)
{
	size_t k;

	if (strlen(Title) > 0)
		printf("\n\n\t%s", Title);

	// 依次输出各个字符 ...
	for (k = 0; k < strlen(Msg); k++)
	{
		if (*Msg != '#')
		{
			printf("%c", *Msg);
			Msg++;
		}
		else
			*(Msg + 1) = '\0';
	}

	printf("\n");
}

// 显示哈夫曼编码表 ...
void DisplayHuffmanCodeBook(HuffmanCodeNode *HuffmanCodeBook, int NumOfCharSet)
{
	int k;

	printf("\n\n\t生成的哈夫曼编码表为 :\n");

	// 依次输出各个编码 ...
	for (k = 0; k < NumOfCharSet; k++)
	{
		printf("\t字符 %c -> ", (HuffmanCodeBook + k)->BaseChar);
		DisplayMsg("", (HuffmanCodeBook + k)->HuffmanCode);
	}

	printf("\n");
}
// 从生成哈夫曼树的权值表中找出权值最小的 2 个根节点序号 ...
void FindTwoMinWeights(HuffmanTreeNode *HuffmanTree, int N, int *k1, int *k2)
{
	float Min1, Min2, wt; // 2 个最小值, 约定 'Min1 <= Min2' ...
	int k;

	// ( 1 ) 扫描第 1 遍寻找最小的值 ...

	// 'N' 表示生成哈夫曼树的权值表中的当前长度 ...
	Min1 = 2.0; // 权重值不会超过 '1.0' ...
	for (k = 0; k < N; k++)
	{
		if ((HuffmanTree + k)->Parent == -1) // 只处理权值表中的树根节点 ...
		{
			// 得到权重值 ...
			wt = (HuffmanTree + k)->Weight;

			if (Min1 > wt)
			{
				Min1 = wt;
				*k1 = k; // 记录 'Min1' 的位置 ...
			}
		}
	}

	// ( 2 ) 扫描第 2 遍寻找次小的值 ...

	// 'N' 表示生成哈夫曼树的权值表中的当前长度 ...
	Min2 = 2.0; // 权重值不会超过 '1.0' ...
	for (k = 0; k < N; k++)
	{
		if ((HuffmanTree + k)->Parent == -1) // 只处理权值表中的树根节点 ...
		{
			if (k != *k1)
			{
				// 得到权重值 ...
				wt = (HuffmanTree + k)->Weight;

				if ((Min2 > wt) && (Min2 >= Min1))
				{
					Min2 = wt;
					*k2 = k; // 记录 'Min2' 的位置 ...
				}
			}
		}
	}
}

// 统计待编码消息中信源字符的频度 ...
void CountEncodingMsgCharFrequency(char *Msg, float *pCharFreq, int NumOfCharSet)
{
	int  k, MsgLen;
	char *p;

	// 'Msg' 为待编码的字符串, 如 'AAABCDACBBA' ...
	MsgLen = strlen(Msg);
	if (MsgLen > 0)
	{
		// 初始化 ...
		for (k = 0; k < NumOfCharSet; k++)
			*(pCharFreq + k) = 0;

		p = Msg;
		while (*p) // 字符串没有结束 ...
		{
			if ((*p >= 'A') && (*p <= 'E')) // 输入字符的有效性检查 ...
			{
				k = *p - 'A';
				*(pCharFreq + k) = *(pCharFreq + k) + 1; // 统计字符出现的个数 ...
			}

			p++;
		}

		// 计算频度值 ...
		// ( 1 ) 'MsgCharFrequency' 数组中储存了信源中每个符号的频度, 'NumOfCharSet' 表示信源中符号的个数.
		// ( 2 ) 'MsgCharFrequency' 数组中元素的个数即为 'NumOfCharSet'.
		for (k = 0; k < NumOfCharSet; k++)
			*(pCharFreq + k) = *(pCharFreq + k) / MsgLen;
	}
}

// Huffman 编码 ...
void HuffmanEncoding(char *OrigMsg, char *EncodingMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook)
{
	float *pMsgCharFrequency;
	int k, k1, k2, kt, km, kn, N, Level, NodeParent, NodeChild;
	char HCode[20];

	// 创建统计信源符号频度的空间 ...
	pMsgCharFrequency = (float *)malloc(sizeof(float) * NumOfCharSet);
	if (pMsgCharFrequency == NULL)
	{
		printf("\n\n\t内存申请失败, 程序退出 ...");

		return;
	}

	// ( 1 ) 统计待编码消息中信源字符的频度( 将结果填充到 'pCharFreq' 中, 'pCharFreq' 空间已申请 ) ...
	CountEncodingMsgCharFrequency(OrigMsg, pMsgCharFrequency, NumOfCharSet);

	//////////////////////////////////////////////////////////////
	printf("\n\t待编码消息中信源字符的频度 :\n\t");
	for (k = 0; k < NumOfCharSet; k++)
		printf("%f ", *(pMsgCharFrequency + k));
	printf("\n");
	//////////////////////////////////////////////////////////////

	// ( 2 ) 初始化 'Huffman Tree' ...
	for (k = 0; k < (2 * NumOfCharSet - 1); k++)
	{
		// 前 'NumOfCharSet' 节点为叶子节点, 储存消息中字符的频度值 ... 
		if (k < NumOfCharSet)
			(HuffmanTree + k)->Weight = *(pMsgCharFrequency + k);
		else
			(HuffmanTree + k)->Weight = 0;

		// 其他属性
		(HuffmanTree + k)->Parent = -1; // 没有父节点 ...
		(HuffmanTree + k)->LChild = -1; // 没有左孩子和右孩子( 'Huffman Tree' 中节点坐标从 '0' 开始 ) ...
		(HuffmanTree + k)->RChild = -1;
	}

	// ( 3 ) 构造 'Huffman Tree' ...

	// 处理 'HuffmanTree' 的后 'NumOfCharSet - 1' 个节点 ...
	N = NumOfCharSet; // 权值表长度( 代表了处理节点的位置 ) ...
	for (k = 0; k < (NumOfCharSet - 1); k++)
	{
		// 从生成哈夫曼树的权值表中找出权值最小的 2 个根节点序号 ...
		FindTwoMinWeights(HuffmanTree, N, &k1, &k2);

		// 生成根节点( 权值较小者为左结点, 权值较大者为右结点 )并加入权值表 ...
		(HuffmanTree + N)->Weight = (HuffmanTree + k1)->Weight + (HuffmanTree + k2)->Weight;
		(HuffmanTree + N)->Parent = -1; // 根节点 ...
		(HuffmanTree + N)->LChild = k1; // 权值较小者为左结点 ...
		(HuffmanTree + N)->RChild = k2; // 权值较大者为右结点 ...

		// 从权值表中删除找出的 2 个节点( 设置父亲节点位置 ) ...
		(HuffmanTree + k1)->Parent = N;
		(HuffmanTree + k2)->Parent = N;

		// 处理下一个位置 ...
		N++;
	}

	//////////////////////////////////////////////////////////////
	printf("\n\t生成的哈夫曼树 :\n");
	for (k = 0; k < (2 * NumOfCharSet - 1); k++)
		printf("\t%f %d %d %d\n", (HuffmanTree + k)->Weight, (HuffmanTree + k)->Parent, (HuffmanTree + k)->LChild, (HuffmanTree + k)->RChild);
	printf("\n");
	//////////////////////////////////////////////////////////////

	// ( 4 ) 生成编码表 'HuffmanCodeBook' ...
	// ( 设所有的结点左结点为 '0', 右结点为 '1', 从根结点开始经中间结点到达叶结点, 其路径代码即是该结点的 'Huffman' 编码 )

	// 初始化 'Huffman' 编码表 ...
	for (k = 0; k < NumOfCharSet; k++)
	{
		(HuffmanCodeBook + k)->BaseChar = MSG_BASE_CHAR_SET[k];
		(HuffmanCodeBook + k)->HuffmanCode[0] = '#'; // 码字结束标记 ...
	}

	// 从每个叶子出发, 由底向上达到父结点, 得到编码 ...
	// ( 权值表中的前 'NumOfCharSet' 各节点即为叶子结点 )
	for (k = 0; k < NumOfCharSet; k++)
	{
		Level = 0; // 叶子结点所处的层数 ...
		kt = 0;
		NodeChild = k;

		NodeParent = (HuffmanTree + k)->Parent;
		while (NodeParent != -1)
		{
			if ((HuffmanTree + NodeParent)->LChild == NodeChild) // 当前结点是父结点的左孩子 ...
			{
				HCode[kt] = '0';
				kt++;
			}
			else if ((HuffmanTree + NodeParent)->RChild == NodeChild) // 当前结点是父结点的右孩子 ...
			{
				HCode[kt] = '1';
				kt++;
			}

			// 继续回溯父结点直到根节点 ...
			NodeChild = NodeParent; // 当前父结点是上一层结点的孩子 ...
			NodeParent = (HuffmanTree + NodeParent)->Parent;

			// 增加结点的层数 ...
			Level++;
		}

		// 上述生成的编码信息是从叶子结点到根节点, 将其逆序 ...
		for (kt = Level - 1; kt >= 0; kt--)
			(HuffmanCodeBook + k)->HuffmanCode[Level - kt - 1] = HCode[kt];

		// 添加末尾结束字符 '#' ...
		(HuffmanCodeBook + k)->HuffmanCode[Level] = '#';
	}

	//////////////////////////////////////////////////////////////
	DisplayHuffmanCodeBook(HuffmanCodeBook, NumOfCharSet);
	//////////////////////////////////////////////////////////////

	// ( 5 ) 哈夫曼编码 ...
	km = 0;
	for (k = 0; k < strlen(OrigMsg); k++)
	{
		// 在编码表中查找字符 ...
		for (kt = 0; kt < NumOfCharSet; kt++)
			if (*(OrigMsg + k) == (HuffmanCodeBook + kt)->BaseChar)
				break;

		// 找到 ...
		if (kt < NumOfCharSet)
		{
			// 拷贝码字 ...
			kn = 0;
			while ((HuffmanCodeBook + kt)->HuffmanCode[kn] != '#')
			{
				*(EncodingMsg + km) = (HuffmanCodeBook + kt)->HuffmanCode[kn];

				km++;
				kn++;
			}
		}
	}

	// 添加末尾结束字符 '#' ...
	*(EncodingMsg + km) = '#';

	// 释放空间 ...
	free(pMsgCharFrequency);
}

// Huffman 解码 ... //遇到1往右走，遇到0往左走
/*void HuffmanDecoding(char *EncodingMsg, char *OrigMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook)
{
	size_t length = strlen(EncodingMsg);
	int root_index = 0;
	while (HuffmanTree[root_index].Parent != -1)
	{
		root_index++;
	}
	char decoded_text[100];
	int cur = 0;
	int j = 0;
	while (j < length)
	{ 
		HuffmanTreeNode* p = 
	}

}*/
void HuffmanDecoding(char *EncodingMsg, char *OrigMsg, int NumOfCharSet, HuffmanTreeNode *HuffmanTree, HuffmanCodeNode *HuffmanCodeBook)
{
	size_t len = strlen(EncodingMsg) - 1;  // #
	int root_Index = 0;
	while (HuffmanTree[root_Index].Parent != -1)//不是根
	{
		root_Index++;
	}

	char code;
	int p = root_Index;
	for (int i = 0; i < len; ++i)
	{
		code = EncodingMsg[i];
		if (code == '0')
			p = HuffmanTree[p].LChild;
		else
			p = HuffmanTree[p].RChild;
		if (HuffmanTree[p].LChild == -1 && HuffmanTree[p].RChild == -1)
		{
			*OrigMsg++ = MSG_BASE_CHAR_SET[p];  //ABCDE
			p = root_Index;
		}

	}
	/*
	int cur = 0;//写入数组的当前位置
	int j = 0;
	while (j < len)
	{
		int p = root_Index;//读到叶子节点结束
		while (HuffmanTree[p].LChild != -1 || HuffmanTree[p].RChild != -1)
		{
			char code = EncodingMsg[j++];
			if (code == '0')
			{
				p = HuffmanTree[p].LChild;
			}
			else
			{
				p = HuffmanTree[p].RChild;
			}
		}
		cur++;
	}
	*/
}
int main()
{
	int  IsStop;
	char UserInput[20];
	int  NumOfCharSet;
	char OrigMsg[100];     // 待编码的字符串 ...
	char EncodingMsg[100]; // 编码结果 ...

	char buffer[100] = { 0 };

	HuffmanTreeNode *HuffmanTree;  // Huffman Tree ...
	HuffmanCodeNode *HuffmanCodeBook; // Huffman 编码表 ...

	// 计算信源的符号个数 ...
	NumOfCharSet = strlen(MSG_BASE_CHAR_SET);

	// 开始处理 ...
	IsStop = FALSE;
	while (!IsStop)
	{
		fflush(stdin); // 清空缓冲区 ...
		// 读入待编码字符串 ...
		printf("\n\t请输入待编码字符串 : ");
		scanf("%s", OrigMsg);

		if (strlen(OrigMsg) > 0)
		{
			// 创建 'Huffman Tree' 的空间 ...
			HuffmanTree = (HuffmanTreeNode *)malloc(sizeof(HuffmanTreeNode) * (2 * NumOfCharSet - 1));
			if (HuffmanTree != NULL)
			{
				// 创建 'Huffman' 编码表的空间 ...
				HuffmanCodeBook = (HuffmanCodeNode *)malloc(sizeof(HuffmanCodeNode) * NumOfCharSet);
				if (HuffmanCodeBook != NULL)
				{
					// 进行 'Huffman' 编码 ...
					HuffmanEncoding(OrigMsg, EncodingMsg, NumOfCharSet, HuffmanTree, HuffmanCodeBook);

					// 输出编码结果 ...
					printf("\n\n\t< 信源符号 > %s", MSG_BASE_CHAR_SET);
					printf("\n\n\t< 原始信息 > %s", OrigMsg);
					DisplayMsg("< 编码信息 > ", EncodingMsg);

					// 进行 'Huffman' 解码 ...
					HuffmanDecoding(EncodingMsg, buffer, NumOfCharSet, HuffmanTree, HuffmanCodeBook);

					// 输出解码结果 ...
					//DisplayMsg("< 解码信息 > ", OrigMsg);
					printf("< 解码信息 >  : %s\n", buffer);

					// 释放空间 ...
					free(HuffmanCodeBook);
				}
				else
					printf("\n\n\t创建 Huffman 编码表失败 ...");

				// 释放空间 ...
				free(HuffmanTree);
			}
			else
				printf("\n\n\t创建 Huffman Tree 失败 ...");
		}
		else
			printf("\n\n\t输入的待编码字符串不能为空 ...");

		printf("\n\n\t继续进行 Huffman 编码[ Y / N ] ?");
		scanf("%s", UserInput);
		IsStop = ((UserInput[0] == 'n') || (UserInput[0] == 'N'));
	}

	// 等待用户输入任意一键返回 ...
	printf("\n\n");
	system("PAUSE");
	return 0;
}
