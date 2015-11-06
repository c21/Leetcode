/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

	void reorderList(ListNode* head) 
	{	
		if(head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		vector<ListNode*> v = vector<ListNode*>();
		ListNode* p = head;
		while(p != NULL)
		{
			v.push_back(p);
			p = p->next;
		}
		for(int i = 0; i <= v.size()/2-1; i++)
		{
			if(v[i]->next != v[v.size()-1-i])
			{
				v[i]->next = v[v.size()-1-i];
				v[v.size()-1-i]->next = v[i+1];
				v[v.size()-1-i-1]->next = NULL;	
			}
		}		
	}

};

/*
  空间复杂度O(1)的方法可以是找到后半段链表，翻转后半段链表，合并前半段和后半段链表。
  如下所示。
*/


class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
    	if(head == NULL || head->next == NULL || head->next->next == NULL)
    		return;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while(slow != NULL && fast != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next;
    		if(fast != NULL)
    			fast = fast->next;
    	}
    	
    	// rotate the second part of list
    	ListNode* t = slow;
    	ListNode* h2 = slow;
    	ListNode* p = slow->next;
    	while(p != NULL)
    	{
    		ListNode* next = p->next;
    		t->next = p->next;
            p->next = h2;
    		h2 = p;
    		p = next;
    	}
    	
    	ListNode* x1 = head;
    	ListNode* x2 = h2;
    	ListNode* h = NULL;
    	t = NULL;
    	while(x1 != NULL && x2 != NULL)
    	{
    		ListNode* next1 = x1->next;
    		ListNode* next2 = x2->next;
    		if(h == NULL)
    		{
    			h = x1;
                h->next = x2;
                t = x2;			
    		}
    		else
    		{
    			t->next = x1;
    			x1->next = x2;
    			t = x2;
    		}
    		x1 = next1;
    		x2 = next2;
    	}
    	
    	if(x1 != NULL)
    	{
    		t->next = x1;
    		t = x1;
    	}
    	t->next = NULL;
    }
};
