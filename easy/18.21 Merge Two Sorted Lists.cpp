/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* head = NULL;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* tail = NULL;
		while(p1 != NULL && p2 != NULL)
		{
			if(p1->val <= p2->val)
			{
				if(head == NULL)	
				{
					head = p1;
					tail = p1;
					p1 = p1->next;
				}
				else
				{
					tail->next = p1;
					tail = p1;
					p1 = p1->next;		
				}	
			}
			else 
			{
				if(head == NULL)
				{
					head = p2;
                                        tail = p2;
					p2 = p2->next;
				}
				else
				{
					tail->next = p2;
                                        tail = p2;
                                        p2 = p2->next;
				}
			}		
										
		}		
		if(p1 != NULL && p2 == NULL)
		{
			if(head == NULL)
				head = p1;
			else
				tail->next = p1;
		}
		else if(p1 == NULL && p2 != NULL)
		{
			if(head == NULL)
				head = p2;
			else
				tail->next = p2;
		}
		else
		{
			if(head != NULL)
				tail->next = NULL;
		}

		return head;	
    	}

};

/*
  模拟
*/
