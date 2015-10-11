/*
Given preorder and inorder traversal of a tree, construct the binary tree.

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

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		if(preoder.size() == 0 || inorder.size() == 0)
			return NULL;
		else
			return gen_tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);	
	}

	TreeNode* gen_tree(vector<int>& preorder, vector<int>& inorder, int b1, int e1, int b2, int e2)
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = preorder[b1];
		root->left = NULL;
		root->right = NULL;
		if(b1 == e1)
			return root;
		else
		{
			for(int i = b2; i <= e2; i++)
			{
				if(inorder[i] == preorder[b1])
				{
					if(i != b2)
						root->left = gen_tree(preorder, inorder, b1+1, b1+i-b2, b2, i-1);
					if(i != e2)
						root->right = gen_tree(preorder, inorder, e1-e2+i+1, e1, i+1, e2);			
					return root;
				}
			}	
		}		
			
	}		

};

/*
  模拟
*/
