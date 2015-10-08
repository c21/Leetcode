/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution 
{

	public:

  TreeNode* sortedListToBST(ListNode* head) 
	{
		if(head == NULL)
			return NULL;
		else
		{
			// get the mid element of linked list
			TreeNode* slow = head;
			TreeNode* fast = head->next;
			TreeNode* prev = NULL;
			while(slow != NULL && fast != NULL)
			{
				prev = slow;
				slow = slow->next;
				fast = fast->next;
				if(fast != NULL)
					fast = fast->next;	
			}

			// treat the mid element as the root of tree
			TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
			p->val = slow->val;
			p->left = NULL;
			p->right = NULL;
			if(prev != NULL)
			{
				prev->next = NULL;
				p->left = sortedListToBST(head);
				prev->next = slow;
			}
			if(slow->next != NULL)
			{
				p->right = sortedListToBST(slow->next);
			}
			
			return p;			
		}		
  }

};

/*
  快慢指针找到中间结点，再构造左右子树。
*/  
