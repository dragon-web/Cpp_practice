#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
using namespace std;
class Arr
{
private:
	vector<vector<int>> arr;
public:
	void printArr(vector<vector<int>>& arr);
	void prinDiagonal(vector<vector<int>>& arr);
};

int main()
{
	int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
	system("pause");
	return 0;
}