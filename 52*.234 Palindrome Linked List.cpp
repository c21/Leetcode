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
  没有使用O(1)空间，而是使用O(n)空间。使用O(1)空间需要将链表后半部分翻转。
*/
