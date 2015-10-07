/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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

	int sum;

  int sumNumbers(TreeNode* root) 
	{
		sum = 0;
		get_sum(root, 0);
		return sum;		
  }

	void get_sum(TreeNode* root, int num)
	{
		if(root != NULL)
		{
			if(root->left == NULL && root->right == NULL)
			{
				sum += num*10 + root->val;
			}
			else
			{
				num = num*10 + root->val;
				if(root->left != NULL)
				{
					get_sum(root->left, num);
				}			
				if(root->right != NULL)
				{
					get_sum(root->right, num);
				}
			}
		}
	}

};

/*
  模拟
*/
