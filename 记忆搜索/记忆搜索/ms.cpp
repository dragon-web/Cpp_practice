#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<algorithm>
using namespace std;

int Solution_1(int Col)
{

}


int arr[100][100];
int main()
{
	int n;
	cout << "请输入行数" << endl;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = Solution_1(i);
	cout << "最大路径和" << ans << endl;
	system("pause");
	return 0;
}