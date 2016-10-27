#pragma once
#include "common.h"

class Solution_string_break
{
public:
	/************************************************************************/
	/* 只需要检查是否可以分割成wordDict里面的组合 */
	/************************************************************************/
	bool wordBreak_I(string s, unordered_set<string>& wordDict) {
		//dp,用一个bool表示，到当前位置，能够拼接
		int n = s.size();
		vector<bool>dp(n + 1, false);
		dp[0] = true;
		for (int i = 1;i < n;i++)
		{
			for (int j = i - 1;j >= 0;--j)
			{
				if (wordDict.find(s.substr(j, i - j)) != wordDict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};