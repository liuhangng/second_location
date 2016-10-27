#pragma once
#include "common.h"

struct TrieNode
{
	//只有小写字母
	TrieNode* next[26];
	string nodecontent;
	TrieNode() 
	{
		fill_n(next, 26, 0);
		nodecontent = string("");
	}
};

//有很多string 构造成的root node

TrieNode* getTrieroot(const vector<string>&vs)
{
	TrieNode* root=new TrieNode();
	for (string x:vs)
	{
		TrieNode* p = root;
		for (char c:x)
		{
			int i = c - 'a';
			if (p->next[i]==NULL)
			{
				p->next[i] = new TrieNode();
			}
			p = p->next[i];
		}
		p->nodecontent = x;
	}
	return root;
}

class Solution_trieNode
{
public:
	/************************************************************************/
	/*在一个二维字符矩阵里面找到相邻元素能够拼接成word*/
	//使用 tries字典树和dfs
	/************************************************************************/
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string>res;
		TrieNode* root = getTrieroot(words);
		for (int i=0;i<board.size();++i)
		{
			for (int j=0;j<board[0].size();++j)
			{
				findWordsDFS(board, i, j, root, res);
			}
		}
		return res;
	}
	void findWordsDFS(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>&res)
	{
		char c = board[i][j];
		if (c == '#' || root->next[c - 'a'] == NULL)return;
		root = root->next[c - 'a'];
		if (root->nodecontent.size()!=0)
		{
			res.push_back(root->nodecontent);
			root->nodecontent.clear(); //防止其它路劲也可以找到这个string
		}
		board[i][j] = '#';
		if (j > 0)findWordsDFS(board, i, j - 1, root, res);
		if (i > 0)findWordsDFS(board, i - 1, j, root, res);
		if (j < board[0].size() - 1)findWordsDFS(board, i, j + 1, root, res);
		if (i < board.size() - 1)findWordsDFS(board, i + 1, j, root, res);
		board[i][j] = c;
	}
private:
};
