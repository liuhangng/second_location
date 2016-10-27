#pragma once
#include "common.h"

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		data.push(x);
		for (int i=0;i<data.size()-1;++i)
		{
			data.push(data.front());
			data.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		data.pop();
	}

	// Get the top element.
	int top() {
		return data.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return data.empty();
	}
private:
	queue<int>data;

};