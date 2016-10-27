
#pragma once
#include "common.h"


const string base[] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };//1-9
const string second[]={"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };//10-20,30,40,90
const string third[] = { "Hundred", "Thousand", "Million", "Billion" };//100,1000,1000 000,1000 000 000

class Solution_number
{
public:
	string __numberToWords(int num)
	{
		string res;
		if (num >= 1000)
		{
			res += base[num / 1000-1] +" "+ third[1]+" ";
			num %= 1000;
		}
		if (num >= 100)
		{
			res += base[num / 100-1] +" "+ third[0]+" ";
			num %= 100;
		}
		if (num == 0)return res;
		if (num < 20)
			res += base[num - 1]+" ";
		else if (num % 10 == 0)
			res += second[num / 10 - 1]+" ";
		else
			res += second[num / 10 - 1] + " "+base[num - num / 10*10 - 1]+" ";
		return res;
	}

	string numberToWords(int num) {
		//分割成四块，每块，调用一样的方法
		if (num == 0)return "Zero";
		vector<int>nums(4, 0);
		int b = 0;
		while (num)
		{
			nums[b++] = num % 1000;
			num /= 1000;
		}
		string res;
		while (b--)
		{
			if (nums[b] != 0)res += __numberToWords(nums[b])+(b==0?"":third[b]+" ");
		}
		if (res[res.size() - 1] == ' ')
			res.pop_back();
		return res;
	}
	bool isMinPer(long long input, long long change)
	{
		//先比较两个是不是有一样的数字组成
		//然后change这个数组里面的每一位是不是都比当前剩余的要小，除了第一位特殊比较
		int numschar1[10] = { 0 };
		int numschar2[10] = { 0 };
		while (input)
		{
			numschar1[input % 10]++;
			input /= 10;
		}
		long long tmp = change;
		while (tmp)
		{
			numschar2[tmp % 10]++;
			tmp /= 10;
		}
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			if (numschar1[i] != numschar2[i])return false;
			count += numschar1[i];
		}
		vector<int>save(count, 0);
		for (int i = 0; i < count; i++)
		{
			save[count - 1 - i] = change % 10;
			change /= 10;
		}
		//第一位
		for (int i = 1; i < count; i++)
		{
			if (save[i] == 0)continue;
			if (save[i] < save[0])return false;
		}
		//从第二位开始
		for (int i = 1; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (save[j] < save[i])return false;
			}
		}
		return true;
	}

	int slove_maza(long long x)
	{
		long long tmp = 2 * x;
		long long n1 = sqrt(tmp);
		long long res = 0;
		while (true)
		{
			long long mul = n1*(n1 + 1) / 2;
			if (mul == x)
			{
				vector<int>cache(n1, 0);
				int fir = 1;
				iota(cache.begin(), cache.end(), fir);
				PRINTVECTOR(cache);
				cout << "sum: " << accumulate(cache.begin(), cache.end(), 0) << endl;
				return n1;
			}
			else if (mul > x)
			{
				res = n1;
				while ((res*(res + 1) / 2 - x) & 0x01)
				{
					res++;
				}
				vector<int>cache(res, 0);
				for (int i = 0; i < res; i++)
				{
					cache[i] = i + 1;
				}
				int index = (res*(res + 1) / 2 - x) / 2;
				cache[index - 1] = -1 * index;
				PRINTVECTOR(cache);
				cout << "sum: " << accumulate(cache.begin(), cache.end(), 0) << endl;
				return res;
			}
			n1++;
		}
		return res;
	}
	bool isUgly(int num) {
		if (num<1)
		{
			return false;
		}
		if (1 == num)return true;
		while (!(num&0x01))
		{
			num >>= 1;
		}
		while (num % 3 == 0)num /= 3;
		while (num % 5 == 0)num /= 5;
		return num == 1;
	}
	/************************************************************************/
	/* 二进制手表 有多少个bit,上4下6                                        */
	/************************************************************************/
	vector<string> readBinaryWatch(int num) {
		vector<string>res;
		for (int h=0;h<12;h++)
		{
			for (int m=0;m<60;m++)
			{
				if (bitset<10>(h << 6 | m).count() == num)
					res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
			}
		}
		return res;
	}
	/************************************************************************/
	/* 从一个数组中，随机选出N个值，组成的向量                              */
	/************************************************************************/
	vector<vector<int>> indexbuildN(const vector<int>&source, int num)
	{
		int n = source.size();
		vector<vector<int>>res;
		vector<bool>used(n, false);
		if (num == 0)return res;
		if (num == n)
		{
			res.push_back(source);
			return res;
		}
		vector<int>tmp;
		for (int i=0;i<n-num+1;i++)
		{
			tmp.push_back(source[i]);
			//used[i]
			__indexbuildN(source, res,tmp,num, i + 1);
			tmp.pop_back();
		}
		return res;
	}
	void __indexbuildN(const vector<int>&source, vector<vector<int>>&res, vector<int>&tmp, const int num, int begin)
	{
		if (tmp.size() == num)
		{
			res.push_back(tmp);
			return;
		}
		else
		{
			for (int i=begin;i<source.size()-num+1;i++)
			{
				tmp.push_back(source[i]);
				__indexbuildN(source, res, tmp, num, i + 1);
				tmp.pop_back();
			}
		}
	}
	bool isPowerOfTwo(int n) {
		if (n <= 0)return false;
		int l = sizeof(int) * 8;
		int base = 1;
		for (int i=1;i<0;i++)
		{
			if (!(n&(~(base << i))))return true;
		}
		return false;
	}
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			count++;
			n = n & (n - 1);
		}
		return count;
	}
	bool isPowerOfThree(int n) {
		if (n <= 0)return false;
		while (n % 3 == 0)
		{
			n /= 3;
		}
		return n == 1;
	}
	bool com(int n1, int n2)
	{
		stringstream s1, s2;
		s1 << n1;
		s2 << n2;
		string ss1, ss2;
		s1 >> ss1;
		s2 >> ss2;
		return strcmp(ss1.c_str(),ss2.c_str());
	}
	int trailingZeroes(int n) {
		return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
	}
	string getDictionSort(long long n, long long m)
	{
		vector<string>nums;
		stringstream ss;
		for (int i=0;i<n;i++)
		{
			ss.clear();
			ss << i+1;
			string s;
			ss >> s;
			nums.push_back(s);
		}
		nth_element(nums.begin(), nums.begin() + m, nums.end());
		return nums[m-1];
	}
	long long  findNthDigit(long long n) {
		long long  base = 9;
		long long  nb = 1;
		long long  sumnum = base;
		long long  presum = 0;
		while (n>sumnum)
		{
			nb++;
			base *= 10;
			presum = sumnum;
			sumnum += base*nb;
		}
		//定位到第几个数字
		long long  index = (n - presum-1) / nb;
		long long  num = std::pow(10, nb-1) + index ;
		//这个数字的第几个位
		long long  bb = n - presum - nb*index;
		long long  loop = nb - bb;
		while (loop--)
		{
			num /= 10;
		}
		return num % 10;
	}
	uint32_t reverseBits(uint32_t n) {
		bitset<32>data(n);
		for (int i=0;i<16;i++)
		{
		    int tmp1 = data[i];
			int tmp2 = data[31 - i];
			//data[i] = data[31 - i];
			//data[31 - i] = tmp;
			data.set(i, tmp2);
			data.set(31 - i, tmp1);
		}
		return data.to_ulong();
	}
	int integerReplacement(unsigned long long n) {
		/************************************************************************
		错误原因分析：
		111011：按照原来的方法，会先消灭后面的11用-1>>1的方法，但是如果先加1效果会好很多
		************************************************************************/
		int count = 0;
		while (n > 1)
		{
			if (!(n & 0x01))n >>= 1;
			else
			{
				if (
					((n >> 1) & 0x01)
					&& 
					(   (n >> 2) & 0x01 || (n >> 3) & 0x01    )
					)
					n = n + 1;
				else
					n -= 1;
			}
			count++;
		}
		return count;
	}
	vector<int> countBits(unsigned long long num) {
		vector<int>res(num + 1);
		res[0] = 0;
		unsigned long long base = 1;
		while (base <= num)
		{
			unsigned long long maxnum = (base << 1) > num ? num+1 : base << 1;
			for (int i=base;i<maxnum;++i)
			{
				res[i] = res[i - base] + 1;
			}
			base <<= 1;
		}
		return res;
	}
	/************************************************************************/
	/* 整数分解为多个数之和，求这些数的最大乘积                   */
	/************************************************************************/
	int integerBreak(int n) {
		//分解为2个数，3个数，n/2个几乎相等数，求其中的最大乘积
		int prodMax = 0;
		for (int i=2;i<=n/2;++i)
		{
			int  p1 = pow(n / i, i - 1)*(n - n / i*(i - 1));
			int p2 = pow(i, n / i)*((n - n / i*i)==0?1: (n - n / i*i));
			prodMax=max(prodMax,max(p1,p2));//二者的结合
		}
		return prodMax;
	}
	int countNumbersWithUniqueDigits(int n) {
		//超过10没有意义
		n = min(n, 10);
		int res = 10;
		if (n == 0)return 1;
		if (n == 1)return res;

		int cur = 9;
		for (int i=n;i<=n;i++)
		{
			cur *= (11 - i);
			res += cur;
		}
		return res;
	}
	int bulbSwitch(int n) {
		//初始全部为0，toggle操作
		//因式分解，
		/*int res = 1;
		if (n == 1)return res;
		for (int i=2;i<=n;i++)
		{
			int num = 2;
			for (int j=2;j<=i/2;++j)
			{
				if (i%j == 0)num++;
			}
			if (num & 0x01)res++;
		}
		return res;*/
		return sqrt(n);
	}
	/************************************************************************/
	/*  1到9，k个组成和为n的所有可能情况  */
	/************************************************************************/
	vector<vector<int>> combinationSum3(int k, int n) {
		int base = 1;
		vector<int>nums(9, 0);
		iota(nums.begin(), nums.end(), base);
		vector<int>used(9, false);
		vector<vector<int>>res;
		if (n > 45)return res;

		vector<int>tmp;
		__combinationSum3(res, nums,tmp, k, n,0);
		return res;
	}
	void __combinationSum3(vector<vector<int>>&res,const vector<int>&nums , vector<int>&tmp, int k, int n,int begin)
	{
		if (n == 0 && k == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (int i=begin;i<nums.size();++i)
		{
			tmp.push_back(nums[i]);
			__combinationSum3(res, nums, tmp, k-1, n-nums[i], i + 1);
			tmp.pop_back();
		}
	}
private:
};