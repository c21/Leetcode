/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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

	int countNodes(TreeNode* root) 
	{
		if(root == NULL)
			return 0;
		else if(root->left == NULL)
			return 1;
		else if(root->right == NULL)
			return 2;
		else
		{
			// get the height
			int h = 0;
			TreeNode* p = root;
			while(p != NULL)
			{
				h++;
				p = p->left;
			}
		
			int h2 = 1;
			p = root->right;
			while(p != NULL)
			{
				h2++;
				p = p->left;
			}	
			if(h == h2)
				return 	pow(2, h-1) + countNodes(root->right);
			else
				return pow(2, h-2) + countNodes(root->left);
		}	
	}

};

/*
  可以用折半搜索的方法，比较左子树最左结点和右子数最左结点的深度。
  如果深度一样，代表左子树是满的，可以只计算右子树。
  如果深度不一样，代表右子树是矮了一层的满的，可以只计算左子树。
*/
