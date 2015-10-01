/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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

   	ListNode* removeElements(ListNode* head, int val) 
	{
		if(head == NULL)
			return NULL;

		ListNode* p = head;
		ListNode* pre = NULL;
		while(p != NULL)
		{
			if(p->val == val)
			{
				if(pre != NULL)
				{
					pre->next = p->next;
                        		p = p->next;
				}
				else
				{
					head = p->next;
					p = p->next;
				}
			}
			else
			{
				pre = p;
				p = p->next;
			}
		}		
		return head;
    	}

};

/*
  模拟
*/
