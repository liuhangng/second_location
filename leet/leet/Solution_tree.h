#pragma once

#include "common.h"
#include "tree_node.h"

class Solution_tree
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val < root->val&&q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (q->val > root->val&&p->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else return root;
	}
	
	void recoverTree(TreeNode* root) {
		TreeNode* firsthNode = nullptr;
		TreeNode* secondeNode = nullptr;
		TreeNode* preNode = new TreeNode(INT_MIN);
		tracert_in_order(root, firsthNode, secondeNode,preNode);
		myswapTreenode(firsthNode, secondeNode);
	}
	void tracert_in_order(TreeNode *root, TreeNode* &firsthNode, TreeNode* &secondeNode, TreeNode* &preNode)
	{
		if (root == nullptr)return;
		tracert_in_order(root->left,firsthNode,secondeNode,preNode);
		if (firsthNode == nullptr&&preNode->val > root->val)
			firsthNode = preNode;
		if (firsthNode&&preNode->val > root->val)
			secondeNode = root;
		preNode = root;
		tracert_in_order(root->right,firsthNode,secondeNode,preNode);
	}
	void myswapTreenode(TreeNode* &node1, TreeNode* node2)
	{
		int temp = node1->val;
		node1->val = node2->val;
		node2->val = temp;
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<vector<int>>allpath;
		vector<string>res;
		if (root == NULL)return res;
		typedef pair<TreeNode*, vector<int>> Node;
		vector<int>tmp;
		queue <Node>cache;
		tmp.push_back(root->val);
		cache.push(Node(root, tmp));
		while (!cache.empty())
		{
			for (int i=0,n=cache.size();i<n;i++)
			{
				Node node = cache.front();
				cache.pop();
				node.second.push_back(node.first->val);
				if (node.first->left || node.first->right)
				{
					if (node.first->left)
					{
						cache.push(Node(node.first->left, node.second));
					}
					if (node.first->right)
					{
						cache.push(Node(node.first->right, node.second));
					}
				}
				else
				{
					allpath.push_back(node.second);
				}
			}
		}
		for (int i=0;i<allpath.size();++i)
		{
			res.push_back(__vectostring(allpath[i]));
		}
		return res;
	}
	vector<string> binaryTreePaths2(TreeNode* root)
	{
		vector<string>res;
		if (root != NULL) __searchBT(res, "", root);
		return res;
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)return 0;
		queue<TreeNode*>cache;
		cache.push(root);
		int level = 0;
		while (!cache.empty())
		{
			++level;
			for (int i=0,n=cache.size();i<n;i++)
			{
				TreeNode* tmp = cache.front();
				cache.pop();
				if (tmp->left == NULL&&tmp->right == NULL)return level;
				if (tmp->left)cache.push(tmp->left);
				if(tmp->right)cache.push(tmp->right);
			}
		}
		return level;

	}
	vector<int> preorderTraversal(TreeNode* root) {
		//节点，左，右
		vector<int>res;
		if (root == NULL)return res;
		stack<TreeNode*>cache;
		cache.push(root);
		TreeNode* tmp;
		
		while (!cache.empty())
		{
			tmp = cache.top();
			cache.pop();
			res.push_back(tmp->val);
			if (tmp->right)
			{
				cache.push(tmp->right);
			}
			if (tmp->left)
			{
				cache.push(tmp->left);
			}
			
		}
		return res;
	}

	vector<int> inordre_Traversr_Morris(TreeNode* root)
	{
		vector<int>res;
		if (root == NULL)return res;
		TreeNode* tmp = root;
		while (tmp!=NULL)
		{
			if (tmp->left == NULL)
			{
				res.push_back(tmp->val);
				tmp = tmp->right;
			}
			else
			{
				TreeNode* pPre = tmp->left;
				while (pPre->right != NULL&&pPre->right!=tmp)
				{
					pPre = pPre->right;
				}
				if (pPre->right == NULL)
				{
					pPre->right = tmp;
					tmp = tmp->left;
				}
				else
				{
					pPre->right = NULL;
					res.push_back(tmp->val);
					tmp = tmp->right;
				}
			}
		}
		return res;
	}
	vector<int> inordre_Traversr_stack(TreeNode* root)
	{
		vector<int>res;
		if (root == NULL)return res;
		stack<TreeNode*>stk;
		TreeNode* tmp=root;
		while (tmp != NULL || !stk.empty())
		{
			if (tmp != NULL)
			{
				stk.push(tmp);
				tmp = tmp->left;
			}
			else
			{
				tmp = stk.top();
				stk.pop();
				res.push_back(tmp->val);
				tmp = tmp->right;
			}
		}
		return res;
	}
	/************************************************************************/
	/* BST,二叉搜索树里面第K大的数       */
	/************************************************************************/
	int kthSmallest(TreeNode* root, int k) {
		//中序遍历，第k个数
		//采用morris
		int count = 0;
		TreeNode* tmp = root;
		while (tmp != NULL)
		{
			if (tmp->left == NULL)
			{
				count++;
				if (count == k)return tmp->val;
				tmp = tmp->right;
			}
			else
			{
				TreeNode* pPre = tmp->left;
				while (pPre->right != NULL&&pPre->right != tmp)
				{
					pPre = pPre->right;
				}
				if (pPre->right == NULL)
				{
					pPre->right = tmp;
					tmp = tmp->left;
				}
				else
				{
					pPre->right = NULL;
					count++;
					if (count == k)return tmp->val;
					tmp = tmp->right;
				}
			}
		}
		return tmp->val;
	}
	/************************************************************************/
	/* It will automatically contact the police 
	if two directly-linked houses were broken into on the same night.*/
	/************************************************************************/
	int rob(TreeNode* root) {
		//递归思路 way1
		/*if (root == NULL)return 0;
		if (root->left == NULL&&root->right == NULL)return root->val;
		if (root->left != NULL&&root->right == NULL)return std::max(root->val + rob(root->left->left) + rob(root->left->right), rob(root->left));
		if (root->left == NULL&&root->right != NULL)
			return std::max(root->val + rob(root->right->left) + rob(root->right->right), rob(root->right));
		return
			std::max(root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right), rob(root->left) + rob(root->right));*/
		
			//使用map way2,所有类似的单值递归都可以转为这样的情况
		/*unordered_map<TreeNode*, int>domap;
		return __rob(root, domap);*/

		//not rob,rob way3 两种情况
		auto res = __robSub(root);
		return std::max(res[0], res[1]);
	}
	vector<int>__robSub(TreeNode* root)
	{
		if (root == NULL)return vector<int>(2);
		vector<int>left = __robSub(root->left);
		vector<int>right = __robSub(root->right);
		vector<int>res(2,0);
		res[0] = max(left[0], left[1]) + max(right[0], right[1]); //如果当前节点不rob
		res[1] =root->val+ max(left[1], right[1]); //当前节点rob
		return res;
	}
	int __rob(TreeNode*root, unordered_map<TreeNode*, int>&domap)
	{
		if (root == NULL)return 0;
		if (domap.find(root) != domap.end())return domap[root];
		int val = 0;
		if (root->left)
			val += __rob(root->left->left, domap) + __rob(root->left->right, domap);
		if (root->right)
			val += __rob(root->right->left, domap) + __rob(root->right->right, domap);
		domap[root]=std::max(root->val + val, __rob(root->left, domap) + __rob(root->right, domap));
		return domap[root];
	}
	/************************************************************************/
	/* Given a binary tree, imagine yourself standing on the right side of it,
	  return the values of the nodes you can see ordered from top to bottom.*/
	/************************************************************************/
	vector<int> rightSideView(TreeNode* root) {
		vector<int>res;
		if (NULL == root)return res;
		//层次遍历，每个取最后的元素
		queue<TreeNode*>que;
		que.push(root);
		TreeNode* tmp;
		while (!que.empty())
		{
			for (int i=0,n=que.size();i<n;i++)
			{
				tmp = que.front();
				que.pop();
				if (tmp->left)que.push(tmp->left);
				if (tmp->right)que.push(tmp->right);
				if (i == n - 1)res.push_back(tmp->val);
			}
		}
		return res;
	}
	/************************************************************************/
	/* 完全二叉数的节点个数2                                                                     */
	/************************************************************************/
	int  height(TreeNode* root)
	{
		return root == NULL?-1 : 1 + height(root->left);
	}

	int countNodes(TreeNode* root) {
		int h = height(root);
		return h < 0 ? 0 :
			height(root->right) == (h - 1) ? (1 >> h) + countNodes(root->right) :
			(1 >> (h - 1)) + countNodes(root->left);
	}
private:

	void __searchBT(vector<string>&res, string path, TreeNode* root)
	{
		if (root->left == NULL&&root->right == NULL)
			res.push_back(path + to_string(root->val));
		if (root->left)
			__searchBT(res, path + to_string(root->val) + "->", root->left);
		if (root->right)
			__searchBT(res, path + to_string(root->val) + "->", root->right);

	}

	string __vectostring(const vector<int>& nums)
	{
		int n = nums.size();
		string s;
		if (n == 0)return s;
		stringstream ss;
		ss << nums[0];
		ss >> s;
		for (int i=1;i<n;i++)
		{
			ss.clear();
			ss << nums[i];
			string tmp;
			ss >> tmp;
			s = s + "->" + tmp;
		}
		return s;
	}
};