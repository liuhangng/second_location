#pragma once
#include "common.h"

struct TrieNode
{
	//ֻ��Сд��ĸ
	TrieNode* next[26];
	string nodecontent;
	TrieNode() 
	{
		fill_n(next, 26, 0);
		nodecontent = string("");
	}
};

//�кܶ�string ����ɵ�root node

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
	/*��һ����ά�ַ����������ҵ�����Ԫ���ܹ�ƴ�ӳ�word*/
	//ʹ�� tries�ֵ�����dfs
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
			root->nodecontent.clear(); //��ֹ����·��Ҳ�����ҵ����string
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
