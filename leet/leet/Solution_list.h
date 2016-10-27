#pragma once

#include "common.h"
#include "list_node.h"

#define  ListNode list_node

class Solution_list
{
public:
	list_node* sort_list(list_node* head)
	{
		if (head == NULL || head->next == NULL)return head;
		list_node* fast = head;
		list_node* slow = head;
		while (fast->next!=NULL && fast->next->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		return mergetTwolist(sort_list(fast), sort_list(slow));
	}
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode* tmp = head->next;
		ListNode* curNext = tmp->next;

		ListNode* hhead = head;
		ListNode* ttmp = tmp;
		while (curNext)
		{
			hhead->next = curNext;
			ttmp->next = curNext->next;
			hhead = hhead->next;
			ttmp = ttmp->next;
			if (curNext->next)curNext = curNext->next->next;
			else break;
		}
		hhead->next = tmp;
		return head;
	}
private:
	list_node* mergetTwolist(list_node* l1, list_node* l2)
	{
		list_node dummy(-1);
		for (list_node* p = &dummy; l1 != nullptr || l2 != nullptr;p=p->next)
		{
			int val1 = l1 == nullptr ? INT_MAX : l1->val;
			int val2 = l2 == nullptr ? INT_MAX : l2->val;
			if (val1 <= val2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}
	bool hasCycle(list_node *head) {
		list_node* fast = head;
		list_node* slow = head;
		while(fast!=NULL&&fast->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)return true;
		}
		return false;
	}
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* cur = head->next;
		ListNode* precur=head;
		while (cur)
		{
			precur->next = cur->next;
			cur->next = dummy.next;
			dummy.next = cur;
			cur = precur->next;
		}
		return dummy.next;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int n1 = 0;
		int n2 = 0;
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		while (p1)
		{
			n1++;
			p1 = p1->next;
		}
		while (p2)
		{
			n2++;
			p2 = p2->next;
		}
		p1 = headA;
		p2 = headB;
		if (n1 > n2)
		{
			int dis = n1 - n2;
			while (dis--)
			{
				p1 = p1->next;
			}
		}
		else
		{
			int dis = n2 - n1;
			while (dis--)
			{
				p2 = p2->next;
			}
		}
		while (p1!=p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
	bool isPalindrome(ListNode* head) {
		//把后面一半反转，然后一个个比较
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next!=NULL&&fast->next->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		slow->next = reverseList(slow->next);
		slow = slow->next;
		while (slow)
		{
			if (slow->val != head->val)return false;
			slow = slow->next;
			head = head->next;
		}
		return true;

	}
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)return head;
		while (head&&head->val == val)head = head->next;
		if (head == NULL)return head;

		ListNode dummy(-1);
		dummy.next = head;
		ListNode* cur = head->next;
		ListNode* precur = head;
		while (cur)
		{
			if (cur->val==val)
			{
				precur->next = cur->next;
			}
			else
			{
				precur = cur;
			}
			cur = cur->next;
		}
		return dummy.next;
	}
	
};