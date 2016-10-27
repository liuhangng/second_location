#pragma once
#include "common.h"

class MinStack {
public:
	/** initialize your data structure here. */
	/************************************************************************/
	/* 如果是线性结构，满足不小getmin的性能                    
	   如果不是线性，满足不了pop和top
	   思路：
	   维持一个下标数组，按照最小堆排列
	*/
	/************************************************************************/
	MinStack() {

	}
	//注意溢出
	void push(int x) {
		if (data.empty())
		{
			data.push(0L);
			minnum = x;
		}
		else
		{
			data.push(x - minnum);
			if (x < minnum)minnum = x;
		}
	}

	void pop() {
		if (data.empty())return;
		int t = data.top();
		data.pop();
		if (t < 0)minnum -= t;
	}

	int top() {
		int t = data.top();
		if (t > 0)return int(t + minnum);
		else return minnum;
	}

	int getMin() {
		return minnum;
	}
private:
	stack<int>data;
	int minnum;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/