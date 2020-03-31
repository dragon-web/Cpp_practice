#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> res;
		queue<vector<int>>qu;
		int begin = 0, twobegin = 0;
		for (size_t i = begin; i < nums.size(); i++) {
			swap(nums[i], nums[begin]);
			qu.emplace(nums);
			twobegin = 0;
			while (!qu.empty()) {
				int sz = qu.size();
				twobegin++;
				while (sz--) {
					vector<int> temp = qu.front();
					if (twobegin == nums.size()) res.emplace_back(temp);
					qu.pop();
					for (size_t i = twobegin; i < nums.size(); i++) {
						swap(temp[i], temp[twobegin]);
						qu.emplace(temp);
						swap(temp[i], temp[twobegin]);
					}
				}
			}
			swap(nums[i], nums[begin]);
		}
		return res;
	}
};



int main()
{
	Solution A;
	int arr[] = {1,2,3};
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	A.permute(test);
	vector<vector<int>> p = A.permute(test);
	vector<vector<int>>::iterator it = p.begin();
	for (it; it != p.end(); ++it)
	{
		for (size_t i = 0; i < (*it).size(); ++i)
		{
			cout << (*it)[i]<<" ";
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}

