/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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

	bool isSymmetric(TreeNode* root) 
	{
		// first reverse the tree
		TreeNode* new_root = reverseTree(root);

		// check reversed tree and this tree is the same or not
		return same(new_root, root);			
    	}

	TreeNode* reverseTree(TreeNode* root)
	{
		if(root == NULL)
			return NULL;
		TreeNode* r_child = reverseTree(root->left);
		TreeNode* l_child = reverseTree(root->right);

		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
		memset(p, 0, sizeof(p));
		p->val = root->val;
		p->left = l_child;
		p->right = r_child;

		return p;		
	}

	bool same(TreeNode* r1, TreeNode* r2)
	{
		if(r1 == NULL && r2 == NULL)
			return true;
		else if(!(r1 != NULL && r2 != NULL))
			return false;
		else
		{
			return (r1->val == r2->val) && same(r1->left, r2->left) && same(r1->right, r2->right);
		}
	}	
};

/*
  只做了递归的方法。还没有做迭代的方法。
  可以先得到翻转后的树，再比较两个树是否一样，如果一样，则该树为对称树，否则为不对称树。
*/
