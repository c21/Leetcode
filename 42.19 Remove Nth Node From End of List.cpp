/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.  
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

    	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{

		// if the list only has one element, or no element, return null
		if(head == NULL || head->next == NULL)
			return NULL;

		// if the list has more than one element
		vector<ListNode*> record = vector<ListNode*>();

		// record all nodes
		ListNode* p = head;
		while(p != NULL)
		{
			record.push_back(p);
			p = p->next;
		}	

		// if delete the head
		if(n == record.size())
		{
			return record[0]->next;
		}
		// if delete the tail
		else if(n == 1)
		{
			record[record.size()-2]->next = NULL;
			return record[0];		
		}
		// if delete element which is neither head nor tail
		else
		{
			record[record.size()-n-1]->next = record[record.size()-n+1];
			return record[0];	
		}	
			
    	}

};

/*
  扫描一遍把所有结点都保存下来再处理。
*/
