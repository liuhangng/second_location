#pragma once
#include "common.h"

class Solution_string_break
{
public:
	/************************************************************************/
	/* ֻ��Ҫ����Ƿ���Էָ��wordDict�������� */
	/************************************************************************/
	bool wordBreak_I(string s, unordered_set<string>& wordDict) {
		//dp,��һ��bool��ʾ������ǰλ�ã��ܹ�ƴ��
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