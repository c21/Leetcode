/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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

	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if(lists.size() == 0)
			return NULL;
		else if(lists.size() == 1)
			return lists[0];
		else
		{
			vector<ListNode*> new_list = vector<ListNode*>();
			for(int i = 0; i+1 < lists.size(); i = i + 2)
			{
				ListNode* h = merge(lists[i], lists[i+1]);
				new_list.push_back(h);	
			}
			if(lists.size() % 2 == 1)
			{
				new_list.push_back(lists[lists.size()-1]);	
			}
			return mergeKLists(new_list);	
		}	
	}

	ListNode* merge(ListNode* h1, ListNode* h2)
	{
		ListNode* p1 = h1;
		ListNode* p2 = h2;
		
		ListNode* h = NULL;
		ListNode* t = NULL;
		while(p1 != NULL && p2 != NULL)
		{
			ListNode* x;
			if(p1->val <= p2->val)
			{
				x = p1;
				p1 = p1->next;
			}
			else
			{
				x = p2;
        p2 = p2->next;
			}
			if(h == NULL)
      {
           	h = x;
            t = x;
     	}
    	else
     	{
             	t->next = x;
            	t = x;
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
		if(t == NULL)
			return NULL;
		else
		{
			t->next = NULL;
			return h;
		}
	}

};

/*
  两两合并，假设初始每个链表长度为n, 时间复杂度为O(kn*log(k)).
*/
