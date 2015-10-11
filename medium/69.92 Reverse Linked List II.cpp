/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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

	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		if(m == n)
			return head;
		else
		{
			ListNode* p = head;
			ListNode* prev_h = NULL;
			ListNode* h = NULL;
			ListNode* prev = NULL;
			for(int i = 1; i <= n; i++)
			{
				ListNode* next_p = p->next;
				if(i == m)
				{
					h = p;
					prev_h = prev;
					prev = p;
					p = next_p;
				}
				else if(i > m && i < n)
				{
					p->next = prev;	
					prev = p;
					p = next_p;
				}
				else if(i == n)
				{
					ListNode* t = p;
					ListNode* next_t = p->next;
					t->next = prev;
					if(prev_h == NULL)
						head = t;
					else
						prev_h->next = t;
					h->next = next_t;
				}
				else
				{
					prev = p;
					p = next_p;
				}
			}		
			return head;	
		}		
	}

};

/*
  从m到n, 依次改变前后两个元素的顺序，最终改变首尾顺序，时间复杂度为O(n), 空间复杂度为O(1).
*/
