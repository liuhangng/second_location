#pragma once
#include "common.h"

using namespace std;
class Solution_permutation
{
public:
	vector<vector<int>> K_sum(const vector<int>&nums, int target)
	{
		vector<vector<int>> res;
		vector<int>tmp;
		//vector<bool>used(nums.size(),false);
		for (int i = 1; i <nums.size();i++)
		{
			Ksum_i(res, nums, tmp, target, i,0);
		}
		if (accumulate(nums.begin(), nums.end(), 0) == target)
			res.push_back(nums);
		return res;
	}
private:
	void Ksum_i(vector<vector<int>>&res, const vector<int>&nums,vector<int>tmp, int sum, int index,int begin)
	{
		if (begin == nums.size())return;
		if (index == 1)
		{
			auto k = find(nums.begin()+begin, nums.end(), sum);
			if (k == nums.end())return;
			int dis = distance(nums.begin(), k);
			tmp.push_back(dis);
			PRINTVECTOR(tmp);
			res.push_back(tmp);
		}
		else
		{
			for (int i = begin; i < nums.size(); i++)
			{		
				tmp.push_back(i);
				Ksum_i(res, nums, tmp, sum - nums[i], index - 1,i+1);
				tmp.erase(tmp.end() - 1);
			}
		}
	}
};



