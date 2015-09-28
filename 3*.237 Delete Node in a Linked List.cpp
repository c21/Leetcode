/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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

    	void deleteNode(ListNode* node) 
	{
		// change the next node to itself, then delete the next node
		node->val = node->next->val;
		node->next = node->next->next;			
    	}

};

/*
这道题挺好。
一开始看到参数只有一个结点，只想着如何通过找到它的上一个结点来删除它，但是不行。
没做出来，后来看了别人的方法才知道，只需要将下一个结点的值赋给这个结点，删除下一个结点就可以了。
而删除下一个结点是很容易的。

应该多从题目条件里找方法，比如不能处理末尾的结点。
*/
