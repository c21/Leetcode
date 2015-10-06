/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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

    	ListNode *detectCycle(ListNode *head) 
	{
/*
		map<ListNode*, int> my_map = map<ListNode*, int>();
		ListNode* p = head;
		while(p != NULL)
		{
			if(my_map.find(p) != my_map.end())
				return p;
			else
				my_map[p] = 1;	
			p = p->next;
		}		
        
		return NULL;
*/
		
    		ListNode* slow = head;
		ListNode* fast = head;

		while(slow != NULL && fast != NULL)
		{
			slow = slow->next;
			if(fast->next == NULL)
				return NULL;
			fast = fast->next->next;
			if(fast == slow)
				break;
		}

		if(fast == NULL || slow == NULL)
			return NULL;

		slow = head;
		while(fast != slow)
		{
			slow = slow->next;
			fast = fast->next;
		}	
		return fast;
	}

};

/*
  没有想出来，看了http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
  发现使用快慢指针，两个指针相遇以后有明确的关系，可以利用。
*/
