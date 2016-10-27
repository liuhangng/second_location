#pragma once
#include <stack>

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		datain.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (dataout.empty())
		{
			while (!datain.empty())
			{
				dataout.push(datain.top());
				datain.pop();
			}
		}
		dataout.pop();
	}

	// Get the front element.
	int peek(void) {
		if (dataout.empty())
		{
			while (!datain.empty())
			{
				dataout.push(datain.top());
				datain.pop();
			}
		}
		return dataout.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (datain.empty() && dataout.empty());
	}
private:
	std::stack<int>datain;
	std::stack<int>dataout;
};