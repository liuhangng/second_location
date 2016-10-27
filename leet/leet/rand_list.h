#pragma once
#include "list_node.h"
#define  ListNode list_node
class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) :__head(head), num(0) {
		while(head != NULL)
		{
			num++;
			head = head->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		int ran = rand() % num;
		ListNode* tmp=__head;
		while (ran--)tmp = tmp->next;
		return tmp->val;
	}
private:
	int num;
	ListNode* __head;
};