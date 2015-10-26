/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

	int count = 0;

	void recoverTree(TreeNode* root) 
	{
		if(root != NULL)
		{
			vector<int> record = vector<int>();
			inorder(root, record);
	
			sort(record.begin(), record.end());		
	
			count = 0;		
			change(root, record);
		}
	}

	void inorder(TreeNode* root, vector<int>& record)
	{
		if(root != NULL)
		{
			if(root->left != NULL)
				inorder(root->left, record);
			record.push_back(root->val);
			if(root->right != NULL)
        inorder(root->right, record);
		}
	}

	void change(TreeNode* root, vector<int>& record)
	{
		if(root != NULL)
		{
			if(root->left != NULL)
        change(root->left, record);
      root->val = record[count];
			count++;
      if(root->right != NULL)
        change(root->right, record);
		}
	}
};

/*
  这里是O(N)空间复杂度的做法，O(1)的方法没有想出来，以后再做。
*/
