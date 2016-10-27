#pragma once
#include "common.h"
#include "tree_node.h"

class Solution_vector
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int>res;
		if (nums1.size() == 0 || nums2.size() == 0)return res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				res.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
			{
				i++;
			}
			else j++;
		}
		if (res.size() < 2)return res;
		int index = 1;
		for (int k = 1;k < res.size();k++)
		{
			if (res[k] > res[k - 1])
				res[index++] = res[k];
		}
		res.erase(res.begin() + index, res.end());
		return res;

	}
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int>res;
		if (nums1.size() == 0 || nums2.size() == 0)return res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				res.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
			{
				i++;
			}
			else j++;
		}
		return res;
	}
	int majorityElement(const vector<int>& nums) {
		int major = nums[0], count = 1;
		for (int i = 1;i < nums.size();i++)
		{
			if (count == 0)
			{
				major = nums[i];
				count = 1;
			}
			else if (major == nums[i])
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		return major;
	}
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int>cache;
		for (int i = 0;i < nums.size();i++)
		{
			if (cache.find(nums[i]) == cache.end())
				cache.insert(nums[i]);
			else
				return true;
		}
		return false;
	}
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)return nums[0];
		vector<int>maxvalue(n + 2, 0);
		for (int i = 2;i <= n + 1;i++)
		{
			maxvalue[i] = std::max(maxvalue[i - 1], maxvalue[i - 2] + nums[i - 2]);
		}
		return maxvalue[n + 1];
	}
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int>cache;
		for (int i = 0;i < nums.size();i++)
		{
			if (i > k)cache.erase(nums[i - k - 1]);
			if (!cache.insert(nums[i]).second)return true;
		}
		return false;
	}

	int maxRotateFunction(vector<int>& A) {
		/*int n = A.size();
		if (n < 2)return 0;
		vector<int>indexprod(n, 0);
		int f = 0;
		iota(indexprod.begin(), indexprod.end(), f);
		int sumMax = INT_MIN;
		for (int i=0;i<n;i++)
		{
			int cursum = 0;
			for (int j=0;j<n;++j)
			{
				cursum += A[j] * indexprod[(j + i) % n];
			}
			if (cursum > sumMax)sumMax = cursum;
		}
		return sumMax;*/
		int n = A.size();
		if (n < 2)return 0;
		int f = 0;
		int allsum = 0;
		for (int i = 0;i < n;++i)
		{
			f += i*A[i];
			allsum += A[i];
		}
		int maxf = f;
		for (int i = n - 1;i >= 1;--i)
		{
			f = f + allsum - n*A[i];
			maxf = max(maxf, f);
		}
		return maxf;
	}
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2) {
			return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
		});
		vector<pair<int, int>> sol;
		for (auto person : people) {
			sol.insert(sol.begin() + person.second, person);
		}
		return sol;
	}
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int>res;
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right)
		{
			//while (numbers[left] == numbers[left + 1])left++;
			//while (numbers[right - 1] == numbers[right])right--;
			if (numbers[left] + numbers[right] == target)
			{
				res.push_back(left + 1);
				res.push_back(right + 1);
				return res;
			}
			else
			{
				if (numbers[left] + numbers[right] > target)
				{
					right--;
				}
				else
				{
					left++;
				}
			}
		}
		return res;
	}
	vector<int> singleNumber_two(vector<int>& nums) {
		//两个，其它都都出现了两次
		//两次异或操作
		vector<int>ress;
		int res = 0;
		for (auto i : nums)
			res = res^i;
		//找到res那个bit为1的位
		int count = 0;
		while (res)
		{
			if (res & 0x01)break;
			res >>= 1;
			count++;
		}
		int r1 = 0, r2 = 0;
		for (auto i : nums)
		{
			if ((i >> count) & 0x01)r1 ^= i;
			else
				r2 ^= i;
		}
		ress.push_back(r1);
		ress.push_back(r2);
		return ress;
	}
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int>res(nums.size(), 0);
		res[0] = 1;
		for (int i = 1;i < nums.size();++i)
		{
			res[i] = res[i - 1] * nums[i - 1];
		}
		int right = 1;
		for (int i = nums.size() - 1;i >= 0;--i)
		{
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//传统方法就是用一个unordermap
		unordered_map<int, int> map;
		for (int num : nums) {
			map[num]++;
		}

		vector<int> res;
		// pair<first, second>: first is frequency,  second is number
		priority_queue<pair<int, int>> pq;
		for (auto it = map.begin(); it != map.end(); it++) {
			pq.push(make_pair(it->second, it->first));
			if (pq.size() > (int)map.size() - k) {
				res.push_back(pq.top().second);
				pq.pop();
			}
		}
		return res;
	}
	int combinationSum4(vector<int>& nums, int target) {
		//递归，设定一个开始值
		//DP
		vector<int>cache(target + 1);
		for (int i = 1;i <= target;++i)
		{
			for (auto num : nums)
			{
				if (num > i)
				{
					break;
				}
				else if (num == i)
				{
					cache[i]++;
				}
				else
				{
					cache[i] += cache[i - num];
				}
			}
		}
		return cache[target];
	}
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int count = 0;
		for (int i : nums)
		{
			n ^= i;
			n ^= count;
			count++;
		}
		return n;
	}
	/************************************************************************/
	/* Given an array of integers, every element appears three times except for one. Find that single one.  */
	/************************************************************************/
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (auto x : nums)
		{
			ones = (ones^x)&~twos;
			twos = (twos^x)&~ones;
		}
		return ones;
	}
	/************************************************************************/
	/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST. */
	/************************************************************************/
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		//变成平衡二叉树
		return __sortedArrayToBST(nums, 0, nums.size());
	}
	/************************************************************************/
	/* buy, sell, cooldown.
		should cooldonw one day after you sell your stock
	*/
	/************************************************************************/
	int maxProfit(vector<int>& prices)
	{
		return __maxProfit(prices, 0);
	}
	int maxProfit_DP(const vector<int>& prices)
	{
		int n = prices.size();
		vector<vector<int>>cache(n + 1, vector<int>(n + 1, 0));
		for (int i=2;i<=n;++i)
		{
			for (int j=i-1;j>=1;--j)
			{
				int res = std::max(cache[j][i-1],cache[j+1][i]);
				for (int k=j+1;k<=i;++k)
				{
					if (prices[j-1] >= prices[k-1])continue;
					res = std::max(res, prices[k-1] - prices[j-1]+(k+2<i?cache[k+2][i]:0));
				}
				cache[j][i] = res;
			}
		}
		return cache[1][n];
	}
	/************************************************************************/
	/* Find Minimum in Rotated Sorted Array */
	/************************************************************************/
	int findMin(vector<int>& nums) {
		//二分法
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1])return nums[mid];
			if (nums[mid] > nums[mid + 1])return nums[mid + 1];
			if (nums[left] < nums[mid])left = mid;
			else right = mid;
		}
		return nums[0];
	}
	/************************************************************************/
	/*必然有相同的，空间复杂度为常量，并且不能够改变原有的相对位置*/
	/************************************************************************/
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];
		cout << "slow: " << slow << "    fast: " << fast << endl;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			cout << "slow: " << slow << "    fast: " << fast << endl;

		}
		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
			cout << "slow: " << slow << "    fast: " << fast << endl;
		}
		return slow;
	}
	/************************************************************************/
	/*  判断所有的小矩形拼在一起是否组成一个大的长方形  */
	/************************************************************************/
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		//找到最偏的四个点，==两个顶点
		int left = INT_MAX, bottom = INT_MAX;
		int up = 0, right = 0;
		int area = 0;
		set<pair<int, int>>cache;
		for (auto v : rectangles)
		{
			left = min(left, v[0]);
			bottom = min(bottom, v[1]);
			right = max(right, v[2]);
			up = max(up, v[3]);
			area += (v[2] - v[0])*(v[3] - v[1]);
			pair<int, int>p1(v[0], v[1]);
			pair<int, int>p2(v[0], v[3]);
			pair<int, int>p3(v[2], v[1]);
			pair<int, int>p4(v[2], v[3]);
			if (cache.find(p1) == cache.end())cache.insert(p1);
			else cache.erase(p1);
			if (cache.find(p2) == cache.end())cache.insert(p2);
			else cache.erase(p2);
			if (cache.find(p3) == cache.end())cache.insert(p3);
			else cache.erase(p3);
			if (cache.find(p4) == cache.end())cache.insert(p4);
			else cache.erase(p4);
		}
		if (cache.size() != 4 ||
			!cache.count(make_pair(left, bottom)) || !cache.count(make_pair(left, up)) ||
			!cache.count(make_pair(right, bottom)) || !cache.count(make_pair(right, up)))
			return false;
		return area == (right - left)*(up - bottom);
	}

	static bool __cmp_largestNumber(int num1, int num2)
	{
		string s1(to_string(num1));
		string s2(to_string(num2));
		string one(s1 + s2);
		return one.compare(s2 + s1) > 0;
	}

	string largestNumber(vector<int>& nums) {
		if (nums.size() < 1)return "";
		bool allZero = true;
		for (int x : nums)
		{
			if (x != 0)allZero = false;
		}
		if (allZero)return "0";
		sort(nums.begin(), nums.end(), __cmp_largestNumber);
		string res;
		for (int x : nums)
		{
			res += to_string(x);
		}
		return res;
	}

private:
	int __maxProfit(const vector<int>& prices, int begin)
	{
		int res = 0;
		if (begin >= prices.size() - 1)return res;
		if (begin == prices.size() - 2)return prices[begin + 1] > prices[begin] ? prices[begin + 1] - prices[begin] : 0;
		for (int i=begin;i<prices.size();i++)
		{
			for (int j=i+1;j<prices.size();++j)
			{
				if (prices[i] >= prices[j])continue;
				res = std::max(res, prices[j] - prices[i] + __maxProfit(prices, j + 2));
			}
		}
		return res;
	}
	TreeNode* __sortedArrayToBST(vector<int>& nums, int begin, int end)
	{
		if (begin == end)return NULL;
		if (begin + 1 == end)return  new TreeNode(nums[begin]);
		int mid = begin + (end - begin) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = __sortedArrayToBST(nums, begin, mid);
		root->right = __sortedArrayToBST(nums, mid + 1, end);
		return root;
	}
};

//int Solution_vector::deg = 0;