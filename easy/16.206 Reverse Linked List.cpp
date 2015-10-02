/*
Reverse a singly linked list.
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

	ListNode* reverseList(ListNode* head) 
	{
		vector<int> array = vector<int>();
		ListNode* p = head;
		while(p != NULL)
		{
			array.push_back(p->val);
			p = p->next;
		}	
		p = head;
		int i = 1;
		while(p != NULL)
		{
			p->val = array[array.size()-i];
			p = p->next; 
			i++;
		}
		return head;	
			
        }

};

/*
  要知道链表永远只是为了存储数据的一种表示方法。
  翻转链表，不如直接翻转链表里面存的数，如果时间空间允许的话。
*/
