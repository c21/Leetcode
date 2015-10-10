/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		if(inorder.size() == 0)
			return NULL;
		else
			return gen_tree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);	
	}

	TreeNode* gen_tree(vector<int>& inorder, vector<int>& postorder, int b1, int e1, int b2, int e2)
	{
		int r = postorder[e2];
		for(int i = b1; i <= e1; i++)
		{
			if(r == inorder[i])
			{
				TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
				root->val = r;
				root->left = NULL;
				root->right = NULL;
				if(i > b1)
					root->left = gen_tree(inorder, postorder, b1, i-1, b2, b2+(i-1-b1));
				if(i < e1)
					root->right = gen_tree(inorder, postorder, i+1, e1, b2+(i-b1), e2-1);	
				return root;
			}
		}	
	}	

};

/*
  模拟。
*/
