/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution 
{
	public:

	ListNode* deleteDuplicates(ListNode* head) 
	{
	
		ListNode* p1 = head;
		while(p1 != NULL)
		{
			ListNode* p2 = p1->next;
			while(p2 != NULL && p2->val == p1->val)
				p2 = p2->next;
			p1->next = p2;
			p1 = p1->next;	
				
		}		
		return head;					
	}

};

/*
  模拟
*/
