/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
                vector<int> array = vector<int>();

                ListNode* p = head;
                while(p != NULL)
                {
                        array.push_back(p->val);
                        p = p->next;
                }
        
                for(int i = 0; i < array.size()/2; i++)
                {
                        if(array[i] != array[array.size()-i-1])
                                return false;
                }
                return true;
    }
};

/*
    更新的方法如下：
    1.找到中点(用快慢指针方法)
    2.翻转前半部链表
    3.比较前后两半链表
*/

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        // corner case
        if(head == NULL || head->next == NULL)
        	return true;
        
        // find the midpoint of linked list
        int len = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != NULL && fast != NULL)
        {
        	slow = slow->next;
        	fast = fast->next;
        	len++;
        	if(fast != NULL)
        	{
        		fast = fast->next;
        		len++;
        	}
        }
        
        // reverse the linked list from head to slow
        ListNode* p = reverse(head, slow);
        if(len % 2 == 1)
        	p = p->next;
        while(p != NULL && slow != NULL)
        {
        	if(p->val != slow->val)
        		return false;
        	p = p->next;
        	slow = slow->next;
        }
        return true;
     }

	ListNode* reverse(ListNode* head, ListNode* end)
	{
		if(head == NULL || head->next == end)
			return head;
		ListNode* h = head;
		ListNode* prev = head;
		ListNode* p = head->next;
        while(p != end)
		{
			ListNode* next = p->next;
			p->next = h;
			prev->next = next;
			h = p;
			p = next;
		}
		return h;
	}
};
