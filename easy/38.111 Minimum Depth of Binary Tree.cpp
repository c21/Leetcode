/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.  
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

    	int minDepth(TreeNode* root) 
	{
		if(root == NULL)
			return 0;
		else if(root->left == NULL && root->right == NULL)
			return 1;
		else if(root->left == NULL && root->right != NULL)
			return minDepth(root->right)+1;
		else if(root->left != NULL && root->right == NULL)
			return minDepth(root->left)+1;
		else		
			return min(minDepth(root->left),minDepth(root->right))+1;
    	}

};

/*
  模拟，此题要注意树的最小深度，必须为遍历到叶子结点，不能中途停止。
*/
