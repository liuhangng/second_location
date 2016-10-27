#pragma once
#include "common.h"


class Solution_string_ladder
{
public:
	int ladderLength2(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(endWord);
		queue<string>toVisit;
		addNextHopeString(beginWord, toVisit, wordList);
		int dist = 2;
		while (!toVisit.empty())
		{
			for (int i=0,n=toVisit.size();i<n;++i)
			{
				string s = toVisit.front();
				toVisit.pop();
				if (s == endWord)return dist;
				addNextHopeString(s, toVisit, wordList);
			}
			dist++;
		}
		return 0;
	}
	void addNextHopeString(string s, queue<string>&toVisit, unordered_set<string>&wordList)
	{
		for (int i = 0;i < s.size();++i)
		{
			char c = s[i];
			for (int j=0;j<26;++j)
			{
				s[i] = 'a' + j;
				if (wordList.find(s) != wordList.end())
				{
					toVisit.push(s);
					wordList.erase(s);
				}
			}
			s[i] = c;
		}
	}
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		wordList.erase(beginWord);
		wordList.erase(endWord);
		unordered_set<string>nextNei;
		unordered_set<string>preNei;
		int dist = 2;
		int len = beginWord.size();
		nextNei.insert(beginWord);
		preNei.insert(endWord);
		while (!nextNei.empty() && !preNei.empty())
		{
			if (nextNei.size() > preNei.size())
				swap(nextNei, preNei);
			unordered_set<string>itNext;
			for (auto s : nextNei)
			{
				for (int i = 0;i < len;i++)
				{
					char c = s[i];
					for (int j = 0;j < 26;j++)
					{
						s[i] = 'a' + j;
						if (preNei.find(s) != preNei.end())return dist;
						if (wordList.find(s) != wordList.end())
						{
							wordList.erase(s);
							itNext.insert(s);
						}
					}
					s[i] = c;
				}
			}
			dist++;
			swap(nextNei, itNext);
		}
		return 0;
	}



	void addNextHopeString2(string s, unordered_set<string>&toVisit, const unordered_set<string>&wordList,
		unordered_map<string,vector<string>>&stringWithLadder,
		const int& dis,unordered_map<string,int>&distanceToBeginword)
	{
		string ssaved(s);
		for (int i = 0;i < s.size();++i)
		{
			char c = s[i];
			for (int j = 0;j < 26;++j)
			{
				s[i] = 'a' + j;
				if (wordList.find(s) != wordList.end())
				{
					if (distanceToBeginword[s]>=dis)
					{
						toVisit.insert(s);
						stringWithLadder[ssaved].push_back(s);
						distanceToBeginword[s] = dis; //如果这个邻居节点已经在更短的路径上了，那么当前节点就不能把它作为下一跳的节点
					}
				}
			}
			s[i] = c;
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
	{
		wordList.insert(endWord);
		unordered_map<string, vector<string>>stringWithLadder;
		unordered_set<string>toVisit;
		toVisit.insert(beginWord);
		wordList.erase(beginWord);
		bool isMeet = false;
		while (isMeet==false&&!toVisit.empty())
		{
			unordered_set<string>nextNeigb;
			for (string s:toVisit)
			{
				if (s == endWord)
				{
					isMeet = true;
				}
				else
				{
					if (isMeet == true)continue;
					string ssaved(s);
					for (int i = 0;i < s.size();++i)
					{
						char c = s[i];
						for (char j = 'a';j <= 'z';++j)
						{
							if (j == c)continue;
							s[i] = j;
							if (wordList.find(s) != wordList.end())
							{
									nextNeigb.insert(s);
									stringWithLadder[ssaved].push_back(s);
							}
						}
						s[i] = c;
					}
				}
			}
			for (string t:nextNeigb)
			{
				wordList.erase(t);
			}
			toVisit = nextNeigb;
		}
		vector<vector<string>>res;
		if (isMeet == false)return res;
		vector<string>path(1,beginWord);
		backTrackDFS( beginWord,endWord,stringWithLadder,path,res);
		return res;
	}
	void backTrackDFS(string beginWord,string endWord, unordered_map<string, vector<string>>stringWithLadder, vector<string>&path,vector<vector<string>>&res)
	{
		if (endWord == beginWord)
		{
			res.push_back(path);
			return;
		}
		for (string s:stringWithLadder[beginWord])
		{
			path.push_back(s);
			backTrackDFS(s, endWord, stringWithLadder, path, res);
			path.pop_back();
		}
	}


};



class Solution_string_ladder2 {
public:
	std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
		std::vector<std::vector<std::string> > paths;
		std::vector<std::string> path(1, beginWord);
		if (beginWord == endWord) {
			paths.push_back(path);
			return paths;
		}
		std::unordered_set<std::string> words1, words2;
		words1.insert(beginWord);
		words2.insert(endWord);
		std::unordered_map<std::string, std::vector<std::string> > nexts;
		bool words1IsBegin = false;
		if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
			getPath(beginWord, endWord, nexts, path, paths);
		return paths;
	}
private:
	bool findLaddersHelper(
		std::unordered_set<std::string> &words1,
		std::unordered_set<std::string> &words2,
		std::unordered_set<std::string> &dict,
		std::unordered_map<std::string, std::vector<std::string> > &nexts,
		bool &words1IsBegin) {
		words1IsBegin = !words1IsBegin;
		if (words1.empty())
			return false;
		if (words1.size() > words2.size())
			return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
		for (auto it = words1.begin(); it != words1.end(); ++it)
			dict.erase(*it);
		for (auto it = words2.begin(); it != words2.end(); ++it)
			dict.erase(*it);
		std::unordered_set<std::string> words3;
		bool reach = false;
		for (auto it = words1.begin(); it != words1.end(); ++it) {
			std::string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
				for (*ch = 'a'; *ch <= 'z'; ++(*ch))
					if (*ch != tmp)
						if (words2.find(word) != words2.end()) {
							reach = true;
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
						}
						else if (!reach && dict.find(word) != dict.end()) {
							words3.insert(word);
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
						}
						*ch = tmp;
			}
		}
		return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
	}
	void getPath(
		std::string beginWord,
		std::string &endWord,
		std::unordered_map<std::string, std::vector<std::string> > &nexts,
		std::vector<std::string> &path,
		std::vector<std::vector<std::string> > &paths) {
		if (beginWord == endWord)
			paths.push_back(path);
		else
			for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
				path.push_back(*it);
				getPath(*it, endWord, nexts, path, paths);
				path.pop_back();
			}
	}
};
