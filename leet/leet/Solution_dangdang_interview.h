#pragma once
#include "common.h"

class Solution_dangdang_interview
{
public:

	int getSpace_GenearyList(string& s)
	{
		int res = 0;
		while (s[res] == ' ')res++;
		s.erase(0, res);
		return res;
	}


	string getRes_GenearyList(vector<string> InputString)
	{
		string res;
		if (InputString.size() < 1)return res;
		string s(InputString[0]);
		int preLevel = getSpace_GenearyList(s);
		res += s;
		if (InputString.size() < 2)return res;
		string tmp;
		for (int i = 1;i < InputString.size();++i)
		{
			tmp = InputString[i];
			int curlevel = getSpace_GenearyList(tmp);
			if (curlevel == preLevel)
			{
				res += ',' + tmp;
			}
			else if (curlevel > preLevel)
			{
				int i = curlevel - preLevel;
				while (i--)res.push_back('(');
				res += tmp;
			}
			else
			{
				int i = preLevel - curlevel;
				while (i--)res.push_back(')');
				res += ',' + tmp;
			}
			preLevel = curlevel;
		}
		while (preLevel--)res.push_back(')');
		return res;
	}

};