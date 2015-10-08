/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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

	void flatten(TreeNode* root) 
	{
		if(root != NULL)
		{
			TreeNode* lp = root->left;
			TreeNode* rp = root->right;
			flatten(lp);
			flatten(rp);
			root->left = NULL;
			if(lp != NULL)
			{
				root->right = lp;
				TreeNode* p = lp;
				while(p->right != NULL)
					p = p->right;
				p->right = rp;
			}	
		}	
	}

};

/*
  按照先序遍历，分别flatten左右子树，然后将根结点指向左子树，左子树最后一个结点指向右子树。
*/
