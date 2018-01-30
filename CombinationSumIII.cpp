//https://leetcode.com/problems/combination-sum-iii/description/
//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output :
//
//[[1, 2, 4]]
//
//Example 2 :
//
//Input : k = 3, n = 9
//
//Output :
//
//[[1, 2, 6], [1, 3, 5], [2, 3, 4]]

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		vector<int> vt;
		engine(ret, vt, 0, k, n);
		return ret;
	}
	void engine(vector<vector<int>>& ret, vector<int> vt, const int cur, const int k, const int n)
	{
		int temp = 0;
		for (auto& a : vt) // if sum exceeds, terminate current routine.
		{
			temp += a;
			if (temp > n)
				return ;
		}
		for (int i = cur + 1; i <= 9; i++)
		{
			if (vt.size() < k)
			{
				vt.push_back(i);
				if (vt.size() == k)
				{
					int sum = 0;
					for (auto& a : vt)
						sum += a;
					if (sum == n)
					{
						ret.push_back(vt);
						return ;
					}
					vt.pop_back();
				}
				else
				{
					engine(ret, vt, i, k, n);
					vt.pop_back();
				}
			}
		}
		return ;
	}
};