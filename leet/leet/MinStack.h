#pragma once
#include "common.h"

class MinStack {
public:
	/** initialize your data structure here. */
	/************************************************************************/
	/* ��������Խṹ�����㲻Сgetmin������                    
	   ����������ԣ����㲻��pop��top
	   ˼·��
	   ά��һ���±����飬������С������
	*/
	/************************************************************************/
	MinStack() {

	}
	//ע�����
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