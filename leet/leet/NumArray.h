#pragma once
#include "common.h"

class NumArray2 {
public:
	NumArray2(vector<int> &nums): data(nums){
		for (int i=1;i<nums.size();i++)
		{
			data[i] += data[i - 1];
		}
	}

	int sumRange(int i, int j) {
		//return accumulate(data.begin() + i, data.begin() + j + 1, 0);
		if (i == 0)return data[j];
		else
			return data[j] - data[i - 1];
	}
private:
	vector<int>data;
};

iterator

class NumArray {
public:
	NumArray(vector<int> &nums):data(nums),sumRg(nums) {
		for (int i=1;i<sumRg.size();i++)
		{
			sumRg[i] += sumRg[i - 1];
		}
	}

	void update(int i, int val) {
		int dist = val-data[i];
		data[i] = val;
		for (int index=i;i<sumRg.size();i++)
		{
			sumRg[i] += dist;
		}

	}

	int sumRange(int i, int j) {
		if (i == 0)return sumRg[j];
		else
			return sumRg[j] - sumRg[i - 1];
	}
private:
	vector<int>data;
	vector<int>sumRg;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);