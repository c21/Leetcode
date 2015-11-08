/*
Given a linked list, determine if it has a cycle in it.

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

/*
class Solution 
{
	public:
    	bool hasCycle(ListNode *head) 
	{
        	unordered_map<ListNode*, int> my_map = unordered_map<ListNode*, int>();

		ListNode* p = head;
		while(p != NULL)
		{
			if(my_map.count(p) == 0)
				my_map[p] = 1;
			else
				return true;
			p = p->next;
		}		
		return false;
    	}
};
*/

class Solution 
{
	public:
    	bool hasCycle(ListNode *head) 
	{
		ListNode* p = head;
		while(p != NULL)
		{
			if(p->next == p)
				return true;
			ListNode* q = p->next;
			p->next = p;
			p = q;
		}
		return false;
	}
}

/*
  想到的方法是：破坏链表结构，将遍历过的结点都指向自己，如果遇到一个结点指向自己，
  它如果不是遍历过的结点，就是自己本身形成环，这两种情况下该链表都有环。
  看到可以用快慢指针做，如下。如果快慢指针指向同一个地方，就有环。
*/

class Solution 
{
    public:
    bool hasCycle(ListNode *head) 
    {
    	if(head == NULL)
    		return false;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while(slow != NULL && fast != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next;
    		if(fast != NULL)
    			fast = fast->next;
    		if(slow == fast && slow != NULL)
    			return true;
    	}
    	return false;
    }
};
