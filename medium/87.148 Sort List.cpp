/*
Sort a linked list in O(n log n) time using constant space complexity.
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

	ListNode* sortList(ListNode* head) 
	{
		if(head == NULL || head->next == NULL)
			return head;
		else if(head->next->next == NULL)
		{
			ListNode* p1 = head;
			ListNode* p2 = head->next;
			if(p1->val <= p2->val)
				return head;
			else
			{
				p2->next = p1;
				p1->next = NULL;
				return p2;
			}
		}
		else
		{
			ListNode* slow = head;
			ListNode* fast = head->next->next;	
			while(slow != NULL && fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
				if(fast != NULL)
					fast = fast->next;
			}
			ListNode* h2 = slow->next;
			slow->next = NULL;
			ListNode* h1 = sortList(head);
			h2 = sortList(h2);
			ListNode* p1 = h1;
			ListNode* p2 = h2;
			ListNode* h = NULL;
			ListNode* t = NULL;
			while(p1 != NULL && p2 != NULL)
			{
				if(p1->val <= p2->val)
				{
					if(h == NULL)
					{
						h = p1;
						t = p1;
					}
					else
					{
						t->next = p1;
						t = p1;
					}
					p1 = p1->next;
				}
				else
				{
					if(h == NULL)
          {
            h = p2;
            t = p2;
          }
          else
          {
            t->next = p2;
            t = p2;
          }
					p2 = p2->next;
				}
			}			
			while(p1 != NULL)
			{
				if(h == NULL)
				{
					h = p1;
					t = p1;
				}
				else
				{
					t->next = p1;
					t = p1;
				}
				p1 = p1->next;
			}	
			while(p2 != NULL)
			{
				if(h == NULL)
        {
          h = p2;
          t = p2;
        }
        else
        {
          t->next = p2;
          t = p2;
        }
        p2 = p2->next;
			}	
			t->next = NULL;			
			return h;
		}
	}


};

/*
  一开始用快速排序超时了，改用归并排序通过。
*/
