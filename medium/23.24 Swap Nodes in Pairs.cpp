/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution 
{

	public:

    	ListNode* swapPairs(ListNode* head) 
	{
        	ListNode* prev = NULL;
		ListNode* p = head;
		ListNode* new_head = NULL;
		while(p != NULL && p->next != NULL)
		{
			ListNode* f1 = p;
			ListNode* f2 = p->next;
			ListNode* f3 = p->next->next;
			if(prev != NULL)
				prev->next = f2;
			if(new_head == NULL)
				new_head = f2;
			f2->next = f1;
			f1->next = f3;
			prev = f1;
			p = f3;
		}		
		if(new_head == NULL && head != NULL)
			new_head = head;
		return new_head;	
    	}

};

/*
  模拟
*/
