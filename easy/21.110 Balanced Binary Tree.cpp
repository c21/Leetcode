/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

	bool isBalanced(TreeNode* root) 
	{
		if(root == NULL)
			return true;
		else
		{
			int h1 = height(root->left);
			int h2 = height(root->right);

			if(abs(h1-h2) <= 1 && isBalanced(root->left) && isBalanced(root->right))
				return true;
			else
				return false;	
		}		
    	}

	int height(TreeNode* root)
	{
		if(root == NULL)
			return 0;
		else 
			return max(height(root->left), height(root->right))+1;		
	}
};

/*
  模拟
*/
