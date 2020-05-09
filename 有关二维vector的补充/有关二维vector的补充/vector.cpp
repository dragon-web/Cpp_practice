#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
	auto row = array.begin();
	auto line = (*row).begin();
	while (row != array.end())
	{
		line = (*row).begin();
		while (line != (*row).end())
		{
			if ((*line) == target)
			{
				return true;
			}
			line++;
		}
		row++;
	}
	return false;
}



int main()
{

	int array[] = { 1,2,5};
	/*vector<int> p(array,array+sizeof(array) / sizeof(array[0]));
	auto it = p.begin();
	while (it != p.end())
	{
		cout << *it << endl;
		it++;
	}*/
	vector<vector<int>> dp(5, vector<int>(array, array + sizeof(array) / sizeof(array[0])));
	
	
	cout << Find(0, dp) << endl;;
	
	
	
	
	
	
	
	/*cout << dp.size() << endl;//行数    5
	cout << dp[0].size() << endl;//列数  3

	/*for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < dp[0].size();++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	vector<vector<int>>::iterator toarr2 = dp.begin();
	vector<int>::iterator it = (*toarr2).begin();
	for (toarr2 = dp.begin(); toarr2 != dp.end(); ++toarr2) {
		for (it = (*toarr2).begin(); it != (*toarr2).end(); ++it) {
			std::cout << *it << " ";
		}
		cout << endl;
	}

	*/
	system("pause");
	return 0;
}