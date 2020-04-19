#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

/*class Print
{
private:
	int Row;
	int Col;
public:
	Print(int m_row, int m_col,int* p);

};

Print::Print(int m_row,int m_col,int* p)
{
	this->Col = m_col;
	this->Row = m_row;
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_col; ++j)
		{
			if ((m_row + m_col + 1) % m_col == 0)
			{
				cout << endl;
			}
			cout << p[i + j];
		}
	}
}

int main()
{
	int col;
	int row;
	cout << "请输入行列" << endl;
	cin >> col >> row;
	int *p = new int[col*row];
	for (int i = 0; i < col;++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << "输入第" << i << "行" << "第" << j << "列"<<endl;
			cin >> p[i + j];
		}
	}
	Print::Print(row, col, p);
	system("pause");
	return 0;
} faliure*/


//警告，如果拿1维数组实现二维数组，会出现值的覆盖


class Print
{
private:
	int col;
	int row;
public:
	Print(int m_col,int m_row,int*p[]);
	void PrintDia(int m_col,int m_row,int **p);
};
Print::Print(int m_col, int m_row, int*p[])
{
	col = m_col;
	row = m_row;
	for (int i = 0;i < m_col;++i)
	{
		for (int j = 0; j < m_row; ++j)
		{
			cout << p[i][j]<<" ";
			if ((i + j + 1) % col == 0)
			{
				cout << endl;
			}
		}
	}
}

int main()
{
	int b[5][5] = { 1 };
	int **arr = (int **)b;
	Print::Print(5, 5, arr);
	system("pause");
	return 0;
}