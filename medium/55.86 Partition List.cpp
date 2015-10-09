/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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

	ListNode* partition(ListNode* head, int x) 
	{
		ListNode* h1 = NULL;
		ListNode* h2 = NULL;
		ListNode* t1 = NULL;
		ListNode* t2 = NULL;
		ListNode* p = head;
		while(p != NULL)
		{
			if(p->val < x)
			{
				if(h1 == NULL)
				{
					h1 = p;
					t1 = p;
				}
				else
				{
					t1->next = p;
					t1 = p;
				}
			}
			else
			{
				if(h2 == NULL)
				{
					h2 = p;
					t2 = p;
				}	
				else
				{
					t2->next = p;
					t2 = p;
				}
			}
			p = p->next;
		}	
		if(h1 != NULL && h2 != NULL)
		{
			t1->next = h2;
			t2->next = NULL;
			return h1;
		}
		else if(h1 == NULL && h2 != NULL)
		{
			t2->next = NULL;
			return h2;
		}
		else if(h1 != NULL && h2 == NULL)
		{
			t1->next = NULL;
			return h1;
		}
		else
			return NULL;
	}

};

/*
  模拟
*/
