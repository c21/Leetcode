/*
Sort a linked list using insertion sort.
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

	ListNode* insertionSortList(ListNode* head) 
	{
		ListNode* h = NULL;
		ListNode* t = NULL;
		ListNode* p = head;
		while(p != NULL)
		{
			ListNode* next = p->next;
			if(h == NULL)
			{
				h = p;
				t = p;
				t->next = NULL;
			}
			else
			{
				ListNode* q = h;
				ListNode* prev = NULL; 
				int flag = 0;
				while(q != NULL)
				{
					if(p->val >= q->val)
					{
						prev = q;
						q = q->next;
					}
					else
					{
						flag = 1;
						if(prev != NULL)		
						{
							prev->next = p;
							p->next = q;
							break;	
						}
						else
						{
							h = p;
							p->next = q;
							break;
						}
					}			
				}
				if(flag == 0)
				{
					t->next = p;
					t = p;
					t->next = NULL;
				}	
			}
			p = next;
		}	
		return h;		
	}

};

/*
  模拟
*/
