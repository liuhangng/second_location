#pragma  once

#include<iostream>

struct list_node
{
	int val;
	list_node* next;
	list_node(int x) :val(x), next(NULL) {}
}; 
