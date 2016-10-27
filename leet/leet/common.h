#pragma once

#include <string>
#include <iostream>
#include <map>
#include <mutex>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stack>
#include <iterator>
#include <list>
#include <sstream>
#include<cstring>
#include<cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include<queue>
#include <bitset>
//#include <pair>
//#include "tree_node.h"

using namespace std;

void PRINTVECTOR(const vector<int>&vec)
{
	for_each(vec.begin(), vec.end(), [] (int x) { cout << x << " "; });
	cout << endl;
}


void PRINTVECTORVECTOR(const vector<vector<int>>&vvec)
{
	for (int i = 0; i < vvec.size();i++)
	{
		for_each(vvec[i].begin(), vvec[i].end(), [](int x){ cout << x << " "; });
		cout << endl;
	}
}

void PRINTSTRING(const vector<string>& vs)
{
	for (int i=0;i<vs.size();i++)
	{
		cout << vs[i] << endl;
	}
}


/************************************************************************/
/* 获取一个int型变量的十进值长度                                        */
/************************************************************************/
int getDexLenghth(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}


