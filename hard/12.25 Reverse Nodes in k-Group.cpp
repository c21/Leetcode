/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if(head == NULL || k == 0 || k == 1)
			return head;
	
		int len = 0;
		ListNode* p = head;
		while(p != NULL)
		{
			len++;
			p = p->next;
		}	
		if(len < k)
			return head;
		ListNode* h = NULL;
		ListNode* t = NULL;
		ListNode* new_head = NULL;
		int c1 = 1;
		int c2 = 1;
		int stop_num = (len / k)*k+1;
		p = head;
		ListNode* pre_t = NULL;
		while(c2 <= stop_num)
		{
		    ListNode* next = NULL;
		    if(p != NULL)
			    next = p->next;
			if(c1 <= k)
			{
				if(t == NULL)
					t = p;
				if(h == NULL)
				{
					h = p;	
				}	
				else
				{
					t->next = p->next;
					p->next = h;
					h = p;
					if(pre_t != NULL)
						pre_t->next = p;
				}	
				c1++;
				c2++;
			}	
			else if(c1 == k+1)
			{
				if(new_head == NULL)
					new_head = h;
				pre_t = t;
				pre_t->next = p;
				h = p;
				t = p;
				c1 = 2;	
				c2++;
			}
			p = next;
		}	
		return new_head;			
	}
};

/*
  先扫描一遍链表记录链表长度，得到翻转的停止位置为len/k*k+1.
  然后再扫描一遍，边扫描边记录序号，注意记录该翻转组的头和尾，以及上个翻转组的尾。
*/
