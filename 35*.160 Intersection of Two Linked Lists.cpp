/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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

    	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		vector<ListNode*> a1 = vector<ListNode*>();
		vector<ListNode*> a2 = vector<ListNode*>();

		ListNode* p = headA;
		while(p != NULL)
		{
			a1.push_back(p);
			p = p->next;
		}		
		p = headB;
		while(p != NULL)
                {
                        a2.push_back(p);
                        p = p->next;
                }
		
		if(a1.size() == 0 || a2.size() == 0 || a1[a1.size()-1] != a2[a2.size()-1])
			return NULL;

		int i = a1.size()-1;
		int j = a2.size()-1;
		for(; i >= 0 && j >= 0; )
		{
			if(a1[i] != a2[j])
				return a1[i]->next;
			i--;
			j--;	
		}
		if(i >= 0)
			return a1[i]->next;
		else if(j >= 0)
			return a2[j]->next;
		else 
			return headA;		
    	}

};

/*
  想到的方法是时间复杂度和空间复杂度都是O(n).
  记录两个链表的所有结点，由于两个链表相交了以后就不会分开，所以可以从尾向前遍历两个链表，
  直到找到不相等的结点位置为止，注意链表头的边界情况。
  
  时间复杂度O(n), 空间复杂度O(1)的方法没想到，在https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
  方法是利用两个链表相交前的所差结点的个数来进行计算，很巧妙。
*/
