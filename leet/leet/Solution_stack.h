#pragma once

#include "common.h"

class Solution_stack
{
public:
	bool isPopPush(vector<int>pushvec, vector<int>popvec)
	{
		int m = pushvec.size();
		int n = popvec.size();
		if (m != n)return false;
		if (m == 0)return false;
		stack<int>cache;
		for (int i = 0,j=0; i < m;i++)
		{
			cache.push(pushvec[i]);
			while (j<n&&!cache.empty()&&popvec[j]==cache.top())
			{
				cache.pop();
				j++;
			}
		}
		return cache.empty();
	}
	vector<vector<int>> printAllPopPush(const vector<int>&nums)
	{
		vector<int>pushvec(nums);
		vector<vector<int>>res;
		__printAllPopPush(res, pushvec, 0, nums);
		return res;
	}
private:
	void __printAllPopPush(vector<vector<int>>&res, vector<int>&nums, int index,const vector<int>& pushvec)
	{
		if (index == nums.size())
		{
			if(isPopPush(pushvec,nums))
				res.push_back(nums);
			return;
		}
		else
		{
			using std::swap;
			for (int i = index; i < nums.size();i++)
			{
				swap(nums[i], nums[index]);
				__printAllPopPush(res, nums, index+1, pushvec);
				swap(nums[i], nums[index]);
			}
		}
	}
};