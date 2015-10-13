/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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

	ListNode* deleteDuplicates(ListNode* head) 
	{
		if(head == NULL)
			return NULL;
		ListNode* prev = NULL;
		ListNode* p = head;
		ListNode* h = head;
		while(p != NULL)
		{
			int x = p->val;
			int count = 1;
			ListNode* q = p->next;
			while(q != NULL && q->val == x)
			{
				q = q->next;
				count++;
			}
			if(count > 1)
			{
				if(prev == NULL)
				{
					h = q;
					p = q;
				}	
				else
				{
					prev->next = q;
					p = q;
				}
			}		
			else
			{
				prev = p;
				p = q;	
			}	
		}	
		return h;	
	}

};

/*
  模拟
*/
