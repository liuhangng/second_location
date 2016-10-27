#pragma once
#include "common.h"

using namespace std;

class Solution_string
{
public:
	string reverseVowels(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j)
		{
			while (i < j && !isVowel(s[i]))i++;
			while (i < j && !isVowel(s[j]))j--;
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
	string string_add(string s1, string s2)
	{
		int n = s1.size();
		int m = s2.size();
		if (n < m)return string_add(s2, s1);
		int dis = n - m;
		int next = 0;
		int sum = 0;
		for (int i = n - 1;i >= 0;i--)
		{
			sum = s1[i] - '0' + next + (i >= dis ? s2[i - dis] - '0' : 0);
			s1[i] = '0' + sum % 10;
			next = sum / 10;
		}
		if (next > 0)
			s1.insert(s1.begin(), next + '0');
		return s1;
	}
	string string_mul(string s1, string s2)
	{
		int n = s1.size();
		int m = s2.size();
		vector<int>res(n + m, 0);
		int sum = 0;
		int next = 0;
		for (int i = n - 1;i >= 0;i--)
		{
			for (int j = m - 1;j >= 0;j--)
			{
				sum = res[i + j + 1] + (s1[i] - '0')*(s2[j] - '0');
				res[i + j] += sum / 10;
				res[i + j + 1] = sum % 10;
			}
		}
		string result;
		for (int i = 0;i < n + m;i++)
		{
			if (i == 0 && res[i] == 0)continue;
			result.push_back('0' + res[i]);
		}
		return result;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, multiset<string>>cache;
		for (auto s : strs)
		{
			string t = s;
			sort(t.begin(), t.end());
			cache[t].insert(s);
		}
		vector<vector<string>>res;
		for (auto m : cache)
		{
			res.push_back(vector<string>(m.second.begin(), m.second.end()));
		}
		return res;
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		return res;
	}
	vector<string> mystrtok(string s, string seg)
	{
		vector<string>res;
		const char* p = seg.c_str();
		char *buf[128];
		//const char* psource = s.c_str());
		char* psource = strtok_s(const_cast<char*>(s.c_str()), p, buf);
		while (psource)
		{
			res.push_back(psource);
			psource = strtok_s(NULL, p, buf);
		}
		return res;
	}
	bool canConstruct(string ransomNote, string magazine) {
		//
		//if (magazine == ransomNote)return true;
		if (ransomNote == "")return true;
		sort(ransomNote.begin(), ransomNote.end());
		sort(magazine.begin(), magazine.end());
		//一一对应映射
		int f_ran = 0;
		int f_mag = 0;
		for (;f_mag < magazine.size();f_mag++)
		{
			if (magazine[f_mag] < ransomNote[f_ran])continue;
			else if (magazine[f_mag] == ransomNote[f_ran])
			{
				f_ran++;
				if (f_ran == ransomNote.size())return true;
			}
			else return false;
		}
		return false;
	}
	string toHex(int num) {
		unsigned int x = num;
		if (x == 0)return "0";
		const char base[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		string res;
		while (x)
		{
			res.push_back(base[x % 16]);
			x >>= 4;
		}
		reverse(res.begin(), res.end());
		return res;
	}
	bool isAnagram(string s, string t) {
		int n1 = s.size();
		int n2 = t.size();
		if (n1 != n2)return false;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for (int i = 0; i < n1;i++)
		{
			if (s[i] != t[i])return false;
		}
		return true;
	}
	int firstUniqChar(string s) {
		int n = s.size();
		vector<bool>used(n, false);//前面已经出现过了
		bool flag = true;
		for (int i = 0;i < n;i++)
		{
			if (used[i])continue;
			flag = true;
			int j = i + 1;
			for (;j < n;j++)
			{
				if (s[i] == s[j])
				{
					used[j] = true;
					flag = false;
				}
			}
			if (flag)return i;
		}
		return -1;
	}
	int countshiftsum(string s)
	{
		int sum = 1;
		bool flag = true;
		int n = s.size();
		for (int j = 1;j < n;j++)
		{
			flag = true;
			for (int i = 0;i < j;i++)
			{
				if (s[i] != s[n - j + i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int i = 0;i < n - j;i++)
				{
					if (s[i] != s[j + i])
					{
						flag = false;
						break;
					}
				}
			}
			if (flag)
				sum++;
		}
		return sum;
	}
	int countshiftsum2(string s)
	{
		int sum = 1;
		int n = s.size();
		if (n <= 1)return sum;
		for (int j = 1;j < n;j++)
		{
			if (s[j] == s[0])
			{
				for (int k = j + 1;k < n;k++)
				{
					if (s[k] != s[k - j])break;
				}
				for (int k = 0;k < j;k++)
				{
					if (s[k] != s[n - j + k])break;
				}
				sum++;
			}
		}
		return sum;
	}
	int countshiftsum3(string s)
	{
		int sum = 1;
		int n = s.size();
		if (n <= 1)return sum;
		bool flag = true;
		for (int i = 1;i < n;i++) //分片长
		{
			if (n%i != 0)continue;
			flag = true;

			for (int j = 1;j < n / i;j++)//分了多少片
			{
				for (int k = 0;k < i;k++)
				{
					if (s[k] != s[j*i + k])
					{
						flag = false;
						break;
					}
				}
				if (flag == false)break;
			}
			if (flag)return n / i;
		}
		return sum;
	}
	string getHint(string secret, string guess) {
		int bulls = 0;
		int cows = 0;
		int n = secret.size();
		vector<bool>used(n, false);
		for (int i = 0;i < n;i++)
		{
			if (secret[i] == guess[i])
			{
				used[i] = true;
				bulls++;
			}
		}
		int lev = n - bulls;
		string tmp1(lev, ' ');
		string tmp2(lev, ' ');
		int index = 0;
		for (int i = 0;i < n;i++)
		{
			if (!used[i])
			{
				tmp1[index] = secret[i];
				tmp2[index++] = guess[i];
			}
		}
		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());
		for (int i = 0, j = 0;i < lev&&j < lev;)
		{
			if (tmp1[i] == tmp2[j])
			{
				i++;
				j++;
				cows++;
			}
			else if (tmp1[i] > tmp2[j]) j++;
			else i++;
		}
		return to_string(bulls) + 'A' + to_string(cows) + 'B';
	}
	string getHint2(string secret, string guess)
	{
		//巧妙利用只有0-9这是个数字
		int bulls = 0;
		int cows = 0;
		vector<int>scount(10, 0);
		vector<int>gcount(10, 0);
		if (secret.size() != guess.size() || secret.empty())return "0A0B";
		for (int i = 0;i < secret.size();i++)
		{
			if (secret[i] == guess[i])
			{
				bulls++;
			}
			else
			{
				scount[secret[i] - '0']++;
				gcount[guess[i] - '0']++;
			}
		}
		for (int i = 0;i < 10;i++)
		{
			cows += std::min(scount[i], gcount[i]);
		}
		return to_string(bulls) + 'A' + to_string(cows) + 'B';
	}
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())return false;
		int n = s.size();
		vector<bool>uesd(n, false);
		for (int i = 0;i < n;i++)
		{
			if (uesd[i])continue;
			for (int j = i + 1;j < n;j++)
			{
				if (uesd[j])continue;
				if (s[j] == s[i])
				{
					if (t[j] != t[i])return false;
					uesd[j] = true;
				}
				else
				{
					if (t[j] == t[i])return false;
				}
			}
		}
		return true;
	}
	bool isIsomorphic2(string s, string t) {
		if (s.size() != t.size())return false;
		int n = s.size();
		int m1[256] = { 0 };
		int m2[256] = { 0 };
		for (int i = 0;i < n;++i)
		{
			if (m1[s[i]] != m2[t[i]])return false;
			m1[s[i]] = i + 1;
			m2[t[i]] = i + 1;
		}
		return true;
	}
	bool wordPattern(string pattern, string str) {
		vector<string>allstr = mystrtok(str, " ");
		int n = pattern.size();
		if (n != allstr.size())return false;
		vector<bool>used(n, false);
		for (int i = 0;i < n;i++)
		{
			if (used[i] == true)continue;
			for (int j = i + 1;j < n;j++)
			{
				if (pattern[j] == pattern[i])
				{
					if (!stringequal(allstr[j], allstr[i]))return false;
					used[j] = true;
				}
				else
				{
					if (stringequal(allstr[j], allstr[i]))return false;
				}
			}
		}
		return true;
	}
	int compareVersion(string version1, string version2) {
			//假设了一样长

	}
	bool isSubsequence(string s, string t) {
		int n1 = s.size();
		int n2 = t.size();
		//vector<int>cache(n2, 0);
		//if (s[0] == t[0])cache[0] = 1;
		int index = 0;
		for (int i=0;i<n2;++i)
		{
			if (index == n1)return true;
			if (t[i] == s[index])++index;
		}
		return index == n1;
	}
	int maxProduct(vector<string>& words) {
		if (words.size() < 2)return 0;
		unordered_map<int, int>maxlen;
		for (int i=0;i<words.size();++i)
		{
			int mask = 0;
			for (auto c:words[i])
			{
				mask |= 1 >> (c - 'a');
			}
			maxlen[mask] = std::max(maxlen[mask], (int)words.size());
		}
		int maxprod = 0;
		for (auto a:maxlen)
		{
			for (auto b:maxlen)
			{
				if (!a.first&b.first)
					maxprod = std::max(maxprod, a.second*b.second);
			}
		}
		return maxprod;


	}
	bool isContainSamceWord(string s1, string s2)
	{
		//排好序
		for (int i=0,j=0;i<s1.size()&&j<s2.size();)
		{
			while (i < s1.size() - 1 && s1[i] == s1[i + 1])i++;
			while (j < s2.size() - 1 && s2[j] == s2[j + 1])j++;
			if (s1[i] == s2[j])return true;
		}
		return false;
	}
	/************************************************************************/
	/* 对一个表达式添加括号，计算各种可能的和                           */
	/************************************************************************/
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>>domap;
		return diffWaysToCompute(domap, input);
	}
	vector<int> diffWaysToCompute(unordered_map<string, vector<int>>&domap, string input) {
		vector<int>result;
		for (int i=0;i<input.size();++i)
		{
			char c = input[i];
			if (c == '+' || c == '-' || c == '*')
			{
				vector<int>res1, res2;
				string substr = input.substr(0, i);
				if (domap.find(substr) != domap.end())
				{
					res1 = domap[substr];
				}
				else
				{
					res1 = diffWaysToCompute(domap, substr);
				}
				substr = input.substr(i + 1);
				if (domap.find(substr) != domap.end())
				{
					res2 = domap[substr];
				}
				else
				{
					res2 = diffWaysToCompute(domap, substr);
				}
				for (auto x:res1)
				{
					for ( auto y:res2)
					{
						switch (c)
						{
						case '*':
							result.push_back(x*y);break;
						case  '-':
							result.push_back(x - y);break;
						case '+':
							result.push_back(x + y);break;
						default:
							break;
						}
					}
				}
			}
		}
		if (result.empty())
		{
			result.push_back(atoi(input.c_str()));
		}
		return result;
	}
	
	/************************************************************************/
	/* 所有的产生括号的情况                                            */
	/************************************************************************/
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.push_back(str);
			return;
		}

		if (m > 0) { addingpar(v, str + ")", n, m - 1); }
		if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }

	}
	/************************************************************************/
	/* Given an encoded string, return it's decoded string.
		The encoding rule is: k[encoded_string],*/
	/************************************************************************/
	string decodeString(string s) {
		stack<char>charsave;
		for (auto c:s)
		{
			if (isalnum(c)||c=='[')
			{
				charsave.push(c);
			}
			else
			{
				vector<char>tmp;
				do 
				{
					char t = charsave.top();
					charsave.pop();
					if (isalpha(t))
						tmp.push_back(t);
					else
						break; //碰到了 '['
				} while (true);
				//获取数字
				int res = 0;
				int base = 1;
				char t = charsave.top();
				charsave.pop();
				while (true)
				{
					res += (t - '0')*base;
					base *= 10;
					if (charsave.empty())break;
					t = charsave.top();
					charsave.pop();
					if (!isdigit(t))
					{
						charsave.push(t);
						break;
					}
				}
				//放入res个tmp
				for (int i=0;i<res;++i)
				{
					for (int j=tmp.size()-1;j>=0;j--)
					{
						charsave.push(tmp[j]);
					}
				}
			}
		}
		//charsave转为string
		string result;
		while (!charsave.empty())
		{
			result.insert(result.begin(), charsave.top());
			charsave.pop();
		}
		return result;
	}
	string decodeString_recursive(string s)
	{
		int i = 0;
		return decodeString_recursive(s, i);
	}
	int KMP_find(string s, string pattren,int begin=0)
	{
		vector<int>next = KMP_next(pattren);
		int i = begin;
		int j = 0;
		while (i < s.size()&&j<pattren.size())
		{
			while (j>=0&&pattren[j]!=s[i])
			{
				j = next[j];
			}
			i++,j++;
		}
		if (j >= pattren.size())
			return i - begin;
		return -1;
	}
	vector<int> KMP_next(string match)
	{
		vector<int>next(match.size());
		next[0] = -1;
		int j = 0, k = -1;
		while (j<match.size() - 1)
		{
			while (k >= 0 && match[k] != match[j])
			{
				k = next[k];
			}
			k++, j++;
			if (match[j] != match[k])
			next[j] = k;
				else
			{

			next[j] = next[k];
			}
		}
		return next;
	}
	void reverseWords(string &s) {
		tackleSpace(s);
		reverse(s.begin(), s.end());
		int index = 0;
		for (int i = 0;i < s.size();++i)
		{
			if (s[i] = ' ')
			{
				reverse(s.begin() + index, s.begin() + i);
				index = i + 1;
			}
		}
		reverse(s.begin() + index, s.end());
		
		//cout << s << endl;
	}


	void tackleSpace(string& s)
	{
		for (int i=0;i<s.size();++i)
		{
			
			while (
				  (std::cout << "here" << s[i] << "here" << std::endl,    s[i]) ==' '
				&&
				((std::cout<<"there"<<s[i+1]<<"there"<<std::endl,s[i+1]) ==' '||i==s.size()-1||i==0))
			{
				s.erase(i, 1);
			}
		}
	}

	/************************************************************************/
	/* change a string to be a strong password at least steps*/
	//三个约束调价：6<=size<=20
	//至少一个小写，一个大写，一个数字
	//不能出现三个连续的字符
	/************************************************************************/
	int strongPasswordChecker(string s) {
		return 0;
	}


	/************************************************************************/
	/* 在前面插入字符，使之成为最短的回文字符串           */
	/************************************************************************/
	bool __isPralindrom(string s, int left, int right)
	{
		while (left<right)
		{
			if (s[left] != s[right])return false;
			left++;
			right--;
		}
	}

	string shortestPalindrome(string s) {
		for (int i=s.size()-1;i>=0;--i)
		{
			if (__isPralindrom(s, 0, i))
			{
				string tmp(s.substr(i + 1));
				reverse(tmp.begin(), tmp.end());
				return tmp + s;
			}
		}
	}


private:
	/************************************************************************/
	/* 巧妙之处在于while的截止条件和i的使用   */
	/************************************************************************/
	string decodeString_recursive(string s, int& i)
	{
		string res;
		while (i<s.size()&&s[i]!=']')
		{
			if (!isdigit(s[i]))
				res += s[i++];
			else
			{
				int n = 0;
				while (i<s.length()&&isdigit(s[i])) //循环到这里的时候，数字n和后面的整个[]的全部解决
				{
					n = n * 10 + s[i++] - '0';
				}
				i++;
				string t = decodeString_recursive(s, i);
				i++;
				while (n-->0)
				{
					res += t;
				}
			}
		}
		return res;
	}
	int __getNextNumber(string version, int& index)
	{
		if (index >= version.size())return 0;
		int res = 0;
		int i = index;
		for (;i<version.size();++i)
		{
			if(version[i]!='.')
			res = res * 10 + version[i] - '0';
		}
	}
	bool stringequal(string s1, string s2)
	{
		if (s1.size() != s2.size())return false;
		for (int i=0;i<s1.size();i++)
		{
			if (s1[i] != s2[i])return false;
		}
		return true;
	}
	/************************************************************************/
	/* 分割函数                                                             */
	/************************************************************************/
	vector<string>mysplit(string str)
	{
		vector<string>res;
		int i = 0;
		int index = 0;
		for (;i<str.size();i++)
		{
			if (str[i] == ' ')
			{
				res.push_back(str.substr(index, i - index));
				index = i + 1;
			}
		}
		res.push_back(str.substr(index));
		return res;
	}
	
	bool isVowel(char c)
	{//a e o u 
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'o' || c == 'u'||c=='i';
	}
};