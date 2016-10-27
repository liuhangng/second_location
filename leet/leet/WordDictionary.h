#pragma once
#include "common.h"

//leetcode
// .可以代表任一字符

//字典树

struct TrieNode2
{
	TrieNode2* next[26];
	bool isFinished;
	TrieNode2()
	{
		isFinished = false;
		for (int i=0;i<26;++i)
		{
			next[i] = NULL;
		}
	}
};

class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode2* p = root;
		for (char c:word)
		{
			if (p->next[c - 'a'] == NULL)p->next[c - 'a'] = new TrieNode2();
			p = p->next[c - 'a'];
		}
		p->isFinished = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		int n = word.size();
		if (n == 0)return true;
		queue<TrieNode2*>myqueue;  //bfs
		myqueue.push(root);
		TrieNode2* p;
		for (int i = 0;i < n;++i)
		{
			for (int j=0,s=myqueue.size();j<s;++j)
			{
				p = myqueue.front();
				myqueue.pop();
				if (word[i] == '.')
				{
					for (int j = 0;j < 26;j++)
					{
						if (p->next[j])myqueue.push(p->next[j]);
					}
				}
				else
				{
					if (p->next[word[i] - 'a'])myqueue.push(p->next[word[i] - 'a']);
				}
			}		
			if (myqueue.empty())return false;
		}
		while (!myqueue.empty())
		{
			p = myqueue.front();
			myqueue.pop();
			if (p->isFinished)return true;
		}
		return false;
	}

	bool search_DFS(string word)
	{
		if (word.size() == 0)return true;
		return __search_DFS(word, 0, root);
	}
	bool __search_DFS(string word, int pos, TrieNode2* root)
	{
		if (root == NULL)return false;
		if (pos >= word.size())return root->isFinished;
		if (word[pos] == '.')
		{
			for (int i = 0;i < 26;i++)
			{
				if (__search_DFS(word, pos + 1, root->next[i]))return true;
			}
			return false;
		}
		else
			return __search_DFS(word, pos + 1, root->next[word[pos] - 'a']);
	}
	WordDictionary()
	{
		root = new TrieNode2();
	}
private:
	//unordered_set<string>wordsave;
	TrieNode2* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");