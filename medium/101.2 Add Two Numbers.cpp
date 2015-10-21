/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <vector>

using namespace std;

class Solution 
{
	public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* head = NULL;
		ListNode* tail = NULL;
		ListNode* p = l1;
		ListNode* q = l2;
		int carry = 0;
		while(p != NULL && q != NULL)
		{
			ListNode* new_v = (ListNode*)malloc(sizeof(ListNode));
			new_v->next = NULL;
			if(p->val + q->val + carry >= 10)
			{
				new_v->val = p->val + q->val + carry -10;
				carry = 1;
			}	
			else
			{
				new_v->val = p->val + q->val + carry;
                                carry = 0;
			}
			if(head == NULL)
			{
				head = new_v;
				tail = new_v;
			}
			else
			{
				tail->next = new_v;
				tail = new_v;
			}
			p = p->next;
			q = q->next;	
		}
		while(p != NULL)
		{
			ListNode* new_v = (ListNode*)malloc(sizeof(ListNode));
      new_v->next = NULL;
      if(p->val + carry >= 10)
      {
              new_v->val = p->val + carry -10;
              carry = 1;
      }
      else
      {
              new_v->val = p->val + carry;
              carry = 0;
      }
      if(head == NULL)
      {
              head = new_v;
              tail = new_v;
      }
      else
      {
              tail->next = new_v;
              tail = new_v;
      }
      p = p->next;
		}
		while(q != NULL)
		{
			ListNode* new_v = (ListNode*)malloc(sizeof(ListNode));
      new_v->next = NULL;
      if(q->val + carry >= 10)
      {
              new_v->val = q->val + carry -10;
              carry = 1;
      }
      else
      {
              new_v->val = q->val + carry;
              carry = 0;
      }
      if(head == NULL)
      {
              head = new_v;
              tail = new_v;
      }
      else
      {
              tail->next = new_v;
				      tail = new_v;
      }
      q = q->next;
		}
		if(carry == 1)
		{
			ListNode* new_v = (ListNode*)malloc(sizeof(ListNode));
      new_v->next = NULL;
			new_v->val = 1;
			if(head == NULL)
      {
              head = new_v;
              tail = new_v;
      }
      else
      {
              tail->next = new_v;
				      tail = new_v;
      }	
		
		}
		return head;
	}

};
