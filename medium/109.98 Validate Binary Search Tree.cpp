/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

	bool isValidBST(TreeNode* root) 
	{
		return check(root, 0, 0, 0, 0);	
	}

	bool check(TreeNode* root, int min_v, int max_v, int min_flag, int max_flag)
	{
		if(root == NULL)
			return true;
		else 
		{
			if( (min_flag && root->val <= min_v) || (max_flag && root->val >= max_v))
				return false;
			bool r1, r2;
			if(max_flag == 0)
				r1 = check(root->left, min_v, root->val, min_flag, 1);
			else
				r1 = check(root->left, min_v, min(root->val, max_v), min_flag, 1);
			if(min_flag == 0)
        r2 = check(root->right, root->val, max_v, 1, max_flag);
      else
        r2 = check(root->right, max(min_v, root->val), max_v, 1, max_flag);	
			return r1 && r2;
		}	
	}	

};

/*
  模拟。
*/
