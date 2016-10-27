#pragma once

#include "common.h"

class Solution_problem
{
public:
	int getMaxSatisfaction(const vector<vector<bool> >&roomconnect, const vector<int>&value, vector<bool>&used, int first, int M)
	{
		int N = value.size();
		if (M == 0)return 0;//Mwifi都已经覆盖
		if (countTrue(used) == N)return 0;

		int valuemax = 0;
		for (int i = first;i < N;i++)//下一次重新计算时，不能在包含这个点
		{
			if (used[i])continue;
			used[i] = true;
			int sumi = value[i];
			stack<int>ichange;
			for (int j = 0;j < N;j++)//与i相连的房间，以及i本身
			{
				if (used[j])continue;
				if (roomconnect[i][j])sumi += value[j];
				used[j] = true;
				ichange.push(j);
			}

			valuemax = std::max(valuemax, sumi + getMaxSatisfaction(roomconnect, value, used, i + 1, M - 1));
			used[i] = false;
			while (!ichange.empty())
			{
				used[ichange.top()] = false;
				ichange.pop();
			}
		}
		return valuemax;
	}
private:

	int countTrue(const vector<bool>&used)
	{
		int sum = 0;
		for (int i = 0;i < used.size();i++)
		{
			if (used[i])sum++;
		}
		return sum;
	}

};